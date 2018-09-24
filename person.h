#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
	std::string name;
	int weight;
	std::string destination;

public:
	Person();
	Person(std::string newName, int newWeight, std::string newDestination);

	//Setters
	void set_name(std::string newName);
	void set_weight(int newWeight);
	void set_destination(std::string newDestination);
	
	//Getters
	std::string get_name();
	int get_weight();
	std::string get_destination();
};
#endif
