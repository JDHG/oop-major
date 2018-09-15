#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <vector>

class Plane
{
	static int creationID;
	//static std::vector<std::string> takenIDs;
	static std::string * takenIDs; //testing only. rather use vectors

protected:
	bool hasPilot;
	bool hasCoPilot;
	bool hasID;

	//Pilot * pilot;
	//Pilot * coPilot;
	//Staff ** staff;
	//Passenger ** passengersOnBoard;

	int totalPassengers;
	int planeNumber;


	//planeID is different from creation ID - gets an ID with child class maybe?
	std::string planeID;
	//std::string origin;
	std::string destination;

public:
	Plane();
	
	virtual void canFly() = 0;

	void setID(std::string newID);
	//void setPilot();
	//void setCoPilot();
	void setDest(std::string newDestination);
	void removeDest();
	
	//void refuel; might make this virtual

	~Plane();
};

#endif