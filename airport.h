#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include <string>
#include "plane.h"
//change

class Airport
{

	int maxPlanes;
	int planesGrounded;
	std::string location;
	std::vector<Plane*> planesOnSite;
	

public:

	Airport(std::string loc, int maxP);

	//getters
	int get_max_planes();
	int get_planes_grounded();
	std::string get_location();
	std::vector<Plane*> get_list_planes();



	bool departure(Plane* depPlane, Airport * destAirport); //removes departing plane from planesOnSite array.
	void add_plane(Plane* newPlane);

	~Airport();
};

#endif
