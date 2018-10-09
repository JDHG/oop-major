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
A320* new_a320();
B747* new_b747();
Airport* new_airport();
Pilot* new_pilot();

//externally defined functions
extern int select_option(int,int);
extern void build_airport_menu(vector<Airport*>);
extern void build_airport_sub_menu(Airport*);
extern void build_departure_menu_1(vector<Plane*>);
extern void build_departure_menu_2(vector<Airport*>);
extern void build_add_plane_to_airport_menu(vector<Plane*>);
extern void build_plane_menu(vector<Plane*>);
extern void build_plane_sub_menu(Plane*);
extern void build_add_plane_menu();
extern void build_pilot_menu(vector<Pilot*>);

//global variables
const int BACK_INT = -9; //used to go back from sub menus
const int FAIL_INT = -1; //used if input functions fail
const int QUIT_INT = -2; //used by home menu to quit program

int main ()
{
	vector<Airport*> ALL_AIRPORTS; //every airport created must be added to this vector
	vector<Plane*> ALL_PLANES; //every plane created must be added to this vector
	vector<Pilot*> ALL_PILOTS; //every pilot created must be added to this vector

	//program loop input variables
	int input = 0; //stores user input throughout menus
	int subChoice = 0; //used exclusively with select_option() NEVER INDEX WITH THIS! USE storedIndex!
	int storedIndex = 0; //used (if needed) to keep a vector/array index returned by "subChoice = select_option(ALL_OBJECTS, ALL_OBJECTS.size())""


	cout << endl << "*** Welcome to Plane Sim v0.001 ***" << endl << endl;
	//main program loop
	while (input != QUIT_INT)
	{
		build_home_menu();
		input = get_home_input();
		switch (input)
		{
			case 1: //airport managing sub-menu
			{
				cout << endl;
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
										cout << "ENTERED 1/2/3 option" << endl;
										switch (subChoice)
										{
											case 0: //departure menus
											{
												 //gets planes at current airport
												build_departure_menu_1(ALL_AIRPORTS[storedIndex]->get_list_planes());
												input = select_option(get_sub_input(), ALL_AIRPORTS[storedIndex]->get_list_planes().size()); //input for choosing a plane to depart
												cout << "input = " << input << endl;
												if (input != BACK_INT && input != FAIL_INT)
												{
													int departPlaneIndex = input; //index of which plane is to leave current airport
													build_departure_menu_2(ALL_AIRPORTS);
													input = select_option(get_sub_input(), ALL_AIRPORTS.size());
													if (input != BACK_INT && input != FAIL_INT)
													{
														int destAirportIndex = input;
														ALL_AIRPORTS[storedIndex]->departure(ALL_AIRPORTS[storedIndex]->get_list_planes()[departPlaneIndex], ALL_AIRPORTS[destAirportIndex], departPlaneIndex);
														//departed plane needs new location set
														//cout << "plane left succesfully?... maybe" << endl;
													}
												}
												break;	
											}
											case 1: //add plane to airport menu
											{
												//list all planes without a location
												build_add_plane_to_airport_menu(ALL_PLANES);
												input = select_option(get_sub_input(), ALL_PLANES.size());
												if (input != BACK_INT && input != FAIL_INT)
												{
													ALL_AIRPORTS[storedIndex]->add_plane(ALL_PLANES[input]);
												}
												break;
											}
											case 2: //list planes
											{
												break;
											}
										}
									}
									if (subChoice == 99) //delete airport
									{
										cout << ALL_AIRPORTS[storedIndex]->get_location() << " airport deleted." << endl;
										delete ALL_AIRPORTS[storedIndex];
										ALL_AIRPORTS.erase(ALL_AIRPORTS.begin() + storedIndex);
										subChoice = BACK_INT;
										input = BACK_INT;
									}
								}
							}
						}
						if (subChoice == 99) {ALL_AIRPORTS.push_back(new_airport());}
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
								if (input != BACK_INT && input != FAIL_INT)
								{
									subChoice = select_option(input, 3); //3 options in plane_sub_menu
									if (subChoice >= 0 && subChoice < 99)
									{
										//do stuff from option 1, 2 or 3
										cout << "ENTERED 1/2/3 option" << endl;
									}
									if (subChoice == 99) //delete plane
									{
										cout << "Plane "<< ALL_PLANES[storedIndex]->get_id() << " deleted." << endl;
										delete ALL_PLANES[storedIndex];
										ALL_PLANES.erase(ALL_PLANES.begin() + storedIndex);
										subChoice = BACK_INT;
										input = BACK_INT;
									}
								}
							}
						}
						if (subChoice == 99) //create new plane menu
						{
							build_add_plane_menu();
							input = select_option(get_sub_input(),2); //2 plane options
							if (input != BACK_INT && input != FAIL_INT)
							{
								switch (input)
								{
									case 0:{ALL_PLANES.push_back(new_a320()); break;}
									case 1:{ALL_PLANES.push_back(new_b747()); break;}
									default:{cout << "*** ADD PLANE FAILED" << endl;}
								}
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
					if (input != BACK_INT && input != FAIL_INT)
					{
						subChoice = select_option(input, ALL_PILOTS.size());
						if (subChoice >= 0 && subChoice < 99) //chosen pilot options menu
						{
							storedIndex = subChoice;
							while (input != BACK_INT)
							{
								//build_pilot_sub_menu(ALL_PILOTS[storedIndex]);
								input = get_sub_input();
								if (input != BACK_INT && input != FAIL_INT)
								{
									/*
									subChoice = select_option(input, x); //x options in pilot_sub_menu
									if (subChoice >= 0 && subChoice < 99)
									{
										//do stuff from option 1, 2 or 3
										cout << "ENTERED 1/2/3 option" << endl;
									}
									*/
									if (subChoice == 99) //delete pilot
									{
										cout << ALL_PILOTS[storedIndex]->get_name() << " has been fired." << endl;
										delete ALL_PILOTS[storedIndex];
										ALL_PILOTS.erase(ALL_PILOTS.begin() + storedIndex);
										subChoice = BACK_INT;
										input = BACK_INT;
									}
								}
							}
						}
					if (subChoice == 99){ALL_PILOTS.push_back(new_pilot());}
					}
				break;
				}
			default: {cout << "***invalid input***" << endl; break;}
			case -2: {cout << "QUIT PROGRAM" << endl; break;}
			}
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

//mid-program object creation functions
A320* new_a320()
{
	A320 * newPlane = new A320();
	return newPlane;
}
B747* new_b747()
{
	B747 * newPlane = new B747();
	return newPlane;
}
Airport* new_airport()
{
	string newLocation;
	int newMax = 3; //airports may not need max_planes for sake of simplicity
	cout << "Enter new airport's location: ";
	cin >> newLocation;
	Airport * newAirport = new Airport(newLocation, newMax);
	return newAirport;
}
Pilot* new_pilot()
{
	string newName;
	int newWeight;
	string atAirport; //this should be assigned by airports
	cout << "Enter pilot's name: ";
	cin >> newName;
	cout << "Enter weight: ";
	cin >> newWeight;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter valid integer weight: ";
		cin >> newWeight;
	}
	cout << "Enter airport: (this functionality will be removed)";
	cin >> atAirport;
	Pilot * newPilot = new Pilot(newName, newWeight, atAirport);
	return newPilot;
}