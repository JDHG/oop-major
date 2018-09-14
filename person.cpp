#include <string>
#include "person.h"

using namespace std;

person::person() {
	name = "?";
	weight = 0;
	destination = "?";
}
person::person(string name, int weight, string destination) {
	name = name;
	weight = weight;
	destination = destination;
}
//Setters
void person::set_name(string newName) {
	name = newName;
}
void person::set_weight(int newWeight) {
	weight = newWeight;
}
void person::set_destination(string newDestination) {
	destination = newDestination;
}
//Getters
string person::get_name() {
	return name;
}
int person::get_weight() {
	return weight;
}
string person::get_destination() {
	return destination;
}