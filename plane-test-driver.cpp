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

	plane1.canFly();

	plane1.setID("A123");
	plane2.setID("A123");
	plane2.setID("B321");

	plane1.canFly();

	plane1.refuel();

	plane1.canFly();

	return 0;
}