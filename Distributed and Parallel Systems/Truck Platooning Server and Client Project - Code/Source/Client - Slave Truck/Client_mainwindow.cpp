
/******************************************************************************

 * Program Name	: Truck Platooning System using Distributed and Parallel System
 * Description 	: Client and Server based communication using P-threads in C++ and GUI creation for better representation using Qt.
 * Author      	: Abhinandan Dinakar
 * Date        	: 25.02.2022
 * Subject 		: Distributed and Parallel Systems
 * Frame Work	: QT Creator
 * Version		: 5.3.0
 
 ******************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qthread.h>
#include <qtimer.h>
pthread_mutex_t mutex;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(); //Creation of new socket

    ui->txtIpAddress->setText("192.168.0.139");
    ui->txtPortNumber->setText("8802");

    //set initial distance
    Distance = 15;
    ui->lineLeadDistance->setText(QString::number(Distance));
    ui->lineLeadDistance_2->setText(QString::number(Distance));

    //setting button interrupts
    connect(ui->btnConnect, SIGNAL(clicked()), this, SLOT(tcp_connect()));
    connect(ui->btnDisconnect, SIGNAL(clicked()), this, SLOT(tcpDisconnect()));

    /*assigning threads with functions.
     * Thread1 is for follower data management.
     * Thread2 is for writing to server*/
    connect(&thread1, &Thread::send, this, &MainWindow::follower_data_manager);
    connect(&thread2, &Thread::send, this, &MainWindow::sendToServer);
    thread1.setStart(false);
    thread2.setStart(false);
}

/*Destructor*/
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::delay(int msec)
{
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, &QEventLoop::quit);
    loop.exec();
}

/*TCP Disconnect
 * Reconnect incase of failure*/
void MainWindow::tcpDisconnect()
{
    ui->cbFollowerCommFailure->setChecked(true);
    ui->cbFollowerCommFailure_2->setChecked(true);

    socket->disconnect();
    thread1.terminate();
    thread2.terminate();

    ui->txtConsole->append("Trying to make connection");
    delay(500);
    tcp_connect();
}

/*tcp_connect()
 * Send connection request, Connect to host
 * Start threads*/
void MainWindow::tcp_connect()
{
   qDebug()<<"Connecting";
   ui->txtConsole->append("Connection established");
   socket->connectToHost(ui->txtIpAddress->text(), ui->txtPortNumber->text().toInt(),
                         QIODevice::ReadWrite, QAbstractSocket::AnyIPProtocol);
   if(socket->waitForDisconnected(1000)){
       qDebug()<<"Error: "<<socket->errorString();
   }

   ui->cbFollowerCommFailure->setChecked(false);
   ui->cbFollowerCommFailure_2->setChecked(false);

   /*setting an interrupt for data reception.
    * When data is received from Server, go to readFromServer()*/
   connect(socket, SIGNAL(readyRead()), this, SLOT(readFromServer()));

   thread1.setStart(true);
   thread1.start();
   thread2.setStart(true);
   thread2.start();
}


/*sendToServer()
 * Sends Follower Truck data to Server*/
void MainWindow::sendToServer()
{
    qDebug() << "sending data to lead";

    QByteArray arrFollowerData;
    arrFollowerData.append(f1.truckID);
    arrFollowerData.append(f1.speed);
    arrFollowerData.append(f1.brake);
    arrFollowerData.append(f1.direction);

    arrFollowerData.append(f1.engineSystem);
    arrFollowerData.append(f1.fuelSystem);
    arrFollowerData.append(f1.coolingSystem);
    arrFollowerData.append(f1. brakeSystem);
    arrFollowerData.append(f1.steeringSystem);
    arrFollowerData.append(f1.electricalSystem);

    arrFollowerData.append(f1.communicationFailure);
    arrFollowerData.append(f1.traffic);

    arrFollowerData.append(f2.truckID);
    arrFollowerData.append(f2.speed);
    arrFollowerData.append(f2.brake);
    arrFollowerData.append(f2.direction);

    arrFollowerData.append(f2.engineSystem);
    arrFollowerData.append(f2.fuelSystem);
    arrFollowerData.append(f2.coolingSystem);
    arrFollowerData.append(f2. brakeSystem);
    arrFollowerData.append(f2.steeringSystem);
    arrFollowerData.append(f2.electricalSystem);

    arrFollowerData.append(f2.communicationFailure);
    arrFollowerData.append(f2.traffic);

    socket->write(arrFollowerData); //write to client
}

