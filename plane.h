#ifndef PLANE_H
#define PLANE_H

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

	//Pilot * pilot;
	//Pilot * coPilot;
	//Staff ** staff;
	//Passenger ** passengersOnBoard;

	int totalPassengers;
	int planeNumber;

	//planeID is different from creation ID
	std::string planeID;
	//std::string origin;
	std::string destination;

public:
	Plane();
	
	virtual bool canFly() = 0;
	virtual void refuel() = 0;

	void setID(std::string newID);
	//void setPilot();
	//void setCoPilot();
	void setDest(std::string newDestination);
	void removeDest();
	
	std::string getID();

	~Plane();
};

#endif