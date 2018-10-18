#include "airport.h"
#include "person.h"
#include "passenger.h"
#include "pilot.h"
#include "plane.h"
#include "b747.h"
#include "a320.h"
#include <iostream>
#include <stdlib.h> //used for rand()
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
void create_passengers(Airport*);
void print_all_passengers(vector<Airport*>);

//externally defined functions
extern int select_option(int,int);
extern void build_airport_menu(vector<Airport*>);
extern void build_airport_passenger_menu(vector<Airport*>);
extern void build_airport_sub_menu(Airport*);
//extern void build_departure_menu_1(vector<Plane*>);
extern void build_departure_menu_2(vector<Airport*>);
extern void build_add_plane_to_airport_menu(vector<Plane*>);
extern void build_plane_menu(vector<Plane*>);
extern void build_plane_sub_menu(Plane*);
extern void build_add_plane_menu();
extern void build_add_passenger_menu(Airport*, int);
extern void build_pilot_menu(vector<Pilot*>);
extern void build_pilot_sub_menu(Pilot*);
extern void build_set_pilot_menu(vector<Pilot*>);
extern void build_set_copilot_menu(vector<Pilot*>);
extern void build_passenger_menu(vector<Passenger*>);
extern void build_passenger_sub_menu(Passenger*);

extern string rng_name();

//global variables
const int BACK_INT = -9; //used to go back from sub menus
const int FAIL_INT = -1; //used if input functions fail
const int QUIT_INT = -2; //used by home menu to quit program
const int SPEC_INT = 99;
const int MAX_PASSENGERS = 50; //there may be no more than this many passengers created
	  int TOTAL_PASSENGERS = 0;
	  int TOTAL_PLANES = 0;
string HEADER = "#####  ";

