#ifndef PLANE_H
#define PLANE_H

#include "pilot.h"
#include <string>
#include <vector>

class Plane
{
	static int creationID; //keeps track of how many planes have been created
	static int IDcount; //tracks how many planeIDs have been created
	static std::vector<std::string> takenIDs; //stores ID's that have already been assigned to planes

protected:
	bool hasPilot;
	bool hasCoPilot;
	bool hasID;
	bool hasLocation;

	int totalPassengers;
	int planeNumber;

	std::string planeID; //planeID is different from creation ID
	std::string location;

	Pilot * pilot;
	Pilot * coPilot;
	//Staff ** staff;
	//Passenger ** passengersOnBoard;

public:
	Plane();
	
	virtual bool can_fly() = 0;
	virtual void refuel() = 0;
	virtual void print_details() = 0;
	virtual std::string get_model() = 0;

	void set_id(std::string newID);
	void set_location(std::string newLocation);
	void remove_location();
	void set_pilot(Pilot * newPilot);
	void set_copilot(Pilot * newCoPilot);

	std::string get_location();
	std::string get_id();

	~Plane();
};

#endif
