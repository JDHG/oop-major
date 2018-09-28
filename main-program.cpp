#include "airport.h"
#include "person.h"
#include "pilot.h"
#include "plane.h"
#include "b747.h"
#include "a320.h"
#include <iostream>
#include <string>
#include <vector>
#include <climits> // for INT_MAX limits in clear_failed_input function
using namespace std;

//functions defined in main-program
void build_home_menu();
int get_input();

//externally defined functions
extern int select_option(int,int);
extern bool delete_airport(vector<Airport*>,int);
extern void build_airport_menu(vector<Airport*>);
extern void build_airport_sub_menu(Airport*);
extern void build_plane_menu(vector<Plane*>);
extern void build_pilot_menu(vector<Pilot*>);

//global variables
const int BACK_INT = 0; //used to go back from sub menus
const int QUIT_INT = -2; //used by home menu to quit program

int main ()
{
	//airport declarations
	vector<Airport*> ALL_AIRPORTS; //every airport created must be added to this vector
	int MAX_PLANES = 3; //all airports have the same max planes just for the moment
	Airport * adelaide = new Airport("Adelaide",MAX_PLANES);
	Airport * tokyo = new Airport("Tokyo", MAX_PLANES);
	ALL_AIRPORTS.push_back(adelaide);
	ALL_AIRPORTS.push_back(tokyo);

	//plane declarations
	vector<Plane*> ALL_PLANES; //every plane created must be added to this vector
	B747 * alpha = new B747();
	A320 * beta = new A320();
	ALL_PLANES.push_back(alpha);
	ALL_PLANES.push_back(beta);

	//pilot declarations
		//might be wise to remove 'destination' state from pilot class
		//seems unnecessary if Planes track this
	vector<Pilot*> ALL_PILOTS; //every pilot created must be added to this vector
	Pilot * dave = new Pilot("Dave", 80, "Adelaide");
	Pilot * steve = new Pilot("Steve", 100, "Adelaide");
	Pilot * laura = new Pilot("Laura", 65, "Tokyo");
	Pilot * amy = new Pilot("Amy", 70, "Tokyo");
	ALL_PILOTS.push_back(dave);
	ALL_PILOTS.push_back(steve);
	ALL_PILOTS.push_back(laura);
	ALL_PILOTS.push_back(amy);

	//program loop input variables
	int input = 0;
	int subChoice = 0;
	int storedIndex = 0; //use to keep an vector/array index if required

	cout << endl << "*** Welcome to Plane Sim v0.001 ***" << endl << endl;

	//main program loop
	while (input != -2)
	{
		//home menu
		build_home_menu();
		input = get_input();

		switch (input)
		{
			//airport managing sub-menu
			case 1:
			{
				while (input != BACK_INT)
				{
					build_airport_menu(ALL_AIRPORTS);
					cout << "enter " << BACK_INT << " to go back" << endl;
					input = get_input();
					if (input != BACK_INT)
					{
						subChoice = select_option(input, ALL_AIRPORTS.size());

						if (subChoice >= 0 && subChoice < 99)
						{
							//chosen airport options menu
							build_airport_sub_menu(ALL_AIRPORTS[subChoice]);
							storedIndex = subChoice;
							while (input != BACK_INT)
							{
								cout << "enter " << BACK_INT << " to go back" << endl;
								input = get_input();
								if (input != BACK_INT)
								{
									subChoice = select_option(input, 3); //3 current options from airport sub menu (99 option doesnt count)
									if (subChoice >= 0 && subChoice < 99)
									{
										//do stuff from option 1, 2 or 3
									}
									if (subChoice == 99)
									{
										if(delete_airport(ALL_AIRPORTS, storedIndex))
										{
											cout << "deleted airport successfully" << endl;
										}
									}
								}
							}
						}
						//create new airport menu
						if (subChoice == 99)
						{
							cout << "ENTERED 99 new airport menu" << endl;
							/*
							build_add_plane_menu();
							cout << "enter " << BACK_INT << " to go back" << endl;
							input = get_input();
							*/
						}
						if (subChoice == -1)
						{
							//edit this output line in final program
							cout << "***invalid input (subChoice " << subChoice << ")***" << endl;
						}
					}
				}
				break;
			}
			//plane managing sub-menu
			case 2:
			{
				while (input != BACK_INT)
				{
					build_plane_menu(ALL_PLANES);
					cout << "enter " << BACK_INT << " to go back" << endl;
					input = get_input();
				}
				break;
			}
			//pilot managing sub-menu
			case 3:
			{
				while (input != BACK_INT)
				{
					build_pilot_menu(ALL_PILOTS);
					cout << "enter " << BACK_INT << " to go back" << endl;
					input = get_input();
				}
				break;
			}
			//invalid input default statement
			default: {cout << "***invalid input***" << endl; break;}
			//quit program
			case -2: {cout << "Bye then" << endl; break;}
		}
	}
	return 0;
}

//prints home menu as defined
void build_home_menu()
{
	cout << endl << "What do you want to manage? (enter number)" << endl
		<< "1   airports" << endl
		<< "2   planes" << endl
		<< "3   pilots" << endl
		<< "enter " << QUIT_INT << " to quit" << endl;
}

int get_input() //used for all menu input
{
	int input;
	cin >> input;
	if (cin.fail()) //prevent infinite loops from invalid input
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "***failed get_input() checks***" << endl;
		return -1;
	}
	return input;
}