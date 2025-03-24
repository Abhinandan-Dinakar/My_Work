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
#include <qhostinfo.h>
#include <qthread.h>
#include <qtimer.h>

pthread_mutex_t mutex;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer();
    m_Socket = new QTcpSocket; //creation of new socket
    ui->txtPort->setText("8802");

    ui->lineLeadDirection->setText("straight");

    connect(ui->btnStartServer, SIGNAL(clicked()), this, SLOT(startServer()));
//    connect(ui->btnStopServer, SIGNAL(clicked()), this, SLOT(stopServer()));

    /*assigning threads with functions.
     * Thread1 is for processing Lead data.
     * Thread2 is for writing to client*/
    connect(&thread1, &Thread::send, this, &MainWindow::lead_data_manager);
    connect(&thread2, &Thread::send, this, &MainWindow::writeToClient);
    thread1.setStart(false);
    thread2.setStart(false);

}

/*Destructor*/
MainWindow::~MainWindow()
{
    if(m_Socket->isOpen()){
        m_Socket->close();
        m_Socket->deleteLater();
        qDebug()<<"SOCKET CLOSED";
    }

    server->close();
    server->deleteLater();
    delete ui;
}

/*starting server and listen for new connection requests from clients*/
void MainWindow::startServer()
{
    if(!server->listen(QHostAddress::Any, ui->txtPort->text().toInt()))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
        QString host = QHostInfo::localHostName();
        qDebug() << QHostInfo::fromName(host).addresses();
    }
    /*setting an interrupt for new connection.
     * Once new connection established, go to newConnection()*/
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

void MainWindow::stopServer()
{
    if(m_Socket->isOpen()){
        m_Socket->close();
//        m_Socket->deleteLater();
        qDebug()<<"SOCKET CLOSED";
    }

    server->close();
}


/*newConnection()
 *Connect when new connection request is sent from client*/
void MainWindow::newConnection()
{
    qDebug()<<"New Connection";
    if(m_Socket->isOpen()){
        m_Socket->close();
    }
    // need to grab the socket
    QTcpSocket *socket = server->nextPendingConnection();

    socket->flush();
    socket->waitForBytesWritten(3000);

    //socket->close();
    m_Socket = socket;

    /*setting an interrupt for data reception.
     * When data is received from client, go to readFromClient()*/
    connect(m_Socket, SIGNAL(readyRead()), this, SLOT(readFromClient()));

    /*start threads once client-server connection is established*/
    thread1.setStart(true);
    thread1.start();
    thread2.setStart(true);
    thread2.start();
}

/*lead_data_manager()
 * Takes user input data and store it in Lead Truck Structure.
 * This data is sent to Client*/
void MainWindow::lead_data_manager()
{
    structL.speed = ui->lineLeadSpeed->text().toInt();
    structL.brake = ui->lineLeadBrake->text().toUInt();

    if(ui->lineLeadDirection->text() == "right")
    {
        structL.direction = Right;
    }else if(ui->lineLeadDirection->text() == "left")
    {
        structL.direction = Left;
    }else if(ui->lineLeadDirection->text() == "straight")
    {
        structL.direction = Straight;
    }
    //health

    if(ui->cbLeadEngineSystem->isChecked())
    {
        structL.engineSystem = fail;
    }else
    {
        structL.engineSystem = pass;
    }
    if(ui->cbLeadFuelSystem->isChecked())
    {
        structL.fuelSystem = fail;
    }else
    {
        structL.fuelSystem = pass;
    }
    if(ui->cbLeadCoolingSystem->isChecked())
    {
        structL.coolingSystem = fail;
    }else
    {
        structL.coolingSystem = pass;
    }
    if(ui->cbLeadBrakeSystem->isChecked())
    {
        structL.brakeSystem = fail;
    }else
    {
        structL.brakeSystem = pass;
    }
    if(ui->cbLeadSteeringSystem->isChecked())
    {
        structL.steeringSystem = fail;
    }else
    {
        structL.steeringSystem = pass;
    }
    if(ui->cbLeadElectricalSystem->isChecked())
    {
        structL.electricalSystem = fail;
    }else
    {
        structL.electricalSystem = pass;
    }

    //simulation scenarios
    if(ui->cbLeadCommFailure->isChecked())
    {
        structL.communicationFailure = fail;
    }else
    {
        structL.communicationFailure = pass;
    }
    if(ui->cbLeadHilAssistance->isChecked())
    {
        structL.hillAssistance = fail;
    }else
    {
        structL.hillAssistance = pass;
    }
    if(ui->cbLeadObstacle->isChecked())
    {
        structL.traffic = fail;
        ui->lineLeadSpeed->setText(QString::number(0));
    }else
    {
        structL.traffic = pass;
    }
}

