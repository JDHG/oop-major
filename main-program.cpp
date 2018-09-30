#include "airport.h"
#include "person.h"
#include "pilot.h"
#include "plane.h"
#include "b747.h"
#include "a320.h"
#include <iostream>
#include <string>
#include <vector>
#include <climits> // for INT_MAX limits in get_input functions
using namespace std;

//functions defined in main-program
void build_home_menu();
int get_home_input(); //get home menu input
int get_sub_input(); //get sub menu input

//externally defined functions
extern int select_option(int,int);
//extern bool delete_airport(vector<Airport*>,int); //rethink this functionality
extern void build_airport_menu(vector<Airport*>);
extern void build_airport_sub_menu(Airport*);
extern void build_plane_menu(vector<Plane*>);
extern void build_plane_sub_menu(Plane*);
extern void build_pilot_menu(vector<Pilot*>);

//global variables
const int BACK_INT = 0; //used to go back from sub menus
const int FAIL_INT = -1; //used if input functions fail
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
	B747 * alpha = new B747("Adelaide","Tokyo"); //planes should get location from airports
	A320 * beta = new A320("Tokyo","Adelaide");
	ALL_PLANES.push_back(alpha);
	ALL_PLANES.push_back(beta);

	//pilot declarations
	vector<Pilot*> ALL_PILOTS; //every pilot created must be added to this vector
	Pilot * dave = new Pilot("Dave", 80, "Adelaide"); //pilots should get location from airports
	Pilot * steve = new Pilot("Steve", 100, "Adelaide");
	Pilot * laura = new Pilot("Laura", 65, "Tokyo");
	Pilot * amy = new Pilot("Amy", 70, "Tokyo");
	ALL_PILOTS.push_back(dave);
	ALL_PILOTS.push_back(steve);
	ALL_PILOTS.push_back(laura);
	ALL_PILOTS.push_back(amy);

	//program loop input variables
	int input = 0; //stores user input throughout menus
	int subChoice = 0; //used exclusively with select_option() NEVER INDEX WITH THIS! USE storedIndex!
	int storedIndex = 0; //used (if needed) to keep a vector/array index returned by "subChoice = select_option(ALL_OBJECTS, ALL_OBJECTS.size())""

	cout << endl << "*** Welcome to Plane Sim v0.001 ***" << endl << endl;

	//main program loop
	while (input != -2)
	{
		build_home_menu();
		input = get_home_input();
		switch (input)
		{
			case 1: //airport managing sub-menu
			{
				while (input != BACK_INT)
				{
					build_airport_menu(ALL_AIRPORTS);
					input = get_sub_input();
					if (input != BACK_INT && input != FAIL_INT)
					{
						subChoice = select_option(input, ALL_AIRPORTS.size());
						if (subChoice >= 0 && subChoice < 99) //chosen airport's options sub-menu
						{
							storedIndex = subChoice;
							while (input != BACK_INT)
							{
								build_airport_sub_menu(ALL_AIRPORTS[storedIndex]);
								input = get_sub_input();
								if (input != BACK_INT && input != FAIL_INT)
								{
									subChoice = select_option(input, 3); //3 current options from airport sub menu (99 option doesn't count)
									if (subChoice >= 0 && subChoice < 99)
									{
										//do stuff from option 1, 2 or 3
									}
									if (subChoice == 99)
									{
										cout << "ENTERED 99 delete airport" << endl;
										//delete airport from vector
										subChoice = 0;
									}
								}
							}
						}
						if (subChoice == 99) //create new airport menu
						{
							cout << "ENTERED 99 new airport menu" << endl;
							/*
							build_add_plane_menu();
							input = get_sub_input();
							*/
						}
					}
				}
				break;
			}
			case 2: //plane managing sub-menu
			{
				while (input != BACK_INT)
				{
					build_plane_menu(ALL_PLANES);
					input = get_sub_input();
					if (input != BACK_INT && input != FAIL_INT)
					{
						subChoice = select_option(input, ALL_PLANES.size());
						if (subChoice >= 0 && subChoice < 99) //chosen plane options menu
						{
							storedIndex = subChoice;
							while (input != BACK_INT)
							{
								build_plane_sub_menu(ALL_PLANES[storedIndex]);
								input = get_sub_input();
							}
						}
					}
				}
				break;
			}
			case 3: //pilot managing sub-menu
			{
				while (input != BACK_INT)
				{
					build_pilot_menu(ALL_PILOTS);
					input = get_sub_input();
				}
				break;
			}
			default: {cout << "***invalid input***" << endl; break;}
			case -2: {cout << "QUIT PROGRAM" << endl; break;}
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

int get_home_input() //used for all user input
{
	cout << "*** get_home_input() " << endl;
	int input;
	cin >> input;
	if (cin.fail()) //prevent infinite loops from invalid input
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "***failed get_home_input() checks***" << endl;
		return -1;
	}
	return input;
}

int get_sub_input() //used for all user input
{
	cout << "*** get_sub_input() " << endl;
	cout << "enter " << BACK_INT << " to go back" << endl;
	int input;
	cin >> input;
	if (cin.fail()) //prevent infinite loops from invalid input
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "***failed get_sub_input() checks***" << endl;
		return -1;
	}
	return input;
}