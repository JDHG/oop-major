#include "plane.h"
#include "pilot.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//static member declarations
int Plane::creationID = 0; //number of planes that exist
int Plane::IDcount = 0; //number of ID's that exist
vector<string> Plane::takenIDs; //ID's that have been used

Plane::Plane()
{
	creationID++;
	planeNumber = creationID;

	totalPassengers = 0;
	hasPilot = false;
	hasCoPilot = false;
	hasID = false;
	hasLocation = false;
	planeID = "no ID";
	location = "none";
}

Plane::Plane(std::string newLocation, std::string newDestination)
{
	creationID++;
	planeNumber = creationID;

	totalPassengers = 0;
	hasPilot = false;
	hasCoPilot = false;
	hasID = false;
	hasLocation = true;
	planeID = "no ID";
	location = newLocation;
}

void Plane::set_id(string newID) //sets ID only if ID is unique from all previous ID's
{
	for (int i = 0; i < IDcount; i++)
	{	
		if (newID == takenIDs[i])
		{
			cout << "* * * This ID is taken. You must enter a unique ID * * *" << endl;
			return;
		}
	}
	takenIDs.push_back(newID); //stores ID so it can't be used again
	IDcount++;
	planeID = newID;
	hasID = true;
}

void Plane::set_location(string newLocation)
{
	location = newLocation;
	hasLocation = true;
}
void Plane::set_airport_location(Airport * newAirport)
{
	airportLocation = newAirport;
	hasLocation = true;
}

void Plane::remove_location()
{
	hasLocation = false;
}

void Plane::set_pilot(Pilot * newPilot) //pilot objects must have a bool to notify if they are available for assignment
{
	if(!newPilot->get_assigned_plane())
	{
		pilot = newPilot;
		hasPilot = true;
		newPilot->set_assigned_plane();
		return;
	}
	cout << "* * * FAILED. Pilot not assigned * * *" << endl;
}

void Plane::set_copilot(Pilot * newCoPilot) //pilot objects must have a bool to notify if they are available for assignment
{
	if(!newCoPilot->get_assigned_plane())
	{
		coPilot = newCoPilot;
		hasCoPilot = true;
		newCoPilot->set_assigned_plane();
		return;
	}
	cout << "* * * FAILED. Co-Pilot not assigned * * *" << endl;
}

bool Plane::check_id()
{
	return hasID;
}
bool Plane::check_location()
{
	return hasLocation;
}

void Plane::clear_passengers()
{
	passengersOnBoard.clear();
	//passengersOnBoard.shrink_to_fit();
	//cout << "size: " << passengersOnBoard.size() << endl;
}

string Plane::get_location()
{
	return location;
}
Airport * Plane::get_airport_location()
{
	if(hasLocation)
	{
		cout << "ATTEMPT RETURN" << endl;
		return airportLocation;
	}
	cout << "* * * THIS PLANE HAS NO LOCATION * * *" << endl;
}

string Plane::get_id()
{
	return planeID;
}

std::vector<Passenger*> Plane::get_passengers_on_board()
{
	return passengersOnBoard;
}

Plane::~Plane()
{

}
