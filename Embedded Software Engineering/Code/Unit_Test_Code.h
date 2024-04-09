/****************************************************************************** 
Unit Testing for Truck Platooning

Subject : Embedded Systems Engineering

Frame Work: Google Test Framework

Version: 1.0.0 23/01/22

Names:
Abhinandan Dinakar
Nikhil Ganapathy Manjapura
Shreya Manasali

******************************************************************************/

/* Header Files*/
#include "pch.h"
#include <iostream>
#include <gtest/gtest.h>
#include "mutex"

using namespace std;
std::mutex sensorLock;


/* Variable Declarations and Initialization */
typedef enum
{
	TEST_OK,
	TEST_NOT_INT,
	TEST_FAILURE,
	TEST_ERROR,
}TEST_STATUS;


/* Class Descriptions */
class TimeOut_Notification {
public:
	TEST_STATUS State = TEST_OK;

	TEST_STATUS TimeOut();
};
TimeOut_Notification Notification;


class ECU {
public:
	TEST_STATUS State = TEST_OK;

	TEST_STATUS Power();
};
ECU PowerOFF;


class FuelSystem {
public:
	TEST_STATUS State = TEST_OK;

	TEST_STATUS Fuel_System();
};
FuelSystem Fuel;


class FaultDetection
{
public:
	TEST_STATUS State = TEST_OK;

	int PlatoonSystem();
};
FaultDetection Fault;


class Sensor
{
public:
	TEST_STATUS State = TEST_OK;

	TEST_STATUS Distance();
};
Sensor Equidistance;


class Obstacle {
public:
	TEST_STATUS State = TEST_OK;

	TEST_STATUS ABS_EBS();
};
Obstacle Brakes;



/* @return State*/
TEST_STATUS TimeOut_Notification::TimeOut()
{
	return State;
}

TEST_STATUS Sensor::Distance()
{
	return State;
}

TEST_STATUS ECU::Power()
{
	return State;
}

TEST_STATUS Obstacle::ABS_EBS()
{
	return State;
}

TEST_STATUS FuelSystem::Fuel_System()
{
	return State;
}



int FaultDetection::PlatoonSystem()
{
	int errorcount = 0;

	if (Notification.TimeOut())
		errorcount++;

	if (Equidistance.Distance())
		errorcount++;

	if (PowerOFF.Power())
		errorcount++;

	if (Brakes.ABS_EBS())
		errorcount++;

	if (Fuel.Fuel_System())
		errorcount++;

	return errorcount;
}



struct TEST_FUNC : public testing::Test {
	void SetUp() {  }
	void TearDown() {}
};


/* Test Cases Implementation and Execution*/

TEST_F(TEST_FUNC, TestCase1) {


	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "SRS ID : PLATOON_SRS_0001" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Requirement : Slave Trucks should notify Application whenever Reception Timeout Occurs, if not set Fault." << endl;
	cout << "Category : Integration Test Case" << endl;
	cout << "Test Case 1 : Check if any Fault Detected during Transmission and Reception of Data." << endl;
	cout << "Expected Result: 0" << endl;
	cout << "Actual Result: " << Fault.PlatoonSystem() << endl;
	ASSERT_EQ(Fault.PlatoonSystem(), 0);
	cout << "Test Case 1: Passed" << endl;
	cout << "Analysis : The TimeoutNotification to be configured for every Packet in the Application to trigger the notification when any Packet is not received within the Configured Time." << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
}

TEST_F(TEST_FUNC, TestCase2) {


	Notification.State = TEST_FAILURE;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "SRS ID : PLATOON_SRS_0002" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Requirement : The Trucks should operate by maintaning Equidistance according to the Configured Values." << endl;
	cout << "Category : Integration Test Case" << endl;
	cout << "Test Case 2 : Transmission of invalid Data when the Sensor is not able to provide a Valid value.(Eg: Faulty Sensor)." << endl;
	cout << "Expected Result: 1" << endl;
	cout << "Actual Result: " << Fault.PlatoonSystem() << endl;
	ASSERT_EQ(Fault.PlatoonSystem(), 1);
	cout << "Test Case 2 : Passed" << endl;
	cout << "Analysis : Check the Malfunctioning of the Sensor." << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
}

