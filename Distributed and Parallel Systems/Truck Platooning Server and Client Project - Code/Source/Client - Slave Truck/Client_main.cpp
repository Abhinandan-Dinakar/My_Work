/******************************************************************************

 * Program Name	: Truck Platooning System using Distributed and Parallel System
 * Description 	: Client and Server based communication using P-threads in C++ and GUI creation for better representation using Qt.
 * Author      	: Abhinandan Dinakar
 * Date        	: 25.02.2022
 * Subject 		: Distributed and Parallel Systems
 * Frame Work	: QT Creator
 * Version		: 4.1.0
 
 ******************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
