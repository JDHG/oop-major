#include "passenger.h"
#include "person.h"

using namespace std;
Passenger() {
	assignedPlane = false;
}
Passenger(std::string newName, int newWeight, std::string newDestination) : Person(newName, newWeight, newDestination) {
	assignedPlane = false;
}
	
//Setters
void set_assigned_plane() {
	assignedPlane = !assignedPlane;
}
void set_location(string newLocation) {
	
}
//Getters
bool get_assigned_plane() {
	return assignedPlane;
}