/*readFromServer()
 * Read array from Server.
 * Store it in Lead Truck Structure*/
void MainWindow::readFromServer()
{
    qDebug() << "receiving data";
    QByteArray arrLeadData = socket->readAll(); //read from server
    QByteArray lacalArrLeadData = arrLeadData;
    structL.speed = lacalArrLeadData[0];
    structL.brake = lacalArrLeadData[1];
    structL.direction = lacalArrLeadData[2];

    structL.engineSystem = lacalArrLeadData[3];
    structL.fuelSystem = lacalArrLeadData[4];
    structL.coolingSystem = lacalArrLeadData[5];
    structL.brakeSystem = lacalArrLeadData[6];
    structL.steeringSystem = lacalArrLeadData[7];
    structL.electricalSystem = lacalArrLeadData[8];

    structL.communicationFailure = lacalArrLeadData[9];
    structL.hillAssistance = lacalArrLeadData[10];
    structL.traffic = lacalArrLeadData[11];
    process_lead_data();
    qDebug() << arrLeadData;
}

/*follower_data_manager()
 * Takes user input data and store it in Follower Truck Structure.
 * This data is sent to Server*/
void MainWindow::follower_data_manager()
{

    f1.speed = structL.speed;
    //scenarios
    if(ui->cbFollowerCommFailure->isChecked())
    {
        f1.communicationFailure = fail;
    }else
    {
        f1.communicationFailure = pass;
    }

    if(ui->cbFollowerObstacle->isChecked())
    {
        f1.traffic = fail;
    }else
    {
        f1.traffic = pass;
    }

    //health
    if(ui->cbFollowerEngineSystem->isChecked())
    {
        f1.engineSystem = fail;
    }else
    {
        f1.engineSystem = pass;
    }
    if(ui->cbFollowerFuleSystem->isChecked())
    {
        f1.fuelSystem = fail;
    }else
    {
        f1.fuelSystem = pass;
    }
    if(ui->cbFollowerCoolingSystem->isChecked())
    {
        f1.coolingSystem = fail;
    }else
    {
        f1.coolingSystem = pass;
    }
    if(ui->cbFollowerBrakeSystem->isChecked())
    {
        f1.brakeSystem = fail;
    }else
    {
        f1.brakeSystem = pass;
    }
    if(ui->cbFollowerSteeringSystem->isChecked())
    {
        f1.steeringSystem = fail;
    }else
    {
        f1.steeringSystem = pass;
    }

    if(ui->cbFollowerElectricalSystem->isChecked())
    {
        f1.electricalSystem = fail;
    }else
    {
        f1.electricalSystem = pass;
    }

    //follower 2
//    f1.speed = f2.speed = structL.speed;
    //scenarios
    if(ui->cbFollowerCommFailure_2->isChecked())
    {
        f2.communicationFailure = fail;
    }else
    {
        f2.communicationFailure = pass;
    }

    if(ui->cbFollowerObstacle_2->isChecked())
    {
        f2.traffic = fail;
    }else
    {
        f2.traffic = pass;
    }

    //health
    if(ui->cbFollowerEngineSystem_2->isChecked())
    {
        f2.engineSystem = fail;
    }else
    {
        f2.engineSystem = pass;
    }
    if(ui->cbFollowerFuleSystem_2->isChecked())
    {
        f2.fuelSystem = fail;
    }else
    {
        f2.fuelSystem = pass;
    }
    if(ui->cbFollowerCoolingSystem_2->isChecked())
    {
        f2.coolingSystem = fail;
    }else
    {
        f2.coolingSystem = pass;
    }
    if(ui->cbFollowerBrakeSystem_2->isChecked())
    {
        f2.brakeSystem = fail;
    }else
    {
        f2.brakeSystem = pass;
    }
    if(ui->cbFollowerSteeringSystem_2->isChecked())
    {
        f2.steeringSystem = fail;
    }else
    {
        f2.steeringSystem = pass;
    }

    if(ui->cbFollowerElectricalSystem_2->isChecked())
    {
        f2.electricalSystem = fail;
    }else
    {
        f2.electricalSystem = pass;
    }

}

