#include "plane.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//static member declarations
int Plane::creationID = 0;
int Plane::IDcount = 0;
vector<string> Plane::takenIDs;

Plane::Plane()
{
	creationID++;
	planeNumber = creationID;

	totalPassengers = 0;
	hasPilot = false;
	hasCoPilot = false;
	hasID = false;

	planeID = "No ID assigned yet.";
	//origin? current location? airport.getLocation()?
	destination = "No destination currently assigned.";
}

//checks if ID has already been used
//if not, assigns it to plane and stores ID in static vector
//if it has, assignment is denied
void Plane::setID(string newID)
{
	for (int i = 0; i < IDcount; i++)
	{	
		if (newID == takenIDs[i])
		{
			cout << "This ID is taken. You must enter a unique ID." << endl;
			return;
		}
	}
	takenIDs.push_back(newID);
	IDcount++;
	planeID = newID;
	hasID = true;
	cout << "test setID - has executed." << endl;
	return;
}

/* need person/pilot classes

void Plane::setPilot(pilot newPilot)
{
	pilot = newPilot;
	hasPilot = true;
	//anyway to unassign pilots?
}
void Plane::setCoPilot(pilot newCoPilot)
{
	coPilot = newCoPilot;
	hasCoPilot = true;
}
*/

void Plane::setDest(string newDestination)
{
	destination = newDestination;
}
void Plane::removeDest()
{
	destination = "No destination currently assigned.";
}
string Plane::getID()
{
	return planeID;
}
/*
void Plane::refuel()
{

}
*/
Plane::~Plane()
{

}