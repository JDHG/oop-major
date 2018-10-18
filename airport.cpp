#include <string>
#include <iostream>
#include <vector>
#include "plane.h"
#include "airport.h"

using namespace std;


Airport::Airport(string loc)
{
	location = loc;
	totalPassengers = 0;
}

	//getters	
string Airport::get_location()
{
	return location;
}

vector<Passenger*> Airport::get_passengers_at_airport()
{
	return passengerOnSite;
}

int Airport::get_total_passengers()
{
	return totalPassengers;
}

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
		depPlane->set_airport_location(destAirport);

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
		//need to set current airport for plane too
		cout << newPlane->get_id() << " added succesfully." << endl;
		return;
	}
	cout << newPlane->get_id() << " cannot be added. It is somewhere else in the world." << endl;
}

void Airport::add_passenger_to_airport(Passenger* chosenPassenger)
{
	passengerOnSite.push_back(chosenPassenger);
	chosenPassenger->set_location(location);
	totalPassengers++;
}

void Airport::remove_passenger_from_airport(int index)
{
	passengerOnSite.erase(passengerOnSite.begin() + (index - 1));
} 

void Airport::print_passengers()
{
	if (totalPassengers > 0)
	{
		for (int i = 0; i < totalPassengers; i++)
		{
			cout << "passenger #" << i+1 << " "
				 << passengerOnSite[i]->get_name()
				 << "    located at: "
				 << passengerOnSite[i]->get_location()
				 << endl << endl;
		}
	}
}

Airport::~Airport()
{
	
}