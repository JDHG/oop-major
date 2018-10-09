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
extern void build_pilot_sub_menu(Pilot*);
extern void build_set_pilot_menu(vector<Pilot*>);
extern void build_set_copilot_menu(vector<Pilot*>);

//global variables
const int BACK_INT = -9; //used to go back from sub menus
const int FAIL_INT = -1; //used if input functions fail
const int QUIT_INT = -2; //used by home menu to quit program
string HEADER = "#####  ";

int main ()
{
	vector<Airport*> ALL_AIRPORTS; //every airport created must be added to this vector
	vector<Plane*> ALL_PLANES; //every plane created must be added to this vector
	vector<Pilot*> ALL_PILOTS; //every pilot created must be added to this vector
	vector<Passenger*> ALL_PASSENGERS;

	//program loop input variables
	string strinput; //used for user string input
	int input = 0; //stores user input throughout menus
	int subChoice = 0; //used exclusively with select_option() NEVER INDEX WITH THIS! USE storedIndex!
	int storedIndex = 0; //used (if needed) to keep a vector/array index returned by "subChoice = select_option(ALL_OBJECTS, ALL_OBJECTS.size())""


	cout << endl << "*** Welcome to Plane Sim v0.1 ***" << endl << endl;
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
										switch (subChoice)
										{
											case 0: //departure menus
											{
												//gets planes at current airport
												build_departure_menu_1(ALL_AIRPORTS[storedIndex]->get_list_planes());
												input = select_option(get_sub_input(), ALL_AIRPORTS[storedIndex]->get_list_planes().size()); //input for choosing a plane to depart
												if (input != BACK_INT && input != FAIL_INT)
												{
													int departPlaneIndex = input; //index of which plane is to leave current airport
													build_departure_menu_2(ALL_AIRPORTS);
													input = select_option(get_sub_input(), ALL_AIRPORTS.size());
													if (input != BACK_INT && input != FAIL_INT)
													{
														int destAirportIndex = input;
														ALL_AIRPORTS[storedIndex]->departure(ALL_AIRPORTS[storedIndex]->get_list_planes()[departPlaneIndex], ALL_AIRPORTS[destAirportIndex], departPlaneIndex);
													}
												}
												break;	
											}
											case 1: //add plane to airport menu
											{
												build_add_plane_to_airport_menu(ALL_PLANES); //list true/false availability like pilots
												input = select_option(get_sub_input(), ALL_PLANES.size());
												if (input != BACK_INT && input != FAIL_INT)
												{
													ALL_AIRPORTS[storedIndex]->add_plane(ALL_PLANES[input]);
												}
												break;
											}
											case 2: //list planes
											{
												cout << "*** LIST PLANES AT THIS AIRPORT" << endl;
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
									subChoice = select_option(input, 5); //5 options in plane_sub_menu
									if (subChoice >= 0 && subChoice < 99)
									{
										switch (subChoice)
										{
											case 0:
											{
												//change id
												cout << HEADER << "Enter new ID: " << endl;
												cin >> strinput;
												ALL_PLANES[storedIndex]->set_id(strinput);
												break;
											}
											case 1:
											{
												//add passengers
												cout << "*** CANT ADD PASSENGERS YET" << endl;
												break;
											}
											case 2:
											{
												//add pilot
												build_set_pilot_menu(ALL_PILOTS);
												input = select_option(get_sub_input(), ALL_PILOTS.size());
												if (input != BACK_INT && input != FAIL_INT)
												{
													ALL_PLANES[storedIndex]->set_pilot(ALL_PILOTS[input]);
												}
												break;
											}
											case 3:
											{
												//add co pilot
												build_set_copilot_menu(ALL_PILOTS);
												input = select_option(get_sub_input(), ALL_PILOTS.size());
												if (input != BACK_INT && input != FAIL_INT)
												{
													ALL_PLANES[storedIndex]->set_copilot(ALL_PILOTS[input]);
												}
												break;
											}
											case 4:
											{
												//refuel
												ALL_PLANES[storedIndex]->refuel();
												cout << "Plane refueled." << endl;
												break;
											}
										}
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
								build_pilot_sub_menu(ALL_PILOTS[storedIndex]);
								input = get_sub_input();
								if (input != BACK_INT && input != FAIL_INT)
								{
									subChoice = select_option(input, 1); //1 options in pilot_sub_menu
									if (subChoice >= 0 && subChoice < 99)
									{
										cout << HEADER << "Enter new name: " << endl;
										cin >> strinput;
										ALL_PILOTS[storedIndex]->set_name(strinput);
									}
										
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
				}
				break;
			}
			case 4: //passenger menu
			{
				//build_passenger_menu(ALL_PASSENGERS);
				break;
			}
			//default: {cout << "***invalid input***" << endl; break;}
			case -2: {cout << "QUIT PROGRAM" << endl; break;}
		}
	}
	return 0;
}

//prints home menu as defined
void build_home_menu()
{
	cout << endl << HEADER << "What do you want to manage? (enter number)" << endl
		<< "1   airports" << endl
		<< "2   planes" << endl
		<< "3   pilots" << endl
		//<< "4   passengers" << endl
		<< "enter " << QUIT_INT << " to quit" << endl;
}

int get_home_input() //used for all user input
{
	//cout << "*** get_home_input() " << endl;
	int input;
	cin >> input;
	if (cin.fail()) //prevent infinite loops from invalid input
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		//cout << "***failed get_home_input() checks***" << endl;
		return -1;
	}
	return input;
}

int get_sub_input() //used for all user input
{
	//cout << "*** get_sub_input() " << endl;
	cout << "enter " << BACK_INT << " to go back" << endl;
	int input;
	cin >> input;
	if (cin.fail()) //prevent infinite loops from invalid input
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		//cout << "***failed get_sub_input() checks***" << endl;
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
	cout << HEADER << "Enter new airport's location: ";
	cin >> newLocation;
	Airport * newAirport = new Airport(newLocation);
	return newAirport;
}
Pilot* new_pilot()
{
	string newName;
	cout << HEADER << "Enter pilot's name: ";
	cin >> newName;
	Pilot * newPilot = new Pilot(newName);
	return newPilot;
}
/*
Passenger* new_passenger()
{
	string newName;
	cout << HEADER << "Enter passenger'ss name: ";
	cin >> newName;
	Passenger * newPassenger = new Passenger(newName);
	return newPassenger;
}
*/