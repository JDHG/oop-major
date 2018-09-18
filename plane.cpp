#include "plane.h"
//#include "person.h"
//#include "pilot.h"

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

	planeID = "No ID assigned yet.";
	location = "No location currently assigned.";
}

void Plane::set_id(string newID) //sets ID only if ID is unique from all previous ID's
{
	for (int i = 0; i < IDcount; i++)
	{	
		if (newID == takenIDs[i])
		{
			cout << "This ID is taken. You must enter a unique ID." << endl;
			return;
		}
	}
	takenIDs.push_back(newID); //stores ID so it can't be used again
	IDcount++;
	planeID = newID;
	hasID = true;
	cout << "test setID - has executed." << endl;
}

void Plane::set_location(string newLocation)
{
	location = newLocation;
}

/*
void Plane::set_pilot(Pilot * newPilot) //pilot objects must have a bool to notify if they are available for assignment
{
	pilot = newPilot;
	hasPilot = true;
}

void Plane::set_copilot(Pilot * newCoPilot) //pilot objects must have a bool to notify if they are available for assignment
{
	coPilot = newCoPilot;
	hasCoPilot = true;
}
*/

string Plane::get_location()
{
	return location;
}

string Plane::get_id()
{
	return planeID;
}

Plane::~Plane()
{

}
