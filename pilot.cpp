#include "pilot.h"
#include "person.h"

pilot::pilot() { //child constructor needs to call parent constructor aswell - Jason
	IDNumber = 0;
	assignedPlane = false;
}
pilot::pilot(int IDNumber) { //child constructor needs to call parent constructor aswell - Jason
	IDNumber = IDNumber;
	assignedPlane = false;
}

//Setters
void pilot::set_IDNumber(int newIDNumber) {
	IDNumber = newIDNumber;
}
void pilot::set_assignedPlane() {
	assignedPlane = !assignedPlane;
}
//Getters
int pilot::get_IDNumber() {
	return IDNumber;
}
bool pilot::get_assignedPlane() {
	return assignedPlane;
}
