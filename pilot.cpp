#include "pilot.h"
#include "person.h"

using namespace std;

int Pilot::nPilots = 0;

Pilot::Pilot() : Person()
{
	nPilots++;
	IDNumber = nPilots;
	assignedPlane = false;
}
Pilot::Pilot(string newName) : Person(newName)
{
	nPilots++;
	IDNumber = nPilots;
	assignedPlane = false;
}

//Setters
void Pilot::set_id_number(int newIDNumber) {
	IDNumber = newIDNumber;
}
void Pilot::set_assigned_plane() {
	assignedPlane = !assignedPlane;
}
//Getters
int Pilot::get_id_number() {
	return IDNumber;
}
bool Pilot::get_assigned_plane() {
	return assignedPlane;
}
