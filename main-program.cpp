#include "airport.h"
#include "person.h"
#include "pilot.h"
#include "plane.h"
#include "b747.h"
#include "a320.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
	//airport declarations
	vector<Airport*> ALL_AIRPORTS; //stores all
	int MAX_PLANES = 3; //all airports have the same max planes just for the moment
	Airport * adelaide = new Airport("Adelaide",MAX_PLANES);
	Airport * tokyo = new Airport("Tokyo", MAX_PLANES);

	//plane declarations
	B747 * alpha = new B747();
	A320 * beta = new A320();

	//pilot declarations
	//might be wise to remove 'destination' state from pilot class
	//seems unnecessary if Planes track this
	Pilot * dave = new Pilot("Dave", 80, "Adelaide");
	Pilot * steve = new Pilot("Steve", 100, "Adelaide");
	Pilot * laura = new Pilot("Laura", 65, "Tokyo");
	Pilot * amy = new Pilot("Amy", 70, "Tokyo");

	//program input variables
	//**may need to use typedef enums for input. switch can't do strings
	string input = "\0";
	string BACK_PHRASE = "back"; //used to go back from sub menus


	cout << endl << "*** Welcome to Plane Sim v0.001 ***" << endl << endl;

	//main program loop
	while (input != "q")
	{
		//home menu
		cout << "What do you want to manage? (type command)" << endl
			<< "   airports" << endl
			<< "   planes" << endl
			<< "   pilots" << endl
			<< "enter q to quit" << endl;
		cin >> input; //get user input

		switch (input)
		{
			//airport managing sub-menu
			case "airports":
			{
				while (input != BACK_PHRASE)
				{
					cout << "**entered airports SS" << endl;
				}
				break;
			}
			//plane managing sub-menu
			case "planes":
			{
				while (input != BACK_PHRASE)
				{
					cout << "**entered planes SS" << endl;
				}
				break;
			}
			//pilot managing sub-menu
			case "pilots":
			{
				while (input != BACK_PHRASE)
				{
					cout << "**entered pilots SS" << endl;
				}
				break;
			}
			//invalid input default
			default:
			{
				cout << "Please type one of the listed commands." << endl;
				break;
			}
		}
	}

	return 0;
}