/*writeToClient()
 * Sends Lead Truck data to Client*/
void MainWindow::writeToClient()
{
    QByteArray arrLeadData;
    arrLeadData.append(structL.speed);
    arrLeadData.append(structL.brake);
    arrLeadData.append(structL.direction);
    //health
    arrLeadData.append(structL.engineSystem);
    arrLeadData.append(structL.fuelSystem);
    arrLeadData.append(structL.coolingSystem);
    arrLeadData.append(structL.brakeSystem);
    arrLeadData.append(structL.steeringSystem);
    arrLeadData.append(structL.electricalSystem);
    //simulation scenarios
    arrLeadData.append(structL.communicationFailure);
    arrLeadData.append(structL.hillAssistance);
    arrLeadData.append(structL.traffic);

    if(m_Socket->isOpen()){
        m_Socket->write(arrLeadData);
        qDebug()<<"Write";
    }
}

/*readFromClient()
 * Read array from client.
 * Store it in Follower Truck Structure*/
void MainWindow::readFromClient()
{
    QByteArray arrFollowerData = m_Socket->readAll();
    f1.truckID = arrFollowerData[0];
    f1.speed = arrFollowerData[1];
    f1.brake = arrFollowerData[2];
    f1.direction = arrFollowerData[3];
    //health
    f1.engineSystem = arrFollowerData[4];
    f1.fuelSystem = arrFollowerData[5];
    f1.coolingSystem = arrFollowerData[6];
    f1.brakeSystem = arrFollowerData[7];
    f1.steeringSystem = arrFollowerData[8];
    f1.electricalSystem = arrFollowerData[9];
    //simulation Scenarios
    f1.communicationFailure = arrFollowerData[10];
    f1.traffic = arrFollowerData[11];

    //follower2
    f2.truckID = arrFollowerData[12];
    f2.speed = arrFollowerData[13];
    f2.brake = arrFollowerData[14];
    f2.direction = arrFollowerData[15];
    //health
    f2.engineSystem = arrFollowerData[16];
    f2.fuelSystem = arrFollowerData[17];
    f2.coolingSystem = arrFollowerData[18];
    f2.brakeSystem = arrFollowerData[19];
    f2.steeringSystem = arrFollowerData[20];
    f2.electricalSystem = arrFollowerData[21];
    //simulation Scenarios
    f2.communicationFailure = arrFollowerData[22];
    f2.traffic = arrFollowerData[23];

    process_follower_data();
    qDebug() << arrFollowerData;
}


/*process_follower_data()
 * Process Follower data and indicate in UI*/
