#ifndef PILOT_H
#define PILOT_H
#include "person.h"

class pilot : public person {
	int IDNumber;
	bool assignedPlane;

public:
	pilot();
	pilot(int IDNumber);

	//Setters
	void set_IDNumber(int newIDNumber);
	void set_assignedPlane();
	//Getters
	int get_IDNumber();
	bool get_assignedPlane();
};
#endif