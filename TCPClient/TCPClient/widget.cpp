#include "widget.h"
#include "ui_widget.h"
#include <QtWidgets/QMessageBox>
#include <QTime>
#include <QTime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    InitUi();
    mSocket=new QTcpSocket();
    connect(mSocket, &QTcpSocket::readyRead, this, &Widget::receiveData);
    connect(mSocket, &QTcpSocket::disconnected, this, &Widget::disconnect);
    connect(ui->btnConnect, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(ui->btnSend, SIGNAL(clicked()), this, SLOT(sendDatatoServer()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::InitUi()
{
    ui->btnSend->setEnabled(false);
    ui->btnConnect->setEnabled(true);
    ui->btnConnect->setText("Connect");
    ui->txtName->setText("Test Client");
    ui->txtServerIP->setText("127.0.0.1");
    ui->portNumber->setValue(10000);
}
void Widget::setFont(const QColor &c,int fontsize)
{
    ui->txtMessageHistory->setTextColor(c);
    ui->txtMessageHistory->setFont(QFont("Times New Roman", fontsize));
}
void Widget::connectToServer()
{
    if(ui->btnConnect->text() == "Connect")
    {

        QString IP = ui->txtServerIP->text();
        quint16 port = quint16 (ui->portNumber->value());
        mSocket->connectToHost(IP, port);
        if (!mSocket->waitForConnected())
        {
            QMessageBox::critical(this, "Connection error!", "Connection timeout!");
            return;
        }
        QMessageBox::information(this, "Connection Complete", "Connected to Server!");
        ui->btnConnect->setText("Disconnect");
        ui->btnSend->setEnabled(true);
        setFont(Qt::blue, 16);
        ui->txtMessageHistory->append("Connected to Server");
    }
    else
    {
         mSocket->disconnectFromHost();
    }

}
void Widget::receiveData()
{
    QByteArray dataReceived;
    dataReceived = mSocket->readAll();
    if(!dataReceived.isEmpty())
    {
        QString temp = QString(dataReceived);
        setFont(Qt::gray,10);
        ui->txtMessageHistory->append("From Server:  "+QTime::currentTime().toString());
        setFont(Qt::black,16);
        ui->txtMessageHistory->append(temp);
    }
}
void Widget::disconnect()
{

    ui->btnConnect->setText("Connect");
    ui->btnSend->setEnabled(false);
    setFont(Qt::red, 10);
    ui->txtMessageHistory->append("Disconnected From Server");
    QMessageBox::information(this, "Disconnect from Server", "Disconnected From Server!");
}
void Widget::sendDatatoServer()
{
    if(ui->txtMessageSend->text().isEmpty())
        return;
    mSocket->write(ui->txtMessageSend->text().toUtf8());
    setFont(Qt::gray, 10);
    ui->txtMessageHistory->append("From Server:  "+QTime::currentTime().toString());
    setFont(Qt::black, 16);
    ui->txtMessageHistory->append(">>>" + ui->txtName->text() + ": " + ui->txtMessageSend->text());
    ui->txtMessageSend->clear();
}











