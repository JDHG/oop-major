#include "person.h"
#include "pilot.h"

#include <iostream>
#include <string>

using namespace std;

int main ()
{
	Person adam;
	Person bob("Bob", 80, "Sydney");

	Pilot steve;
	Pilot dave("Dave", 90, "London");

	cout << adam.get_name() << endl;
	cout << adam.get_weight() << endl;
	cout << adam.get_destination() << endl << endl;

	cout << bob.get_name() << endl;
	cout << bob.get_weight() << endl;
	cout << bob.get_destination() << endl << endl;

	cout << steve.get_name() << endl;
	cout << steve.get_weight() << endl;
	cout << steve.get_destination() << endl;
	cout << steve.get_id_number() << endl << endl;

	cout << dave.get_name() << endl;
	cout << dave.get_weight() << endl;
	cout << dave.get_destination() << endl;
	cout << dave.get_id_number() << endl << endl;

	return 0;
}