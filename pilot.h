#ifndef PILOT_H
#define PILOT_H
#include "person.h"

class Pilot : public Person {
	static int nPilots; //tracks number of pilots created for unique ID assignment
	int IDNumber;
	bool assignedPlane;

public:
	Pilot();
	Pilot(std::string newName, int newWeight, std::string newDestination);

	//Setters
	void set_id_number(int newIDNumber);
	void set_assigned_plane();
	//Getters
	int get_id_number();
	bool get_assigned_plane();
};
#endif