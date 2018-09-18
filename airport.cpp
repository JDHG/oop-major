#include <string>
#include <iostream>
#include "plane.h"
#include "airport.h"

using namespace std;

airport::airport(string loc, int maxP)
{

	location = loc;
	maxPlanes = maxP;
	planesGrounded = 0;
}

	//getters
int airport::get_max_planes()
{
	return maxPlanes;
}

int airport::get_planes_grounded()
{
	return planesGrounded;
}
	
string airport::get_location()
{
	return location;
}

vector<Plane*> airport::get_list_planes()
{
	return planesOnSite;
}

//removes departing plane from planesOnSite array.
bool airport::departure(Plane* depPlane, airport * destAirport)
{
	if (depPlane->can_fly())
	{
		destAirport->planesOnSite.push_back(depPlane);
		// must remove plane from departure airport.
		return true;
	}
	cout << "Plane unable to depart." << endl;
	return false;
} 

void airport::add_plane(Plane* newPlane)
{
	planesOnSite.push_back(newPlane);
	newPlane->set_location(location);
}

	
airport::~airport()
{

}

