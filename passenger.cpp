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
void Passenger::set_assigned_plane() {
	assignedPlane = !assignedPlane;
}
void Passenger::set_location(string newLocation) {
	location = newLocation;
}
//Getters
bool Passsenger::get_assigned_plane() {
	return assignedPlane;
}