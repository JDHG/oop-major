#ifndef A320_H
#define A320_H

#include "plane.h"

class A320 : public Plane
{
	//carries up to 162 passengers in 1 class
	int seats;

	int fuelCapacity;
	int fuel;
	int onBoardWeight;
	int maxPayload;

public:
	A320();

	//virtual function definitions
	bool can_fly();
	void refuel();
	//void print_details();

	bool fuel_check();
	bool pilot_check();
	bool weight_check();

	~A320();
};
#endif