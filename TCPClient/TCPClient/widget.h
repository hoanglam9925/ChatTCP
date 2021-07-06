#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void connectToServer();
    void receiveData();
    void disconnect();
    void sendDatatoServer();

private:
    void InitUi();
    void setFont(const QColor &c,int fontsize);
    Ui::Widget *ui;
    QTcpSocket *mSocket;
};

#endif // WIDGET_H
