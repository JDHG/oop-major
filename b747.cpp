#include "plane.h"
#include "b747.h"

#include <iostream>

using namespace std;

B747::B747() : Plane()
{
	model = "Boeing 747";

	seats = 15;
	fuelCapacity = 193280;
	fuel = 1000;
	onBoardWeight = 0; //this number needs to increase and decrease with all persons/luggage changes
	maxPayload = 76067; //plane cannot fly if onBoard weight exceeds this value
}

B747::B747(std::string newLocation, std::string newDestination) : Plane(newLocation, newDestination)
{
	model = "Boeing 747";

	seats = 15;
	fuelCapacity = 193280;
	fuel = 1000;
	onBoardWeight = 0; //this number needs to increase and decrease with all persons/luggage changes
	maxPayload = 76067; //plane cannot fly if onBoard weight exceeds this value
}

void B747::refuel()
{
	fuel = fuelCapacity;
}

bool B747::can_fly() //checks and prints status of all relevant preflight checks
{
	if (!hasID)
	{
		cout << "This plane must be assigned an ID before checks can be done." << endl;
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

void B747::print_details()
{
	cout << "Details of Plane ID: " << get_id() << endl
		<< "Model: " << model << endl
		<< "Passengers on-board: " << "-/" << seats << endl //update when passengers can be added
		<< "Fuel: " << fuel << "/" << fuelCapacity << " Litres" << endl;
		//<< "Allowable on-board weight: " << onBoardWeight << "/" << maxPayload << endl;
	if(hasPilot)
	{
		cout << "Pilot: " << pilot->get_name() << "  ID number: " << pilot->get_id_number() << endl;
	}
	if(!hasPilot)
	{
		cout << "Pilot: NONE" << endl;
	}

	if(hasCoPilot)
	{
		cout << "Co-Pilot: " << coPilot->get_name() << "  ID number: " << coPilot->get_id_number() << endl;
	}
	if(!hasCoPilot)
	{
		cout << "Co-Pilot: NONE" << endl;
	}
}

void B747::add_passenger(Passenger * newPassenger)
{
	if (newPassenger->get_location() == get_location() && totalPassengers < seats)
	{
		passengersOnBoard.push_back(newPassenger);
		totalPassengers++;
		cout << "Passenger added succesfully" << endl;
		return;
	}
	cout << "* * * FAILED TO ADD PASSENGER * * *" << endl;
}

bool B747::fuel_check()
{
	if (fuel < (fuelCapacity - fuelCapacity/10))
	{
		return false;
	}
	cout << "Passed fuel check." << endl;
	return true;
}

bool B747::pilot_check()
{
	if (!hasPilot || !hasCoPilot)
	{
		return false;
	}
	cout << "Passed pilot check." << endl;
	return true;
}

bool B747::weight_check()
{
	if (onBoardWeight > maxPayload)
	{
		return false;
	}
	cout << "Passed weight check." << endl;
	return true;
}

string B747::get_model()
{
	return model;
}

B747::~B747()
{

}