#include "plane.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int Plane::creationID = 0;
string * Plane::takenIDs = new string[10]; //testing only. rather use vectors

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

//virtual bool canFly() = 0;

//checks if ID has already been used
//if not, assigns it to plane and stores ID in array
//if it has, assignment is denied
void Plane::setID(string newID)
{
	int i;
	for (i = 0; i < creationID; i++)
	{	
		//update to use vectors instead of arrays
		if (newID == takenIDs[i])
		{
			cout << "This ID is taken. You must enter a unique ID." << endl;
			return;
		}
	}
	//Plane::takenIDs.push_back(newID);
	takenIDs[creationID-1] = newID;
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
/*
void Plane::refuel()
{

}
*/
Plane::~Plane()
{

}