#include "plane.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//static member declarations
int Plane::creationID = 0; //number of planes thgat exist
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

//checks if ID has already been used
//if not, assigns it to plane and stores ID in static vector
//if it has, assignment is denied
void Plane::set_id(string newID)
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

void Plane::set_location(string newLocation)
{
	location = newLocation;
}

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
