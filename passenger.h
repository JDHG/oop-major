#ifndef PASSENGERS_H
#define PASSENGERS_H
#include "person.h"

class Passenger : public Person {
	bool assignedPlane;

public:
	Passenger();
	Passenger(std::string newName, int newWeight, std::string newDestination);

	//Setters
	void set_assigned_plane();
	void set_location();
	//Getters
	int get_id_number();
	bool get_assigned_plane();
};
#endif