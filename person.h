#ifndef PERSON_H
#define PERSON_H

#include <string>

class person {
	std::string name;
	int weight;
	std::string destination;

public:
	person();
	person(std::string name, int weight, std::string destination);

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
