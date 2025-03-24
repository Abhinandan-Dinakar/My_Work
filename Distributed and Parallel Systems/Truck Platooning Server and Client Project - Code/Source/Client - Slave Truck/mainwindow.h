#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>

#include "thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


struct FollowerTruck_Data
{
    int truckID;
    int speed;
    int brake;
    int direction;
    //health
    int engineSystem;
    int fuelSystem;
    int coolingSystem;
    int brakeSystem;
    int steeringSystem;
    int electricalSystem;
    //simulation Scenarios
    int communicationFailure;
    int hillAssistance;
    int traffic;
};

enum Direction{
    Right,
    Left,
    Straight
};

enum Status{
    fail,
    pass
};

struct LeadTruck_Data
{
    int speed;
    int brake;
    int direction;
    //health
    int engineSystem;
    int fuelSystem;
    int coolingSystem;
    int brakeSystem;
    int steeringSystem;
    int electricalSystem;
    //simulation Scenarios
    int communicationFailure;
    int hillAssistance;
    int traffic;
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    struct FollowerTruck_Data f1,f2, f3;
    struct LeadTruck_Data structL;

    void delay(int msec);
    float prevSpeed;
    bool speedFlag = true;
    float diffSpeed;
    bool trafficFlag =  false; 

    int Distance;

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;

    Thread  thread1, thread2;

public slots:
    void tcp_connect();
    void tcpDisconnect();

    void follower_data_manager();
    void sendToServer();

    void readFromServer();
    void process_lead_data();

};
#endif // MAINWINDOW_H
