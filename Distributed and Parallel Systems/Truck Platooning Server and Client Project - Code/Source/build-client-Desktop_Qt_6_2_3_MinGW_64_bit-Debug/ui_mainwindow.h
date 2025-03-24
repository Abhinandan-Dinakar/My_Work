/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QPushButton *btnConnect;
    QLineEdit *txtPortNumber;
    QLabel *label_11;
    QLineEdit *txtIpAddress;
    QLabel *label_10;
    QPushButton *btnDisconnect;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_25;
    QLineEdit *lineLeadSpeed;
    QLabel *label_16;
    QLineEdit *lineLeadDistance;
    QLabel *label_23;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QCheckBox *cbFollowerCommFailure;
    QLabel *label_12;
    QCheckBox *cbFollowerObstacle;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineDirection;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;
    QCheckBox *cbFollowerEngineSystem;
    QCheckBox *cbFollowerFuleSystem;
    QCheckBox *cbFollowerCoolingSystem;
    QCheckBox *cbFollowerBrakeSystem;
    QCheckBox *cbFollowerSteeringSystem;
    QCheckBox *cbFollowerElectricalSystem;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QLabel *label_26;
    QLineEdit *lineLeadSpeed_2;
    QLabel *label_3;
    QLineEdit *lineLeadDistance_2;
    QLabel *label_24;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QCheckBox *cbFollowerCommFailure_2;
    QLabel *label_13;
    QLineEdit *lineDirection_2;
    QLabel *label_14;
    QLabel *label_15;
    QCheckBox *cbFollowerObstacle_2;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QCheckBox *cbFollowerEngineSystem_2;
    QCheckBox *cbFollowerFuleSystem_2;
    QCheckBox *cbFollowerCoolingSystem_2;
    QCheckBox *cbFollowerBrakeSystem_2;
    QCheckBox *cbFollowerSteeringSystem_2;
    QCheckBox *cbFollowerElectricalSystem_2;
    QTextBrowser *txtConsole;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(497, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_8 = new QGridLayout(centralwidget);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        btnConnect = new QPushButton(groupBox_4);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        gridLayout_5->addWidget(btnConnect, 0, 4, 1, 1);

        txtPortNumber = new QLineEdit(groupBox_4);
        txtPortNumber->setObjectName(QString::fromUtf8("txtPortNumber"));

        gridLayout_5->addWidget(txtPortNumber, 0, 3, 1, 1);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 0, 2, 1, 1);

        txtIpAddress = new QLineEdit(groupBox_4);
        txtIpAddress->setObjectName(QString::fromUtf8("txtIpAddress"));

        gridLayout_5->addWidget(txtIpAddress, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 0, 0, 1, 1);

        btnDisconnect = new QPushButton(groupBox_4);
        btnDisconnect->setObjectName(QString::fromUtf8("btnDisconnect"));

        gridLayout_5->addWidget(btnDisconnect, 1, 4, 1, 1);


        gridLayout_8->addWidget(groupBox_4, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_3->addWidget(label_25, 0, 0, 1, 1);

        lineLeadSpeed = new QLineEdit(groupBox);
        lineLeadSpeed->setObjectName(QString::fromUtf8("lineLeadSpeed"));

        gridLayout_3->addWidget(lineLeadSpeed, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 0, 2, 1, 1);

        lineLeadDistance = new QLineEdit(groupBox);
        lineLeadDistance->setObjectName(QString::fromUtf8("lineLeadDistance"));

        gridLayout_3->addWidget(lineLeadDistance, 0, 3, 1, 1);

        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_3->addWidget(label_23, 0, 4, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbFollowerCommFailure = new QCheckBox(groupBox_2);
        cbFollowerCommFailure->setObjectName(QString::fromUtf8("cbFollowerCommFailure"));

        gridLayout->addWidget(cbFollowerCommFailure, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 0, 0, 1, 1);

        cbFollowerObstacle = new QCheckBox(groupBox_2);
        cbFollowerObstacle->setObjectName(QString::fromUtf8("cbFollowerObstacle"));

        gridLayout->addWidget(cbFollowerObstacle, 2, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineDirection = new QLineEdit(groupBox_2);
        lineDirection->setObjectName(QString::fromUtf8("lineDirection"));

        gridLayout->addWidget(lineDirection, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 3);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 2, 2, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 2, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        cbFollowerEngineSystem = new QCheckBox(groupBox_3);
        cbFollowerEngineSystem->setObjectName(QString::fromUtf8("cbFollowerEngineSystem"));

        gridLayout_2->addWidget(cbFollowerEngineSystem, 0, 1, 1, 1);

        cbFollowerFuleSystem = new QCheckBox(groupBox_3);
        cbFollowerFuleSystem->setObjectName(QString::fromUtf8("cbFollowerFuleSystem"));

        gridLayout_2->addWidget(cbFollowerFuleSystem, 1, 1, 1, 1);

        cbFollowerCoolingSystem = new QCheckBox(groupBox_3);
        cbFollowerCoolingSystem->setObjectName(QString::fromUtf8("cbFollowerCoolingSystem"));

        gridLayout_2->addWidget(cbFollowerCoolingSystem, 2, 1, 1, 1);

        cbFollowerBrakeSystem = new QCheckBox(groupBox_3);
        cbFollowerBrakeSystem->setObjectName(QString::fromUtf8("cbFollowerBrakeSystem"));

        gridLayout_2->addWidget(cbFollowerBrakeSystem, 0, 3, 1, 1);

        cbFollowerSteeringSystem = new QCheckBox(groupBox_3);
        cbFollowerSteeringSystem->setObjectName(QString::fromUtf8("cbFollowerSteeringSystem"));

        gridLayout_2->addWidget(cbFollowerSteeringSystem, 1, 3, 1, 1);

        cbFollowerElectricalSystem = new QCheckBox(groupBox_3);
        cbFollowerElectricalSystem->setObjectName(QString::fromUtf8("cbFollowerElectricalSystem"));

        gridLayout_2->addWidget(cbFollowerElectricalSystem, 2, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 1, 3, 1, 2);


        gridLayout_8->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_26 = new QLabel(groupBox_5);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_4->addWidget(label_26, 0, 0, 1, 1);

        lineLeadSpeed_2 = new QLineEdit(groupBox_5);
        lineLeadSpeed_2->setObjectName(QString::fromUtf8("lineLeadSpeed_2"));

        gridLayout_4->addWidget(lineLeadSpeed_2, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 2, 1, 1);

        lineLeadDistance_2 = new QLineEdit(groupBox_5);
        lineLeadDistance_2->setObjectName(QString::fromUtf8("lineLeadDistance_2"));

        gridLayout_4->addWidget(lineLeadDistance_2, 0, 3, 1, 1);

        label_24 = new QLabel(groupBox_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_4->addWidget(label_24, 0, 4, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        cbFollowerCommFailure_2 = new QCheckBox(groupBox_6);
        cbFollowerCommFailure_2->setObjectName(QString::fromUtf8("cbFollowerCommFailure_2"));

        gridLayout_6->addWidget(cbFollowerCommFailure_2, 1, 1, 1, 1);

        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_6->addWidget(label_13, 2, 0, 1, 1);

        lineDirection_2 = new QLineEdit(groupBox_6);
        lineDirection_2->setObjectName(QString::fromUtf8("lineDirection_2"));

        gridLayout_6->addWidget(lineDirection_2, 0, 1, 1, 1);

        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_6->addWidget(label_14, 0, 0, 1, 1);

        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 1, 0, 1, 1);

        cbFollowerObstacle_2 = new QCheckBox(groupBox_6);
        cbFollowerObstacle_2->setObjectName(QString::fromUtf8("cbFollowerObstacle_2"));

        gridLayout_6->addWidget(cbFollowerObstacle_2, 2, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_6, 1, 0, 1, 3);

        groupBox_7 = new QGroupBox(groupBox_5);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_7->addWidget(label_17, 2, 2, 1, 1);

        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_7->addWidget(label_18, 1, 2, 1, 1);

        label_19 = new QLabel(groupBox_7);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_7->addWidget(label_19, 0, 2, 1, 1);

        label_20 = new QLabel(groupBox_7);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_7->addWidget(label_20, 1, 0, 1, 1);

        label_21 = new QLabel(groupBox_7);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_7->addWidget(label_21, 2, 0, 1, 1);

        label_22 = new QLabel(groupBox_7);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_7->addWidget(label_22, 0, 0, 1, 1);

        cbFollowerEngineSystem_2 = new QCheckBox(groupBox_7);
        cbFollowerEngineSystem_2->setObjectName(QString::fromUtf8("cbFollowerEngineSystem_2"));

        gridLayout_7->addWidget(cbFollowerEngineSystem_2, 0, 1, 1, 1);

        cbFollowerFuleSystem_2 = new QCheckBox(groupBox_7);
        cbFollowerFuleSystem_2->setObjectName(QString::fromUtf8("cbFollowerFuleSystem_2"));

        gridLayout_7->addWidget(cbFollowerFuleSystem_2, 1, 1, 1, 1);

        cbFollowerCoolingSystem_2 = new QCheckBox(groupBox_7);
        cbFollowerCoolingSystem_2->setObjectName(QString::fromUtf8("cbFollowerCoolingSystem_2"));

        gridLayout_7->addWidget(cbFollowerCoolingSystem_2, 2, 1, 1, 1);

        cbFollowerBrakeSystem_2 = new QCheckBox(groupBox_7);
        cbFollowerBrakeSystem_2->setObjectName(QString::fromUtf8("cbFollowerBrakeSystem_2"));

        gridLayout_7->addWidget(cbFollowerBrakeSystem_2, 0, 3, 1, 1);

        cbFollowerSteeringSystem_2 = new QCheckBox(groupBox_7);
        cbFollowerSteeringSystem_2->setObjectName(QString::fromUtf8("cbFollowerSteeringSystem_2"));

        gridLayout_7->addWidget(cbFollowerSteeringSystem_2, 1, 3, 1, 1);

        cbFollowerElectricalSystem_2 = new QCheckBox(groupBox_7);
        cbFollowerElectricalSystem_2->setObjectName(QString::fromUtf8("cbFollowerElectricalSystem_2"));

        gridLayout_7->addWidget(cbFollowerElectricalSystem_2, 2, 3, 1, 1);


        gridLayout_4->addWidget(groupBox_7, 1, 3, 1, 2);


        gridLayout_8->addWidget(groupBox_5, 2, 0, 1, 1);

        txtConsole = new QTextBrowser(centralwidget);
        txtConsole->setObjectName(QString::fromUtf8("txtConsole"));

        gridLayout_8->addWidget(txtConsole, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 497, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Follower Truck", nullptr));
        groupBox_4->setTitle(QString());
        btnConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "IP", nullptr));
        btnDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Follower Truck 1", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Distance:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "meters", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Follower Truck Scenarios", nullptr));
        cbFollowerCommFailure->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Direction", nullptr));
        cbFollowerObstacle->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Comm failure", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Obstacle", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "FollowerTruck Health Simulator", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Electrical System", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Steering System", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Brake System", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Fuel System", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Cooling System", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Engine System", nullptr));
        cbFollowerEngineSystem->setText(QString());
        cbFollowerFuleSystem->setText(QString());
        cbFollowerCoolingSystem->setText(QString());
        cbFollowerBrakeSystem->setText(QString());
        cbFollowerSteeringSystem->setText(QString());
        cbFollowerElectricalSystem->setText(QString());
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Follower Truck 2", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Distance:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "meters", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Follower Truck Scenarios", nullptr));
        cbFollowerCommFailure_2->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Obstacle", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Direction", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Comm failure", nullptr));
        cbFollowerObstacle_2->setText(QString());
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "FollowerTruck Health Simulator", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Electrical System", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Steering System", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Brake System", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Fuel System", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Cooling System", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Engine System", nullptr));
        cbFollowerEngineSystem_2->setText(QString());
        cbFollowerFuleSystem_2->setText(QString());
        cbFollowerCoolingSystem_2->setText(QString());
        cbFollowerBrakeSystem_2->setText(QString());
        cbFollowerSteeringSystem_2->setText(QString());
        cbFollowerElectricalSystem_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
