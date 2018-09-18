#include "plane.h"
#include "b747.h"
#include "a320.h"
#include "person.h"
#include "pilot.h"

#include <iostream>
#include <string>

using namespace std;

int main ()
{
	B747 plane1;
	A320 plane2;

	plane1.can_fly(); //fail due to no ID

	plane1.set_id("B123");
	plane2.set_id("B123");
	plane2.set_id("A555");

	cout << plane1.get_location() << endl;
	plane1.set_location("Canadia");
	cout << plane1.get_location() << endl;

	plane1.can_fly(); //fail fuel and pilot checks

	plane1.refuel();

	plane1.can_fly(); //fail pilot checks only
	plane2.can_fly();

	return 0;
}
