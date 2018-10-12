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

vector<Plane*> Airport::get_list_planes()
{
	return planesOnSite;
}

void Airport::list_planes()
{
	cout << location << endl;
	for (int i = 0; i < planesOnSite.size(); i++){
		cout << planesOnSite[i]->get_id() << endl;
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

		destAirport->planesOnSite.push_back(depPlane); //copies plane into destination vector

		//moves plane to end of airport's vector and pops it off.
		if (planesOnSite.size() > 1)
		{
			iter_swap(planesOnSite.begin() + (input - 1), planesOnSite.end());
		}
		planesOnSite.pop_back();

		depPlane->set_location(destAirport->get_location());
		return true;
	}
	cout << "Plane unable to depart." << endl;
	return false;
} 

void Airport::add_plane(Plane* newPlane)
{
	if (!newPlane->check_location())
	{
		planesOnSite.push_back(newPlane);
		newPlane->set_location(location);
		cout << newPlane->get_id() << " added succesfully." << endl;
		return;
	}
	cout << newPlane->get_id() << " cannot be added. It is somewhere else in the world." << endl;
}

	
Airport::~Airport()
{

}

