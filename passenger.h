#ifndef PASSENGERS_H
#define PASSENGERS_H
#include "person.h"

class Passenger : public Person {
	bool assignedPlane;

public:
	Passenger();
	Passenger(std::string newName);
	
	//Setters
	void set_assigned_plane();
	void set_location();
	//Getters
	bool get_assigned_plane();
};
#endif