/*process_lead_data()
 * Process lead truck data and indicate in UI*/
void MainWindow::process_lead_data()
{
    if(prevSpeed == structL.speed)
    {
        speedFlag = true;
    }
    else{
        speedFlag = false;
        prevSpeed = structL.speed;
    }
         if(!speedFlag)
         {
             int speed = 0;
             float incrementSpeed = structL.speed/10.0;
             for(int i=0; i<10; i++)
             {
                 speed = speed + incrementSpeed;
                 f1.speed = f2.speed = speed;
                 ui->lineLeadSpeed->setText(QString::number(speed));
                 ui->lineLeadSpeed_2->setText(QString::number(speed));
                 delay(400);
             }
             ui->lineLeadSpeed->setText(QString::number(structL.speed));
             ui->lineLeadSpeed_2->setText(QString::number(structL.speed));
         }else{
         //do nothing
     }

    ui->lineLeadDistance->setText(QString::number(structL.brake));
    ui->lineLeadDistance_2->setText(QString::number(structL.brake));

    if(structL.direction == Right)
    {
        ui->lineDirection->setText("RIGHT");
        ui->lineDirection_2->setText("RIGHT");
        f1.direction = f2.direction = Right;
    }else if(structL.direction == Left)
    {
        ui->lineDirection->setText("LEFT");
        ui->lineDirection_2->setText("LEFT");
        f1.direction = f2.direction =  Left;
    }else if(structL.direction == Straight)
    {
        ui->lineDirection->setText("STRAIGHT");
        ui->lineDirection_2->setText("STRAIGHT");
        f1.direction = f2.direction = Straight;
    }else
    {
        ui->lineDirection->clear();
        ui->lineDirection_2->clear();
    }

    if(structL.engineSystem == fail)
    {
        ui->txtConsole->setText("Engine System Fail");
    }
    if(structL.fuelSystem == fail)
    {
        ui->txtConsole->setText("Fuel System Fail");
    }
    if(structL.coolingSystem == fail)
    {
        ui->txtConsole->setText("Cooling System Fail");
    }
    if(structL.brakeSystem == fail)
    {
        ui->txtConsole->setText("Brake System Fail");
    }
    if(structL.steeringSystem == fail)
    {
        ui->txtConsole->setText("Steering System Fail");
    }
    if(structL.steeringSystem == fail)
    {
        ui->txtConsole->setText("Electrical System Fail");
    }
    if(structL.communicationFailure == fail)
    {
        ui->txtConsole->setText("Communiction System Fail");
    }
    if(structL.hillAssistance == fail)
    {
        ui->txtConsole->setText("Hill ahead");
        ui->lineLeadDistance->setText(QString::number(Distance*2));
        ui->lineLeadDistance_2->setText(QString::number(Distance*2));
    }else
    {
//        ui->txtConsole->clear();
        ui->lineLeadDistance->setText(QString::number(Distance));
        ui->lineLeadDistance_2->setText(QString::number(Distance));
    }
    if(structL.traffic == fail)
    {
        ui->txtConsole->setText("Traffic ahead");
        trafficFlag = true;
    }else{
        trafficFlag = false;
//        ui->txtConsole->clear();
    }

}
