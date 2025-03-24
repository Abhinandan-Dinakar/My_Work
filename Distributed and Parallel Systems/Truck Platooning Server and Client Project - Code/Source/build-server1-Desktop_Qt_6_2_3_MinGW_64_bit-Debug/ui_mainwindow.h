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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QCheckBox *checkF1EngineSystem;
    QCheckBox *checkF1Obstacle;
    QLabel *label_18;
    QLabel *label_17;
    QCheckBox *checkF1CoolingSystem;
    QCheckBox *checkF1BrakeSystem;
    QCheckBox *checkF1ElectricaSystem;
    QLabel *label_13;
    QCheckBox *checkF1FuelSystem;
    QLabel *label_23;
    QLineEdit *lineF1Speed;
    QLabel *label_19;
    QLabel *label_15;
    QCheckBox *checkF1CommFailure;
    QLabel *label_20;
    QLabel *label_22;
    QLabel *label_14;
    QLineEdit *LineF1Direction;
    QLabel *label_21;
    QCheckBox *checkF1SteeringSystem;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QCheckBox *checkF2Obstacle;
    QLabel *label_30;
    QCheckBox *checkF2EngineSystem;
    QLabel *label_26;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_25;
    QLineEdit *LineF2Direction;
    QLabel *label_27;
    QCheckBox *checkF2SteeringSystem;
    QCheckBox *checkF2ElectricaSystem;
    QLineEdit *lineF2Speed;
    QLabel *label_35;
    QCheckBox *checkF2BrakeSystem;
    QLabel *label_32;
    QCheckBox *checkF2CommFailure;
    QLabel *label_31;
    QCheckBox *checkF2FuelSystem;
    QCheckBox *checkF2CoolingSystem;
    QLabel *label_28;
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QCheckBox *cbLeadHilAssistance;
    QLabel *label_8;
    QLabel *label_9;
    QCheckBox *cbLeadObstacle;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_24;
    QCheckBox *cbLeadCommFailure;
    QLabel *label_12;
    QLineEdit *lineLeadBrake;
    QLineEdit *lineLeadDirection;
    QLineEdit *lineLeadSpeed;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QCheckBox *cbLeadEngineSystem;
    QCheckBox *cbLeadFuelSystem;
    QCheckBox *cbLeadCoolingSystem;
    QCheckBox *cbLeadBrakeSystem;
    QCheckBox *cbLeadSteeringSystem;
    QCheckBox *cbLeadElectricalSystem;
    QLineEdit *txtPort;
    QToolButton *btnStartServer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 385);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        checkF1EngineSystem = new QCheckBox(groupBox_3);
        checkF1EngineSystem->setObjectName(QString::fromUtf8("checkF1EngineSystem"));

        gridLayout_3->addWidget(checkF1EngineSystem, 4, 2, 1, 1);

        checkF1Obstacle = new QCheckBox(groupBox_3);
        checkF1Obstacle->setObjectName(QString::fromUtf8("checkF1Obstacle"));

        gridLayout_3->addWidget(checkF1Obstacle, 3, 2, 1, 1);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 5, 0, 1, 1);

        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 4, 0, 1, 2);

        checkF1CoolingSystem = new QCheckBox(groupBox_3);
        checkF1CoolingSystem->setObjectName(QString::fromUtf8("checkF1CoolingSystem"));

        gridLayout_3->addWidget(checkF1CoolingSystem, 6, 2, 1, 1);

        checkF1BrakeSystem = new QCheckBox(groupBox_3);
        checkF1BrakeSystem->setObjectName(QString::fromUtf8("checkF1BrakeSystem"));

        gridLayout_3->addWidget(checkF1BrakeSystem, 7, 2, 1, 1);

        checkF1ElectricaSystem = new QCheckBox(groupBox_3);
        checkF1ElectricaSystem->setObjectName(QString::fromUtf8("checkF1ElectricaSystem"));

        gridLayout_3->addWidget(checkF1ElectricaSystem, 9, 2, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 0, 0, 1, 1);

        checkF1FuelSystem = new QCheckBox(groupBox_3);
        checkF1FuelSystem->setObjectName(QString::fromUtf8("checkF1FuelSystem"));

        gridLayout_3->addWidget(checkF1FuelSystem, 5, 2, 1, 1);

        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_3->addWidget(label_23, 2, 0, 1, 2);

        lineF1Speed = new QLineEdit(groupBox_3);
        lineF1Speed->setObjectName(QString::fromUtf8("lineF1Speed"));

        gridLayout_3->addWidget(lineF1Speed, 0, 1, 1, 2);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_3->addWidget(label_19, 6, 0, 1, 2);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 1, 0, 1, 1);

        checkF1CommFailure = new QCheckBox(groupBox_3);
        checkF1CommFailure->setObjectName(QString::fromUtf8("checkF1CommFailure"));

        gridLayout_3->addWidget(checkF1CommFailure, 2, 2, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_3->addWidget(label_20, 7, 0, 1, 2);

        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_3->addWidget(label_22, 8, 0, 1, 2);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 3, 0, 1, 1);

        LineF1Direction = new QLineEdit(groupBox_3);
        LineF1Direction->setObjectName(QString::fromUtf8("LineF1Direction"));

        gridLayout_3->addWidget(LineF1Direction, 1, 1, 1, 2);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_3->addWidget(label_21, 9, 0, 1, 2);

        checkF1SteeringSystem = new QCheckBox(groupBox_3);
        checkF1SteeringSystem->setObjectName(QString::fromUtf8("checkF1SteeringSystem"));

        gridLayout_3->addWidget(checkF1SteeringSystem, 8, 2, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 1, 1, 2, 2);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        checkF2Obstacle = new QCheckBox(groupBox_4);
        checkF2Obstacle->setObjectName(QString::fromUtf8("checkF2Obstacle"));

        gridLayout_4->addWidget(checkF2Obstacle, 3, 2, 1, 1);

        label_30 = new QLabel(groupBox_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_4->addWidget(label_30, 4, 0, 1, 2);

        checkF2EngineSystem = new QCheckBox(groupBox_4);
        checkF2EngineSystem->setObjectName(QString::fromUtf8("checkF2EngineSystem"));

        gridLayout_4->addWidget(checkF2EngineSystem, 4, 2, 1, 1);

        label_26 = new QLabel(groupBox_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_4->addWidget(label_26, 1, 0, 1, 1);

        label_33 = new QLabel(groupBox_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_4->addWidget(label_33, 7, 0, 1, 2);

        label_34 = new QLabel(groupBox_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_4->addWidget(label_34, 8, 0, 1, 2);

        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_4->addWidget(label_25, 0, 0, 1, 1);

        LineF2Direction = new QLineEdit(groupBox_4);
        LineF2Direction->setObjectName(QString::fromUtf8("LineF2Direction"));

        gridLayout_4->addWidget(LineF2Direction, 1, 1, 1, 2);

        label_27 = new QLabel(groupBox_4);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_4->addWidget(label_27, 2, 0, 1, 2);

        checkF2SteeringSystem = new QCheckBox(groupBox_4);
        checkF2SteeringSystem->setObjectName(QString::fromUtf8("checkF2SteeringSystem"));

        gridLayout_4->addWidget(checkF2SteeringSystem, 8, 2, 1, 1);

        checkF2ElectricaSystem = new QCheckBox(groupBox_4);
        checkF2ElectricaSystem->setObjectName(QString::fromUtf8("checkF2ElectricaSystem"));

        gridLayout_4->addWidget(checkF2ElectricaSystem, 9, 2, 1, 1);

        lineF2Speed = new QLineEdit(groupBox_4);
        lineF2Speed->setObjectName(QString::fromUtf8("lineF2Speed"));

        gridLayout_4->addWidget(lineF2Speed, 0, 1, 1, 2);

        label_35 = new QLabel(groupBox_4);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_4->addWidget(label_35, 9, 0, 1, 2);

        checkF2BrakeSystem = new QCheckBox(groupBox_4);
        checkF2BrakeSystem->setObjectName(QString::fromUtf8("checkF2BrakeSystem"));

        gridLayout_4->addWidget(checkF2BrakeSystem, 7, 2, 1, 1);

        label_32 = new QLabel(groupBox_4);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_4->addWidget(label_32, 6, 0, 1, 2);

        checkF2CommFailure = new QCheckBox(groupBox_4);
        checkF2CommFailure->setObjectName(QString::fromUtf8("checkF2CommFailure"));

        gridLayout_4->addWidget(checkF2CommFailure, 2, 2, 1, 1);

        label_31 = new QLabel(groupBox_4);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_4->addWidget(label_31, 5, 0, 1, 1);

        checkF2FuelSystem = new QCheckBox(groupBox_4);
        checkF2FuelSystem->setObjectName(QString::fromUtf8("checkF2FuelSystem"));

        gridLayout_4->addWidget(checkF2FuelSystem, 5, 2, 1, 1);

        checkF2CoolingSystem = new QCheckBox(groupBox_4);
        checkF2CoolingSystem->setObjectName(QString::fromUtf8("checkF2CoolingSystem"));

        gridLayout_4->addWidget(checkF2CoolingSystem, 6, 2, 1, 1);

        label_28 = new QLabel(groupBox_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_4->addWidget(label_28, 3, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 1, 3, 2, 2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cbLeadHilAssistance = new QCheckBox(groupBox);
        cbLeadHilAssistance->setObjectName(QString::fromUtf8("cbLeadHilAssistance"));

        gridLayout_2->addWidget(cbLeadHilAssistance, 5, 2, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 5, 0, 1, 1);

        cbLeadObstacle = new QCheckBox(groupBox);
        cbLeadObstacle->setObjectName(QString::fromUtf8("cbLeadObstacle"));

        gridLayout_2->addWidget(cbLeadObstacle, 4, 2, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 4, 0, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_2->addWidget(label_24, 2, 0, 1, 1);

        cbLeadCommFailure = new QCheckBox(groupBox);
        cbLeadCommFailure->setObjectName(QString::fromUtf8("cbLeadCommFailure"));

        gridLayout_2->addWidget(cbLeadCommFailure, 3, 2, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 0, 0, 1, 1);

        lineLeadBrake = new QLineEdit(groupBox);
        lineLeadBrake->setObjectName(QString::fromUtf8("lineLeadBrake"));

        gridLayout_2->addWidget(lineLeadBrake, 2, 1, 1, 2);

        lineLeadDirection = new QLineEdit(groupBox);
        lineLeadDirection->setObjectName(QString::fromUtf8("lineLeadDirection"));

        gridLayout_2->addWidget(lineLeadDirection, 1, 1, 1, 2);

        lineLeadSpeed = new QLineEdit(groupBox);
        lineLeadSpeed->setObjectName(QString::fromUtf8("lineLeadSpeed"));

        gridLayout_2->addWidget(lineLeadSpeed, 0, 1, 1, 2);


        gridLayout_5->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        cbLeadEngineSystem = new QCheckBox(groupBox_2);
        cbLeadEngineSystem->setObjectName(QString::fromUtf8("cbLeadEngineSystem"));

        gridLayout->addWidget(cbLeadEngineSystem, 0, 1, 1, 1);

        cbLeadFuelSystem = new QCheckBox(groupBox_2);
        cbLeadFuelSystem->setObjectName(QString::fromUtf8("cbLeadFuelSystem"));

        gridLayout->addWidget(cbLeadFuelSystem, 1, 1, 1, 1);

        cbLeadCoolingSystem = new QCheckBox(groupBox_2);
        cbLeadCoolingSystem->setObjectName(QString::fromUtf8("cbLeadCoolingSystem"));

        gridLayout->addWidget(cbLeadCoolingSystem, 2, 1, 1, 1);

        cbLeadBrakeSystem = new QCheckBox(groupBox_2);
        cbLeadBrakeSystem->setObjectName(QString::fromUtf8("cbLeadBrakeSystem"));

        gridLayout->addWidget(cbLeadBrakeSystem, 0, 3, 1, 1);

        cbLeadSteeringSystem = new QCheckBox(groupBox_2);
        cbLeadSteeringSystem->setObjectName(QString::fromUtf8("cbLeadSteeringSystem"));

        gridLayout->addWidget(cbLeadSteeringSystem, 1, 3, 1, 1);

        cbLeadElectricalSystem = new QCheckBox(groupBox_2);
        cbLeadElectricalSystem->setObjectName(QString::fromUtf8("cbLeadElectricalSystem"));

        gridLayout->addWidget(cbLeadElectricalSystem, 2, 3, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 2, 0, 1, 1);

        txtPort = new QLineEdit(centralwidget);
        txtPort->setObjectName(QString::fromUtf8("txtPort"));

        gridLayout_5->addWidget(txtPort, 0, 1, 1, 1);

        btnStartServer = new QToolButton(centralwidget);
        btnStartServer->setObjectName(QString::fromUtf8("btnStartServer"));

        gridLayout_5->addWidget(btnStartServer, 0, 2, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 650, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Lead Truck", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Follower 1 status", nullptr));
        checkF1EngineSystem->setText(QString());
        checkF1Obstacle->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "Fuel System", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Engine System", nullptr));
        checkF1CoolingSystem->setText(QString());
        checkF1BrakeSystem->setText(QString());
        checkF1ElectricaSystem->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        checkF1FuelSystem->setText(QString());
        label_23->setText(QCoreApplication::translate("MainWindow", "Comm failure", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Cooling System", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Direction", nullptr));
        checkF1CommFailure->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "Brake System", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Steering System", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Obstacle", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Electrical System", nullptr));
        checkF1SteeringSystem->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Follower 2 status", nullptr));
        checkF2Obstacle->setText(QString());
        label_30->setText(QCoreApplication::translate("MainWindow", "Engine System", nullptr));
        checkF2EngineSystem->setText(QString());
        label_26->setText(QCoreApplication::translate("MainWindow", "Direction", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Brake System", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Steering System", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Comm failure", nullptr));
        checkF2SteeringSystem->setText(QString());
        checkF2ElectricaSystem->setText(QString());
        label_35->setText(QCoreApplication::translate("MainWindow", "Electrical System", nullptr));
        checkF2BrakeSystem->setText(QString());
        label_32->setText(QCoreApplication::translate("MainWindow", "Cooling System", nullptr));
        checkF2CommFailure->setText(QString());
        label_31->setText(QCoreApplication::translate("MainWindow", "Fuel System", nullptr));
        checkF2FuelSystem->setText(QString());
        checkF2CoolingSystem->setText(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "Obstacle", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Lead Truck Scenarios", nullptr));
        cbLeadHilAssistance->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Direction", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Hill Assistance", nullptr));
        cbLeadObstacle->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Obstacle", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Comm failure", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Brake", nullptr));
        cbLeadCommFailure->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Lead Truck Health Simulator", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Fuel System", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Electrical System", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Cooling System", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Engine System", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Brake System", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Steering System", nullptr));
        cbLeadEngineSystem->setText(QString());
        cbLeadFuelSystem->setText(QString());
        cbLeadCoolingSystem->setText(QString());
        cbLeadBrakeSystem->setText(QString());
        cbLeadSteeringSystem->setText(QString());
        cbLeadElectricalSystem->setText(QString());
        btnStartServer->setText(QCoreApplication::translate("MainWindow", "Start Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
