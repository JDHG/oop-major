#include <string>
#include <iostream>
#include "plane.h"
#include "airport.h"

using namespace std;

Airport::Airport(string loc, int maxP)
{

	location = loc;
	maxPlanes = maxP;
	planesGrounded = 0;
}

	//getters
int Airport::get_max_planes()
{
	return maxPlanes;
}

int Airport::get_planes_grounded()
{
	return planesGrounded;
}
	
string Airport::get_location()
{
	return location;
}

vector<Plane*> Airport::get_list_planes()
{
	return planesOnSite;
}

//removes departing plane from planesOnSite array.
bool Airport::departure(Plane* depPlane, Airport * destAirport)
{
	if (depPlane->can_fly())
	{
		destAirport->planesOnSite.push_back(depPlane);
		// must remove plane from departure Airport.
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

