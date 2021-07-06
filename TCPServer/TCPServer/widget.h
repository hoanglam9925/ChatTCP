#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QHash>
class QBuffer;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void acceptConnection();
    void readFromClient();
    void displayServerError(QAbstractSocket::SocketError err);
    void disconnectServer();
    void sendDatatoClient();
    void removeClient();
    void startServer();
private:
    Ui::Widget *ui;

    bool listen = false;
    void initUi();
    void setFont(const QColor &c,int fontsize);


    QTcpServer *server;

    QList<QTcpSocket*> connections;
    QHash<QTcpSocket*, QBuffer*> buffers;
};

#endif // WIDGET_H
