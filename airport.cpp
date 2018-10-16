#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "plane.h"
#include "airport.h"

using namespace std;


//another test edit

Airport::Airport(string loc)
{
	location = loc;
}

	//getters	
string Airport::get_location()
{
	return location;
}

/*
vector<Plane*> Airport::get_list_planes()
{
	return planesOnSite;
}
*/

void Airport::list_planes(vector<Plane*> planesOnSite)
{
	cout << "Planes at " << location << " airport: "<< endl;
	for (int i = 0; i < planesOnSite.size(); i++)
	{
		if (planesOnSite[i]->get_location() == location)
		{
			cout << i << "    " << planesOnSite[i]->get_id() << endl;
		}
	}
}

//removes departing plane from planesOnSite array.
bool Airport::departure(Plane* depPlane, Airport* destAirport, int input, bool CHEAT_CODE)
{
	if (depPlane->can_fly() || CHEAT_CODE)
	{
		if (CHEAT_CODE)
		{
			cout << "* * * CHEAT ACTIVE. PLANES CAN ALWAYS FLY * * *" << endl;
		}

		depPlane->set_location(destAirport->get_location());

		return true;
	}
	cout << "Plane unable to depart." << endl;
	return false;
}

void Airport::add_plane(Plane* newPlane)
{
	if (!newPlane->check_location()) //this check isnt working
	{
		newPlane->set_location(location);
		cout << newPlane->get_id() << " added succesfully." << endl;
		return;
	}
	cout << newPlane->get_id() << " cannot be added. It is somewhere else in the world." << endl;
}

void Airport::add_passenger_to_airport(Passenger* chosenPassenger)
{
	passengerOnSite.push_back(chosenPassenger);
	chosenPassenger->set_location(location);	
}

void Airport::remove_passenger_from_airport(int index)
{
	passengerOnSite.erase(passengerOnSite.begin() + (index - 1));
} 

Airport::~Airport()
{

}