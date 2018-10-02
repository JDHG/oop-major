#ifndef A320_H
#define A320_H

#include "plane.h"

class A320 : public Plane
{
	std::string model;
	//carries up to 162 passengers in 1 class
	int seats;

	int fuelCapacity;
	int fuel;
	int onBoardWeight;
	int maxPayload;

public:
	A320();
	A320(std::string newLocation, std::string newDestination);

	//virtual function definitions
	bool can_fly();
	void refuel();
	void print_details();

	bool fuel_check();
	bool pilot_check();
	bool weight_check();

	std::string get_model();

	~A320();
};
#endif