TEST_F(TEST_FUNC, TestCase3) {


	Notification.State = TEST_FAILURE;
	PowerOFF.State = TEST_FAILURE;
	Brakes.State = TEST_FAILURE;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "SRS ID : PLATOON_SRS_0003" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Requirement : Transmission shall be stopped during the Power-OFF of the ECU." << endl;
	cout << "Category : Integration Test Case" << endl;
	cout << "Test Case 3 : Master or Slave Truck face Power-OFF Condition." << endl;
	cout << "Expected Result: 3" << endl;
	cout << "Actual Result: " << Fault.PlatoonSystem() << endl;
	ASSERT_EQ(Fault.PlatoonSystem(), 3);
	cout << "Test Case 3 : Passed" << endl;
	cout << "Analysis : Trucks needs to Stop due to Hardware / Software Failure." << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;

}

TEST_F(TEST_FUNC, TestCase4) {


	Notification.State = TEST_FAILURE;
	PowerOFF.State = TEST_FAILURE;
	Brakes.State = TEST_FAILURE;
	Equidistance.State = TEST_FAILURE;
	Fuel.State = TEST_FAILURE;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "SRS ID : PLATOON_SRS_0004" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Requirement : Failure in the Braking System due to Low levels in the fluid Reservoir, Broken Wheel Speed Sensors or System is Turned OFF." << endl;
	cout << "Category : Integration Test Case" << endl;
	cout << "Test Case 4 : To Check the Activation of ABS and EBS Systems." << endl;
	cout << "Expected Result: 5" << endl;
	cout << "Actual Result: " << Fault.PlatoonSystem() << endl;
	ASSERT_EQ(Fault.PlatoonSystem(), 5);
	cout << "Test Case 4 : Passed" << endl;
	cout << "Analysis : The Hardware / Software part of the ABS and EBS needs to be Corrected." << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
}

TEST_F(TEST_FUNC, TestCase5) {


	Notification.State = TEST_NOT_INT;
	PowerOFF.State = TEST_NOT_INT;
	Brakes.State = TEST_NOT_INT;
	Equidistance.State = TEST_NOT_INT;
	Fuel.State = TEST_NOT_INT;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "SRS ID : PLATOON_SRS_0005" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Requirement : Any Failures detected in the Fuel System." << endl;
	cout << "Category : Integration Test Case" << endl;
	cout << "Test Case 5 : To Check the performance of Fuel Filter, Carburator and Fuel Pump." << endl;
	cout << "Expected Result: 5" << endl;
	cout << "Actual Result: " << Fault.PlatoonSystem() << endl;
	ASSERT_EQ(Fault.PlatoonSystem(), 5);
	cout << "Test Case 5 : Passed" << endl;
	cout << "Analysis : Issues related to Fuel System needs to be Corrected." << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
}

TEST_F(TEST_FUNC, TestCase6) {


	Notification.State = TEST_FAILURE;
	PowerOFF.State = TEST_NOT_INT;
	Brakes.State = TEST_ERROR;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "SRS ID : PLATOON_SRS_0006" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Requirement : Any Failures detected in the Cooling System." << endl;
	cout << "Category : Integration Test Case" << endl;
	cout << "Test Case 6 : To Check the Working of Tempareture Sensor." << endl;
	cout << "Expected Result: 5" << endl;
	cout << "Actual Result: " << Fault.PlatoonSystem() << endl;
	ASSERT_EQ(Fault.PlatoonSystem(), 5);
	cout << "Test Case 6 : Passed" << endl;
	cout << "Analysis : Check the Malfunctioning of the Sensor." << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
}

