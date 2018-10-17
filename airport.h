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
	int totalPassengers;
	

public:

	Airport(std::string loc);

	//getters
	std::string get_location();
	std::vector<Passenger*> get_passengers_at_airport();
	int get_total_passengers();



	bool departure(Plane* depPlane, Airport* destAirport, int input, bool cheat);
	void add_plane(Plane* newPlane);
	void list_planes(std::vector<Plane*>); //takes ALL_PLANES as argument

	void add_passenger_to_airport(Passenger* chosenPassenger);
	void remove_passenger_from_airport(int index);

	void print_passengers();

	~Airport();
};

#endif
