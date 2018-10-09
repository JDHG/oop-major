#include "passenger.h"
#include "person.h"

using namespace std;
Passenger::Passenger() : Person() {
	assignedPlane = false;
}
Passenger::Passenger(string newName) : Person(newName) {
	assignedPlane = false;
}
//Setters
void Passenger::set_assigned_plane() {
	assignedPlane = !assignedPlane;
}
//Getters
bool Passenger::get_assigned_plane() {
	return assignedPlane;
}