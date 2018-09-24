#include "plane.h"
#include "a320.h"

#include <iostream>

using namespace std;

A320::A320()
{
	model = "Airbus 320";
	seats = 164;
	fuelCapacity = 27000;
	fuel = 1000;
	onBoardWeight = 0; //this number needs to increase and decrease with all persons/luggage changes
	maxPayload = 19958;
}

void A320::refuel()
{
	fuel = fuelCapacity;
}

bool A320::can_fly() //checks and prints status of all relevant preflight checks
{
	if (!hasID)
	{
		cout << endl << "This plane must be assigned an ID before checks can be done." << endl << endl;
		return false;
	}

	bool FC,PC,WC; //assigns values based on check function results
	cout << "Pre-Flight status of Plane ID: " << planeID << ":" << endl;

	FC = fuel_check();
	if(!FC)
	{
		cout << "*** Failed fuel check." << endl << "    Refueling required." << endl;
	}

	PC = pilot_check();
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

	WC = weight_check();
	if(!WC)
	{
		cout << "*** Failed weight check." << endl << "    Weight Limit exceeded by "
			<< (onBoardWeight - maxPayload) << "kg." << endl;
	}

	if (FC && PC && WC) //if all functions returned true
	{
		cout << "Ready to fly" << endl;
		return true;
	}
	return false;
}

void A320::print_details()
{
	cout << "Details of Plane ID: " << get_id() << endl
		<< "Model: " << model << endl
		<< "Passengers on-board: " << "-/" << seats << endl //update when passengers can be added
		<< "Fuel: " << fuel << "/" << fuelCapacity << " Litres" << endl
		<< "Allowable on-board weight: " << onBoardWeight << "/" << maxPayload << endl;
	if(hasPilot)
	{
		cout 
		<< "Pilot: " << pilot->get_name() << "  ID number: " << pilot->get_id_number() << endl;
	}
	if(hasCoPilot)
	{
		cout
		<< "Co-Pilot: " << coPilot->get_name() << "  ID number: " << coPilot->get_id_number() << endl;
	}
}

bool A320::fuel_check()
{
	if (fuel < (fuelCapacity - fuelCapacity/10))
	{
		return false;
	}
	cout << "Passed fuel check." << endl;
	return true;
}

bool A320::pilot_check()
{
	if (!hasPilot || !hasCoPilot)
	{
		return false;
	}
	cout << "Passed pilot check." << endl;
	return true;
}

bool A320::weight_check()
{
	if (onBoardWeight > maxPayload)
	{
		return false;
	}
	cout << "Passed weight check." << endl;
	return true;
}

A320::~A320()
{

}
