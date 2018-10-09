#include <string>
#include "person.h"

using namespace std;

Person::Person() {
	name = "no name";
	destination = "no destination";
	location = "no location";
}
Person::Person(string newName) {
	name = newName;
	destination = "no destination";
	location = "no location";
}
void Person::checkout() {
	location = destination;
	destination = "no destination";
}
//Setters
void Person::set_name(string newName) {
	name = newName;
}
void Person::set_destination(string newDestination) {
	destination = newDestination;
}
void Person::set_location(string newLocation) {
	location = newLocation;
}
//Getters
string Person::get_name() {
	return name;
}
string Person::get_destination() {
	return destination;
}
string Person::get_location() {
	return location;
}