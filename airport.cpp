#include <string>
#include <iostream>
#include <vector>
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
bool Airport::departure(Plane* depPlane, Airport* destAirport, int input)
{
	if (depPlane->can_fly())
	{
		planesOnSite.erase(planesOnSite.begin() + (input - 1));
		destAirport->planesOnSite.push_back(depPlane);
		return true;
	}
	cout << "Plane unable to depart." << endl;
	return false;
} 

void Airport::add_plane(Plane* newPlane)
{
	planesOnSite.push_back(newPlane);
	newPlane->set_location(location);
}

	
Airport::~Airport()
{

}

