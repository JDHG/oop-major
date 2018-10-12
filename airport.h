#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include <string>
#include "plane.h"
//change

class Airport
{

	std::string location;
	std::vector<Plane*> planesOnSite;
	

public:

	Airport(std::string loc);

	//getters
	std::string get_location();
	std::vector<Plane*> get_list_planes();



	bool departure(Plane* depPlane, Airport* destAirport, int input, bool cheat); //removes departing plane from planesOnSite array.
	void add_plane(Plane* newPlane);
	void list_planes();


	~Airport();
};

#endif
