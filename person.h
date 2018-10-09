#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
	std::string name;
	std::string destination;
	std::string location;

public:
	Person();
	Person(std::string newName);

	void checkout();
	//Setters
	void set_name(std::string newName);
	void set_destination(std::string newDestination);
	void set_location(std::string newLocation);
	
	//Getters
	std::string get_name();
	std::string get_destination();
	std::string get_location();
};
#endif
