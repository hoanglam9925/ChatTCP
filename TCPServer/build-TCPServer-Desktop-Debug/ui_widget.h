/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *PortNumber;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QTextBrowser *txtMessage;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *cbbClientIP;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *sendMessage;
    QPushButton *btnSendMessage;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(327, 331);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 14, 298, 314));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        PortNumber = new QSpinBox(widget);
        PortNumber->setObjectName(QStringLiteral("PortNumber"));
        PortNumber->setMaximum(99999);

        horizontalLayout->addWidget(PortNumber);

        btnStart = new QPushButton(widget);
        btnStart->setObjectName(QStringLiteral("btnStart"));

        horizontalLayout->addWidget(btnStart);

        btnStop = new QPushButton(widget);
        btnStop->setObjectName(QStringLiteral("btnStop"));

        horizontalLayout->addWidget(btnStop);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        txtMessage = new QTextBrowser(widget);
        txtMessage->setObjectName(QStringLiteral("txtMessage"));

        gridLayout->addWidget(txtMessage, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        cbbClientIP = new QComboBox(widget);
        cbbClientIP->setObjectName(QStringLiteral("cbbClientIP"));

        horizontalLayout_2->addWidget(cbbClientIP);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sendMessage = new QLineEdit(widget);
        sendMessage->setObjectName(QStringLiteral("sendMessage"));

        horizontalLayout_3->addWidget(sendMessage);

        btnSendMessage = new QPushButton(widget);
        btnSendMessage->setObjectName(QStringLiteral("btnSendMessage"));

        horizontalLayout_3->addWidget(btnSendMessage);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "Port", nullptr));
        btnStart->setText(QApplication::translate("Widget", "Start", nullptr));
        btnStop->setText(QApplication::translate("Widget", "Stop", nullptr));
        label_2->setText(QApplication::translate("Widget", "Client IP", nullptr));
        btnSendMessage->setText(QApplication::translate("Widget", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
