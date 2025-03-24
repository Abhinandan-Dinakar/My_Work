/******************************************************************************

 * Program Name	: Truck Platooning System using Distributed and Parallel System
 * Description 	: Client and Server based communication using P-threads in C++ and GUI creation for better representation using Qt.
 * Author      	: Abhinandan Dinakar
 * Date        	: 25.02.2022
 * Subject 		: Distributed and Parallel Systems
 * Frame Work	: QT Creator
 * Version		: 1.2.0
 
 ******************************************************************************/

#include "thread.h"

Thread::Thread(QObject *parent) : QThread(parent)
{

}

void Thread::run(){
    while (m_bStart) {
        emit send();
        msleep(40);
    }
}

bool Thread::bStart() const
{
    return m_bStart;
}

void Thread::setStart(bool bStart)
{
    m_bStart = bStart;
}
