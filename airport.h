#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include <string>
#include "plane.h"
#include "passenger.h"

class Airport
{

	std::string location;  //Location of Airport
	//std::vector<Plane*> planesOnSite; //Vector of planes grounded at chosen Airport
	//std::string * planesOnSite;
	std::vector<Passenger*> passengerOnSite;  //Vector of Passengers at chosen Airport
	

public:

	Airport(std::string loc);

	//getters
	std::string get_location();
	//std::vector<Plane*> get_list_planes();



	bool departure(Plane* depPlane, Airport* destAirport, int input, bool cheat); //removes departing plane from planesOnSite array.
	void add_plane(Plane* newPlane);
	void list_planes(std::vector<Plane*> planesOnSite); //takes ALL_PLANES as argument

	void add_passenger_to_airport(Passenger* chosenPassenger);
	void remove_passenger_from_airport(int index);


	~Airport();
};

#endif
