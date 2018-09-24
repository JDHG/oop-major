#include <string>
#include "person.h"

using namespace std;

Person::Person() {
	name = "no name";
	weight = 0;
	destination = "no destination";
}
Person::Person(string newName, int newWeight, string newDestination) {
	name = newName;
	weight = newWeight;
	destination = newDestination;
}
//Setters
void Person::set_name(string newName) {
	name = newName;
}
void Person::set_weight(int newWeight) {
	weight = newWeight;
}
void Person::set_destination(string newDestination) {
	destination = newDestination;
}
//Getters
string Person::get_name() {
	return name;
}
int Person::get_weight() {
	return weight;
}
string Person::get_destination() {
	return destination;
}