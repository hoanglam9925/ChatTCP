#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QMetaEnum>
#include <QBuffer>
#include <QTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    server = new QTcpServer;
    connect(server, &QTcpServer::newConnection, this, &Widget::acceptConnection);
    connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(startServer()));
    connect(ui->btnStop, SIGNAL(clicked()), this, SLOT(disconnectServer()));
    connect(ui->btnSendMessage, SIGNAL(clicked()), this, SLOT(sendDatatoClient()));
    //connect(ui->sendMessage, SIGNAL(textChanged()), this, SLOT(sendDatatoClient()));
    initUi();
}

Widget::~Widget()
{
    server->close();
    server->deleteLater();
    delete ui;
}

void Widget::initUi()
{
    ui->btnSendMessage->setEnabled(false);
    ui->btnStop->setEnabled(false);
    ui->btnStart->setEnabled(true);
    ui->PortNumber->setValue(10000);
}
void Widget::setFont(const QColor &c,int fontsize)
{
    ui->txtMessage->setTextColor(c);
    ui->txtMessage->setFont(QFont("Times New Roman", fontsize));
}
void Widget::acceptConnection()
{
    if(listen) //Server dang hoat dong
    {
        //nhan thong tin cua Client dang doi vao bien
        QTcpSocket *newConnection = server->nextPendingConnection();

        /**************Luu thong tin vao List va Hash***************/
        //dua thong tin socket vao QList cac Client
        connections.append(newConnection);
        //Tao buffer
        QBuffer *buffer = new QBuffer(this);
        buffer->open(QIODevice::ReadWrite);
        //Dua vao Hash <TcpSocket, Buffer>
        buffers.insert(newConnection, buffer);
        /*******************************************/

        /*************Dang Ky su kien cho Client moi*****************/
        connect(newConnection, &QTcpSocket::readyRead, this, &Widget::readFromClient);
        connect(newConnection, &QTcpSocket::disconnected, this, &Widget::removeClient);
        /*******************************************/
        //Them IP vao CBB
        ui->cbbClientIP->addItem(QString(newConnection->peerAddress().toString()));
        //Dang ky su kien error cua Client
        connect(newConnection, static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error),
                        this, &Widget::displayServerError);
        setFont(Qt::blue, 16);
        ui->txtMessage->append("New connection accepted \n");
        ui->txtMessage->append(QString(newConnection->peerAddress().toString() + "\n"));
    }
}
void Widget::readFromClient()
{
    //Xac dinh ket noi nao co thong diep den
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
    //Lay bo dem du lieu tuong ung voi socket (tu bang hash buffers)
    QBuffer *buffer = buffers.value(socket);
    //ghi toan bo du lieu cua socket nay vao bo dem (buffer) da xac dinh o tren
    qint64 bytes = buffer->write(socket->readAll());
    //dich chuyen ve dau bo dem bang ham seek
    buffer->seek(buffer->pos() - bytes);
    auto test = buffer->readAll();
    setFont(Qt::gray, 6);
    ui->txtMessage->append("From " + socket->peerAddress().toString() +":  " + QTime::currentTime().toString());
    setFont(Qt::black, 16);
    ui->txtMessage->append(test);
    //    foreach (QTcpSocket* connection, connections)
    //    {
    //            connection->write(test); //Gui bang cach ghi ra socket
    //    }
}
void Widget::displayServerError(QAbstractSocket::SocketError err)
{
    if (err == QTcpSocket::RemoteHostClosedError)
    {
        setFont(Qt::red, 16);
        ui->txtMessage->append(QString("Connection closed.\n"));
        return;
    }

    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    setFont(Qt::black, 16);
    ui->txtMessage->append(QString("ERROR: ") + metaEnum.valueToKey(err) + "\n");
}
void Widget::disconnectServer()
{
    listen = false;
    server->close();
    ui->btnStop->setEnabled(false);
    ui->btnStart->setEnabled(true);
    ui->btnSendMessage->setEnabled(false);


}
void Widget::sendDatatoClient()
{
    /***************Check dieu kien gui data**************/
    if(ui->cbbClientIP->currentText().isEmpty())
    {
        return;
    }
    if(ui->sendMessage->text().isEmpty() )
    {
        return;
    }

    /*****************************************************/
    //Khai bao mot Socket tam thoi de lay tu List Client
    QTcpSocket* tempConnect = nullptr;
    //Quet cac Socket trong List
    foreach (QTcpSocket* connection, connections)
    {
        if(connection->peerAddress().toString() == ui->cbbClientIP->currentText())
        {
            tempConnect = connection;
            break;
        }
    }
    //Gui data xuong Client tuong ung
    tempConnect->write(ui->sendMessage->text().toUtf8());
    setFont(Qt::gray, 6);
    ui->txtMessage->append("From Server:" + QTime::currentTime().toString());
    setFont(Qt::black, 16);
    ui->txtMessage->append(ui->sendMessage->text().toUtf8());

    //Clear data trong o go du lieu
    ui->sendMessage->clear();
}
void Widget::removeClient()
{
    //Nhan biet tu Client nao va take trong buffer du lieu Client tuong ung
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
    QBuffer *buffer = buffers.take(socket);
    QString addressDisconnect = socket->peerAddress().toString();
    int tmpIndex = ui->cbbClientIP->findText(addressDisconnect);
    ui->cbbClientIP->removeItem(tmpIndex);
    //Xoa du lieu cua Client
    buffer->close();
    buffer->deleteLater();
    connections.removeAll(socket);
    socket->deleteLater();
}
void Widget::startServer()
{
    listen = true;
    /******************Mo Server (ham tra ve bool de check)********************/
    while (!server->isListening() && !server->listen(QHostAddress::Any,quint16(ui->PortNumber->value())))
    {
        auto ret = QMessageBox::critical(
                     this, tr("Server"),
                     tr("cannot start the server: %1.").arg(server->errorString()),
                     QMessageBox::Retry | QMessageBox::Cancel);
        if (ret == QMessageBox::Cancel)
        {
            setFont(Qt::red,16);
            ui->txtMessage->append("ERROR: " + server->errorString()  + "\n");
            return;
        }
    }
    /*************************************************************************/
    ui->btnStart->setEnabled(false);
    ui->btnSendMessage->setEnabled(true);
    ui->btnStop->setEnabled(true);
    setFont(Qt::blue, 16);
    ui->txtMessage->append(QString("Listening on port %1...\n").arg(server->serverPort()));
}