int main ()
{
	srand(time(NULL)); //gen random seed for rng_name()
	vector<Airport*> ALL_AIRPORTS; //every airport created must be added to this vector
	vector<Plane*> ALL_PLANES; //every plane created must be added to this vector
	vector<Pilot*> ALL_PILOTS; //every pilot created must be added to this vector

	//program loop input variables
	string strinput; //used for user string input
	int input = 0; //stores user input throughout menus
	int subChoice = 0; //used exclusively with select_option() NEVER INDEX WITH THIS! USE storedIndex!
	int storedIndex = 0; //used (if needed) to keep a vector/array index returned by "subChoice = select_option(ALL_OBJECTS, ALL_OBJECTS.size())""
	int storedIndex_2 = 0;
	int destAirportIndex;
	int departPlaneIndex;
	Airport * passengerSource; //used for adding passengers from airport to plane
	vector<Passenger*>* passengerVec;
	Plane * chosenPlane;
	bool SUCCESSFUL_TRIP = false;
	bool CHEAT_ENABLED = false; //used for departure testing (planes can fly without passing checks)


	cout << endl << "*** Welcome to Plane Sim v0.9 ***" << endl << endl;
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
					cout << endl << "99  create new airport" << endl << endl;
					input = get_sub_input();
					if (input != BACK_INT && input != FAIL_INT)
					{
						subChoice = select_option(input, ALL_AIRPORTS.size());
						if (subChoice >= 0 && subChoice < SPEC_INT) //chosen airport's options sub-menu
						{
							storedIndex = subChoice;
							while (input != BACK_INT)
							{
								build_airport_sub_menu(ALL_AIRPORTS[storedIndex]);
								input = get_sub_input();
								if (input != BACK_INT && input != FAIL_INT)
								{
									subChoice = select_option(input, 3); //3 current options from airport sub menu (SPEC_INT option doesn't count)
									if (subChoice >= 0 && subChoice < SPEC_INT)
									{
										switch (subChoice)
										{
											case 0: //departure menus
											{
												//gets planes at current airport
												cout << HEADER << "CHOOSE A PLANE TO DEPART: " << endl;
												ALL_AIRPORTS[storedIndex]->list_planes(ALL_PLANES);
												input = select_option(get_sub_input(), TOTAL_PLANES); //input for choosing a plane to depart
												if (input != BACK_INT && input != FAIL_INT && input != SPEC_INT)
												{
													departPlaneIndex = input; //index of which plane is to leave current airport
																					 // +1 because select_option() returns input-1

													//cout << "***DEPART PLANE INDEX: " << departPlaneIndex << endl;

													build_departure_menu_2(ALL_AIRPORTS);
													input = select_option(get_sub_input(), ALL_AIRPORTS.size());
													if (input != BACK_INT && input != FAIL_INT && input != SPEC_INT)
													{
														destAirportIndex = input;
														//cout << "***DEST AIRPORT INDEX: " << destAirportIndex << endl;
														//make sure that plane is at that airport before attempting to fly
														if (ALL_PLANES[departPlaneIndex]->get_location()
															==
															ALL_AIRPORTS[storedIndex]->get_location())
														{
															chosenPlane = ALL_PLANES[departPlaneIndex];
															//departure function call
															SUCCESSFUL_TRIP = ALL_AIRPORTS[storedIndex]->departure(
																chosenPlane,
																ALL_AIRPORTS[destAirportIndex],
																departPlaneIndex,
																CHEAT_ENABLED);
															//set airport location

														}
														else
														{
															cout << "INVALID CHOICE" << endl;
														}
													}
													if(SUCCESSFUL_TRIP)
													{
														cout << chosenPlane->get_id()
															 << " has landed at "
															 << chosenPlane->get_location() << endl;

														chosenPlane->clear_passengers();
														cout << "All passengers have been delivered succesfully" << endl;
													}
												}
												break;	
											}
											case 1: //add plane to airport menu
											{
												build_add_plane_to_airport_menu(ALL_PLANES); //list true/false availability like pilots
												input = select_option(get_sub_input(), ALL_PLANES.size());
												if (input != BACK_INT && input != FAIL_INT && input != SPEC_INT)
												{
													ALL_PLANES[input]->set_location(ALL_AIRPORTS[storedIndex]->get_location());
													ALL_PLANES[input]->set_airport_location(ALL_AIRPORTS[storedIndex]);
												}
												break;
											}
											case 2: //list planes
											{
												//cout << "*** LIST PLANES AT THIS AIRPORT" << endl;
												ALL_AIRPORTS[storedIndex]->list_planes(ALL_PLANES);
												break;
											}
										}
									}
									if (subChoice == SPEC_INT) //delete airport
									{
										cout << ALL_AIRPORTS[storedIndex]->get_location() << " airport deleted." << endl;
										
										for (int i = 0; i < ALL_AIRPORTS[storedIndex]->get_total_passengers(); i++)
										{
											delete ALL_AIRPORTS[storedIndex]->get_passengers_at_airport()[i];
										}

										delete ALL_AIRPORTS[storedIndex];
										ALL_AIRPORTS.erase(ALL_AIRPORTS.begin() + storedIndex);
										subChoice = BACK_INT;
										input = BACK_INT;
									}
								}
							}
						}
						if (subChoice == SPEC_INT) {ALL_AIRPORTS.push_back(new_airport());}
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
						if (subChoice >= 0 && subChoice < SPEC_INT) //chosen plane options menu
						{
							storedIndex = subChoice;
							while (input != BACK_INT)
							{
								build_plane_sub_menu(ALL_PLANES[storedIndex]);
								input = get_sub_input();
								if (input != BACK_INT && input != FAIL_INT)
								{
									subChoice = select_option(input, 5); //5 options in plane_sub_menu
									if (subChoice >= 0 && subChoice < SPEC_INT)
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
												if (TOTAL_PASSENGERS != 0)
												{
													if(ALL_PLANES[storedIndex]->check_location())
													{
														passengerSource = ALL_PLANES[storedIndex]->get_airport_location();
														cout << "airport locale: " << passengerSource->get_location() << endl;

														build_add_passenger_menu(passengerSource, passengerSource->get_total_passengers());
														//input = select_option(get_sub_input(), passengerSource->get_total_passengers());
														input = get_sub_input();

														if (input != BACK_INT && input != FAIL_INT && input != SPEC_INT)
														{
															if (input <= passengerSource->get_total_passengers() && input >= 0)
															{
																cout << "PASSENGER INDEX: " << input << endl;
																ALL_PLANES[storedIndex]->add_passenger(passengerSource->get_passengers_at_airport()[input]);
																cout << "succesfully added passenger "
																	 << passengerSource->get_passengers_at_airport()[input]->get_name()
																	 << endl;
															}
															else
															{
																cout << "***INVALID CHOICE***" << endl;
															}

														}
													}
													else
													{
														cout << "THIS PLANE HAS NO LOCATION ASSIGNED" << endl;
													}
													
												}
												else
												{
													cout << HEADER << "There are no passengers to add." << endl;
												}
												break;
											}
											case 2:
											{
												//add pilot
												build_set_pilot_menu(ALL_PILOTS);
												input = select_option(get_sub_input(), ALL_PILOTS.size());
												if (input != BACK_INT && input != FAIL_INT && input != SPEC_INT)
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
												if (input != BACK_INT && input != FAIL_INT && input != SPEC_INT)
												{
													ALL_PLANES[storedIndex]->set_copilot(ALL_PILOTS[input]);
												}
												break;
											}
											case 4:
											{
												//refuel
												ALL_PLANES[storedIndex]->refuel();
												cout << HEADER << "Plane refueled." << endl;
												break;
											}
										}
									}
									if (subChoice == SPEC_INT) //delete plane
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
						if (subChoice == SPEC_INT) //create new plane menu
						{
							build_add_plane_menu();
							input = select_option(get_sub_input(),2); //2 plane options
							if (input != BACK_INT && input != FAIL_INT && input != SPEC_INT)
							{
								switch (input)
								{
									case 0:{ALL_PLANES.push_back(new_a320()); break;}
									case 1:{ALL_PLANES.push_back(new_b747()); break;}
									default:{cout << "*** ADD PLANE FAILED" << endl;}
								}
								TOTAL_PLANES++;
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
						if (subChoice >= 0 && subChoice < SPEC_INT) //chosen pilot options menu
						{
							storedIndex = subChoice;
							while (input != BACK_INT)
							{
								build_pilot_sub_menu(ALL_PILOTS[storedIndex]);
								input = get_sub_input();
								if (input != BACK_INT && input != FAIL_INT)
								{
									subChoice = select_option(input, 1); //1 options in pilot_sub_menu
									if (subChoice >= 0 && subChoice < SPEC_INT)
									{
										cout << HEADER << "Enter new name: " << endl;
										cin >> strinput;
										ALL_PILOTS[storedIndex]->set_name(strinput);
									}
										
									if (subChoice == SPEC_INT) //delete pilot
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
					if (subChoice == SPEC_INT){ALL_PILOTS.push_back(new_pilot());}
					}
				}
				break;
			}
			case 4: //passenger menu
			{
				if (ALL_AIRPORTS.size() > 0)
				{
					build_airport_menu(ALL_AIRPORTS); //must choose an airport first as they store passengers
					input = get_sub_input();
					if (input != BACK_INT && input != FAIL_INT && input != SPEC_INT)
					{
						subChoice = select_option(input, ALL_AIRPORTS.size());
						if (subChoice >= 0 && subChoice <= ALL_AIRPORTS.size())
						{
							storedIndex = subChoice;
							cout << "STORED INDEX" << storedIndex << endl;
							passengerSource = ALL_AIRPORTS[storedIndex]; //get chosen airport
							build_passenger_menu(passengerSource->get_passengers_at_airport());
							input = get_sub_input();

							if (input != BACK_INT && input != FAIL_INT && input != SPEC_INT) //choose a passenger if available
							{
								subChoice = select_option(input, passengerSource->get_passengers_at_airport().size());
								if (subChoice >= 0 && subChoice <= passengerSource->get_passengers_at_airport().size())
								{
									storedIndex_2 = subChoice;
									build_passenger_sub_menu(passengerSource->get_passengers_at_airport()[storedIndex_2]);
									input = get_sub_input();
									if (input != BACK_INT && input != FAIL_INT && input != SPEC_INT)
									{
										subChoice = select_option(input, 2); //2 options in passenger sub menu
										switch (subChoice)
										{
											case 0: //change name
											{
												cout << HEADER << "Enter new name: " << endl;
												cin >> strinput;
												passengerSource->get_passengers_at_airport()[storedIndex_2]->set_name(strinput);
												cout << "NAME CHANGED" << endl;
												break;
											}

											case 1: //print details
											{
												cout << "PRINT" << endl;
												break;
											}
										}
									}
									if (input == SPEC_INT) //delete passengers
									{
								
										subChoice = BACK_INT;
										input = BACK_INT;
									}
								}
							}

							if (input == SPEC_INT) //create passengers
							{
								create_passengers(passengerSource);
							}
						}
					}

				}
				if (ALL_AIRPORTS.size() <= 0)
				{
					cout << HEADER << "NO AIRPORT AVAILABLE FOR PASSENGER CREATION" << endl;
				}

				break;
			}

			case 345131: //cheat for flying without passing checks
			{
				cout << "ENTERED CHEAT - TESTING ONLY" << endl;
				CHEAT_ENABLED = !CHEAT_ENABLED;
				cout << "cheat active: " << CHEAT_ENABLED << endl;
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
		<< "4   passengers" << endl
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
void create_passengers(Airport* airport)
{
	int nPassengers;
	int createdCount = 0;
	string newName;
	//create multiple passengers
	cout << HEADER << "You may create up to " << MAX_PASSENGERS << " passengers." << endl
		 << "Total passengers: " << TOTAL_PASSENGERS << "/" << MAX_PASSENGERS << endl
		 << "How many passengers do you want to create at " << airport->get_location() << " airport? ";
	cin >> nPassengers;
	while (cin.fail()) //prevent infinite loops from invalid input
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter valid integer value: ";
		cin >> nPassengers;
	}

	for (int i = 0; i < nPassengers; i++)
	{
		if (TOTAL_PASSENGERS < MAX_PASSENGERS)
		{
			newName = rng_name();
			Passenger * newPassenger = new Passenger(newName);
			airport->add_passenger_to_airport(newPassenger);
			TOTAL_PASSENGERS++;
			createdCount++;
			cout << "Passenger " << newName << " created." << endl;
		}
		if (TOTAL_PASSENGERS >= MAX_PASSENGERS)
		{
			i = nPassengers;
		}
	}
	cout << createdCount << " passengers created succesfully at " << airport->get_location() << " airport." << endl;
	cout << "Total passengers in the world: " << TOTAL_PASSENGERS << "/" << MAX_PASSENGERS << endl;
}

void print_all_passengers(vector<Airport*> all_airports)
{
	for (int i = 0; i < all_airports.size(); i++)
	{
		all_airports[i]->print_passengers();
	}
}