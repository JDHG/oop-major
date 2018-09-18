#include "plane.h"
#include "b747.h"
#include "person.h"
#include "pilot.h"

#include <iostream>
#include <string>

using namespace std;

int main ()
{
	B747 plane1;
	B747 plane2;

	plane1.can_fly();

	plane1.set_id("A123");
	plane2.set_id("A123");
	plane2.set_id("B321");

	cout << plane1.get_location() << endl;

	plane1.can_fly();

	plane1.refuel();

	plane1.can_fly();

	return 0;
}
