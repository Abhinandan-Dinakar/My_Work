#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

#include "thread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/*structure to store Follower Truck data*/
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

/*Structure to store Lead Truck Data*/
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

/* Direction enumeration*/
enum Direction{
    Right,
    Left,
    Straight
};

/*Status enumeration*/
enum Status{
    fail,
    pass
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //structure objects
    struct LeadTruck_Data structL;
    struct FollowerTruck_Data f1, f2;

    bool trafficFlag = false;
    int speedCounter = 10;
    float speed = 0;
    float decrementSpeed = 0;

private:
    Ui::MainWindow *ui;
    QTcpServer *server;
    QTcpSocket *m_Socket;

    //thread declarations
    Thread thread1, thread2;

public slots:
    //function prototypes
    void startServer();
    void stopServer();
    void newConnection();

    void lead_data_manager();
    void writeToClient();

    void readFromClient();
    void process_follower_data();

};
#endif // MAINWINDOW_H
