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
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *txtServerIP;
    QLabel *label_3;
    QLineEdit *txtName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *portNumber;
    QPushButton *btnConnect;
    QTextBrowser *txtMessageHistory;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtMessageSend;
    QPushButton *btnSend;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(391, 300);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 371, 281));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        txtServerIP = new QLineEdit(layoutWidget);
        txtServerIP->setObjectName(QStringLiteral("txtServerIP"));

        horizontalLayout_3->addWidget(txtServerIP);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        txtName = new QLineEdit(layoutWidget);
        txtName->setObjectName(QStringLiteral("txtName"));

        horizontalLayout_3->addWidget(txtName);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        portNumber = new QSpinBox(layoutWidget);
        portNumber->setObjectName(QStringLiteral("portNumber"));
        portNumber->setMaximum(99999);

        horizontalLayout_2->addWidget(portNumber);

        btnConnect = new QPushButton(layoutWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));

        horizontalLayout_2->addWidget(btnConnect);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        txtMessageHistory = new QTextBrowser(layoutWidget);
        txtMessageHistory->setObjectName(QStringLiteral("txtMessageHistory"));

        gridLayout->addWidget(txtMessageHistory, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        txtMessageSend = new QLineEdit(layoutWidget);
        txtMessageSend->setObjectName(QStringLiteral("txtMessageSend"));

        horizontalLayout->addWidget(txtMessageSend);

        btnSend = new QPushButton(layoutWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));

        horizontalLayout->addWidget(btnSend);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "Server IP:", nullptr));
        label_3->setText(QApplication::translate("Widget", "Name:", nullptr));
        label_2->setText(QApplication::translate("Widget", "Port:", nullptr));
        btnConnect->setText(QApplication::translate("Widget", "Connect", nullptr));
        btnSend->setText(QApplication::translate("Widget", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
