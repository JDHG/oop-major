#ifndef B747_H
#define B747_H

#include "plane.h"

class B747 : public Plane
{
	//carries up to 364 passengers in 3 separate classes
	int firstClassSeats;
	int	businessClassSeats;
	int economyClassSeats;

	int fuelCapacity;
	int fuel;
	int onBoardWeight;
	int maxPayload;

public:
	B747();

	//virtual function definitions
	bool canFly();
	void refuel();

	bool fuelCheck();
	bool pilotCheck();
	bool weightCheck();

	~B747();

};

#endif