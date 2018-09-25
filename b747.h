#ifndef B747_H
#define B747_H

#include "plane.h"

class B747 : public Plane
{
	std::string model;

	//carries up to 364 passengers in 3 separate classes
	int firstClassSeats;
	int businessClassSeats;
	int economyClassSeats;

	int fuelCapacity;
	int fuel;
	int onBoardWeight;
	int maxPayload;

public:
	B747();

	//virtual function definitions
	bool can_fly();
	void refuel();
	void print_details();

	bool fuel_check();
	bool pilot_check();
	bool weight_check();

	std::string get_model();

	~B747();
};
#endif