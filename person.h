#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
	std::string name;
	int weight;
	std::string destination;
	std::string location;

public:
	Person();
	Person(std::string newName, int newWeight, std::string newDestination, std::string newLocation);

	void checkout();
	//Setters
	void set_name(std::string newName);
	void set_weight(int newWeight);
	void set_destination(std::string newDestination);
	void set_location(std::string newLocation);
	
	//Getters
	std::string get_name();
	int get_weight();
	std::string get_destination();
	std::string get_location();
};
#endif
