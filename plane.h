#ifndef PLANE_H
#define PLANE_H

#include "pilot.h"
#include "passenger.h"
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
	bool hasLocation; //check these two in can_fly() ?
	bool hasDestination;

	int totalPassengers;
	int planeNumber;

	std::string planeID; //planeID is different from creation ID
	std::string location;
	std::string destination;

	Pilot * pilot;
	Pilot * coPilot;
	std::vector<Passenger*> passengersOnBoard; //maybe just store passenger names and number? this way they can be deleted properly

public:
	Plane();
	Plane(std::string newLocation, std::string newDestination);
	
	virtual bool can_fly() = 0;
	virtual void refuel() = 0;
	virtual void print_details() = 0;
	virtual std::string get_model() = 0;
	virtual void add_passenger(Passenger * newPassenger) = 0;

	void set_id(std::string newID);
	void set_location(std::string newLocation);
	void set_destination(std::string newDestination);
	void remove_location();
	void set_pilot(Pilot * newPilot);
	void set_copilot(Pilot * newCoPilot);

	bool check_id();
	bool check_location();

	void clear_passengers();

	std::string get_location();
	std::string get_destination();
	std::string get_id();

	~Plane();
};

#endif
