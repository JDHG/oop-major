#include "airport.h"
#include "person.h"
#include "passenger.h"
#include "pilot.h"
#include "plane.h"
#include "b747.h"
#include "a320.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void build_home_menu();
extern void build_airport_menu(vector<Airport*>);
extern void build_plane_menu(vector<Plane*>);
extern void build_pilot_menu(vector<Pilot*>);

int main ()
{
	//airport declarations
	vector<Airport*> ALL_AIRPORTS; //stores all airports created
	int MAX_PLANES = 3; //all airports have the same max planes just for the moment
	Airport * adelaide = new Airport("Adelaide",MAX_PLANES);
	Airport * tokyo = new Airport("Tokyo", MAX_PLANES);
	ALL_AIRPORTS.push_back(adelaide);
	ALL_AIRPORTS.push_back(tokyo);

	//plane declarations
	vector<Plane*> ALL_PLANES; //stores all planes created
	B747 * alpha = new B747();
	A320 * beta = new A320();
	ALL_PLANES.push_back(alpha);
	ALL_PLANES.push_back(beta);

	//pilot declarations
	//might be wise to remove 'destination' state from pilot class
	//seems unnecessary if Planes track this
	vector<Pilot*> ALL_PILOTS; //stores all pilots created
	Pilot * dave = new Pilot("Dave", 80, "Adelaide");
	Pilot * steve = new Pilot("Steve", 100, "Adelaide");
	Pilot * laura = new Pilot("Laura", 65, "Tokyo");
	Pilot * amy = new Pilot("Amy", 70, "Tokyo");
	ALL_PILOTS.push_back(dave);
	ALL_PILOTS.push_back(steve);
	ALL_PILOTS.push_back(laura);
	ALL_PILOTS.push_back(amy);

	//passenger declarations
	vector<Passenger *> ALL_PASSENGERS;
	Passeneger * shaun = new Passeneger("Shaun",63,"Adelaide");
	ALL_PASSENGERS.push_back(shaun);

	//program loop input variables
	char input = '\0';
	char BACK_CHAR = 'b'; //used to go back from sub menus

	cout << endl << "*** Welcome to Plane Sim v0.001 ***" << endl << endl;

	//main program loop
	while (input != 'q')
	{
		//home menu
		build_home_menu();
		cin >> input; //get user input at home menu

		switch (input)
		{
			//airport managing sub-menu
			case '1':
			{
				while (input != BACK_CHAR)
				{
					build_airport_menu(ALL_AIRPORTS);
					cout << "enter " << BACK_CHAR << " to go back" << endl;
					cin >> input;
				}
				break;
			}
			//plane managing sub-menu
			case '2':
			{
				while (input != BACK_CHAR)
				{
					build_plane_menu(ALL_PLANES);
					cout << "enter " << BACK_CHAR << " to go back" << endl;
					cin >> input;
				}
				break;
			}
			//pilot managing sub-menu
			case '3':
			{
				while (input != BACK_CHAR)
				{
					build_pilot_menu(ALL_PILOTS);
					cout << "enter " << BACK_CHAR << " to go back" << endl;
					cin >> input;
				}
				break;
			}
			//invalid input default
			default:
			{
				cout << "Please type one of the listed commands." << endl;
				break;
			}
			case 'q':
			{
				break;
			}
		}
	}

	cout << "Bye then" << endl;
	return 0;
}

//prints home menu as defined
void build_home_menu()
{
	cout << endl << "What do you want to manage? (enter number)" << endl
		<< "1   airports" << endl
		<< "2   planes" << endl
		<< "3   pilots" << endl
		<< "enter q to quit" << endl;
}