void MainWindow::process_follower_data()
{
    ui->lineF1Speed->setText(QString::number(f2.speed));
    if(f1.direction == Right)
    {
        ui->LineF1Direction->setText("RIGHT");
    }else if(f1.direction == Left)
    {
        ui->LineF1Direction->setText("LEFT");
    }else if(f1.direction == Straight)
    {
        ui->LineF1Direction->setText("STRAIGHT");
    }else
    {
        ui->LineF1Direction->clear();
    }
    //health
    if(f1.engineSystem == fail)
    {
        ui->checkF1EngineSystem->setChecked(true);
    }else
    {
        ui->checkF1EngineSystem->setChecked(false);
    }
    if(f1.fuelSystem == fail)
    {
        ui->checkF1FuelSystem->setChecked(true);
    }else
    {
        ui->checkF1FuelSystem->setChecked(false);
    }
    if(f1.coolingSystem == fail)
    {
        ui->checkF1CoolingSystem->setChecked(true);
    }else
    {
        ui->checkF1CoolingSystem->setChecked(false);
    }
    if(f1.brakeSystem == fail)
    {
        ui->checkF1BrakeSystem->setChecked(true);
    }else
    {
        ui->checkF1BrakeSystem->setChecked(false);
    }
    if(f1.steeringSystem == fail)
    {
        ui->checkF1SteeringSystem->setChecked(true);
    }else
    {
        ui->checkF1SteeringSystem->setChecked(false);
    }
    if(f1.electricalSystem == fail)
    {
        ui->checkF1ElectricaSystem->setChecked(true);
    }else
    {
        ui->checkF1ElectricaSystem->setChecked(false);
    }


    //simulation scenarios
    if(f1.communicationFailure == fail)
    {
        ui->checkF1CommFailure->setChecked(true);
        ui->lineF1Speed->setText(QString::number(0));
        ui->lineLeadSpeed->setText(QString::number(0));
    }else
    {
        ui->checkF1CommFailure->setChecked(false);
    }
    if(f1.traffic == fail)
    {
        ui->checkF1Obstacle->setChecked(true);
    }else
    {
        ui->checkF1Obstacle->setChecked(false);
    }

    //follower 2 update
    ui->lineF2Speed->setText(QString::number(f2.speed));
    if(f2.direction == Right)
    {
        ui->LineF2Direction->setText("RIGHT");
    }else if(f2.direction == Left)
    {
        ui->LineF2Direction->setText("LEFT");
    }else if(f2.direction == Straight)
    {
        ui->LineF2Direction->setText("STRAIGHT");
    }else
    {
        ui->LineF2Direction->clear();
    }
    //health
    if(f2.engineSystem == fail)
    {
        ui->checkF2EngineSystem->setChecked(true);
    }else
    {
        ui->checkF2EngineSystem->setChecked(false);
    }
    if(f2.fuelSystem == fail)
    {
        ui->checkF2FuelSystem->setChecked(true);
    }else
    {
        ui->checkF2FuelSystem->setChecked(false);
    }
    if(f2.coolingSystem == fail)
    {
        ui->checkF2CoolingSystem->setChecked(true);
    }else
    {
        ui->checkF2CoolingSystem->setChecked(false);
    }
    if(f2.brakeSystem == fail)
    {
        ui->checkF2BrakeSystem->setChecked(true);
    }else
    {
        ui->checkF2BrakeSystem->setChecked(false);
    }
    if(f2.steeringSystem == fail)
    {
        ui->checkF2SteeringSystem->setChecked(true);
    }else
    {
        ui->checkF2SteeringSystem->setChecked(false);
    }
    if(f2.electricalSystem == fail)
    {
        ui->checkF2ElectricaSystem->setChecked(true);
    }else
    {
        ui->checkF2ElectricaSystem->setChecked(false);
    }

    //simulation scenarios
    if(f2.communicationFailure == fail)
    {
        ui->checkF2CommFailure->setChecked(true);
        ui->lineF2Speed->setText(QString::number(0));
        ui->lineLeadSpeed->setText(QString::number(0));
    }else
    {
        ui->checkF2CommFailure->setChecked(false);
    }
    if(f2.traffic == fail)
    {
        ui->checkF2Obstacle->setChecked(true);
    }else
    {
        ui->checkF2Obstacle->setChecked(false);
    }
}

