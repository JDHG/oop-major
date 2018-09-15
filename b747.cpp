#include "plane.h"
#include "b747.h"

#include <iostream>

using namespace std;

B747::B747() : Plane()
{
	//364 total seats
	firstClassSeats = 58;
	businessClassSeats = 36;
	economyClassSeats = 270;

	fuelCapacity = 193280;
	fuel = 1000;

	onBoardWeight = 0;
	maxPayload = 76067; //plane cannot fly if onBoard weight exceeds this value
}

void B747::refuel()
{
	fuel = fuelCapacity;
}

//checks and prints status of all relevant preflight checks
bool B747::canFly()
{
	if (!hasID)
	{
		cout << endl << "This plane must be assigned an ID before checks can be done." << endl << endl;
		return false;
	}

	bool FC,PC,WC;

	cout << "Pre-Flight status of Plane ID: " << planeID << ":" << endl;

	FC = fuelCheck();
	if(!FC)
	{
		cout << "*** Failed fuel check." << endl << "    Refueling required." << endl;
	}

	PC = pilotCheck();
	if(!PC)
	{
		cout << "*** Failed pilot check." << endl;
		if (!hasPilot)
		{
			cout << "    No Pilot assigned." << endl;
		}
		if (!hasCoPilot)
		{
			cout << "    No Co-Pilot assigned." << endl;
		}
	}

	WC = weightCheck();
	if(!WC)
	{
		cout << "*** Failed weight check." << endl << "    Weight Limit exceeded by "
			<< (onBoardWeight - maxPayload) << "kg." << endl;
	}
	cout << "passengers: " << totalPassengers << endl
		<< "plane number: " << planeNumber << endl
		<< "destination: " << destination << endl << endl;

	if (FC && PC && WC)
	{
		cout << "Ready to fly" << endl;
		return true;
	}
	return false;
}

bool B747::fuelCheck()
{
	if (fuel < (fuelCapacity - fuelCapacity/10))
	{
		return false;
	}
	cout << "Passed fuel check." << endl;
	return true;
}

bool B747::pilotCheck()
{
	if (!hasPilot || !hasCoPilot)
	{
		return false;
	}
	cout << "Passed pilot check." << endl;
	return true;
}

bool B747::weightCheck()
{
	if (onBoardWeight > maxPayload)
	{
		return false;
	}
	cout << "Passed weight check." << endl;
	return true;
}

B747::~B747()
{

}