#include "airport.h"
#include "person.h"
#include "pilot.h"
#include "plane.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string MENU_HEADER = "#####  ";

//functions for creating menus in main program

//airport menus
void build_airport_menu(vector<Airport*> all_airports)
{
	//dynamic menu. changes size with number of elements
	cout << endl << MENU_HEADER << "Select Airport: (enter number)" << endl;
	for (int i = 0; i < all_airports.size(); i++)
	{
		cout << i+1 << "   " << all_airports[i]->get_location() << endl;
	}
}
void build_airport_passenger_menu(vector<Airport*> all_airports)
{
	//dynamic menu. changes size with number of elements
	cout << endl << MENU_HEADER << "Select Airport: (enter number)" << endl;
	for (int i = 0; i < all_airports.size(); i++)
	{
		cout << i+1 << "   " << all_airports[i]->get_location() << endl;
	}
}

void build_airport_sub_menu(Airport* selection)
{
	//static menu. same for all airports
	cout << endl << MENU_HEADER << selection->get_location() << ": (enter number)" << endl;
	cout << "1   depart plane" << endl
		 << "2   add new plane" << endl
		 << "3   list planes" << endl;
	cout << endl << "99   delete this airport" << endl << endl;
}

void build_departure_menu_2(vector<Airport*> destinationList)
{
	cout << endl << MENU_HEADER << "Select Destination: (enter number)" << endl;
	for (int i = 0; i < destinationList.size(); i++)
	{
		cout << i+1 << "    " << destinationList[i]->get_location() << endl;
	}
	cout << endl;
}

void build_add_plane_to_airport_menu(vector<Plane*> all_planes)
{
	cout << endl << MENU_HEADER << "Select plane to add: (enter number)" << endl;
	for (int i = 0; i < all_planes.size(); i++)
	{
		cout << i+1 << "    " << all_planes[i]->get_id()
			 << "    LOCATION: " << all_planes[i]->get_location()
			 << endl;
	}
	cout << endl;
}

//plane menus
void build_plane_menu(vector<Plane*> all_planes)
{
	//dynamic menu. changes size with number of elements
	cout << endl << MENU_HEADER << "Select Plane: (enter number)" << endl;
	cout << "(#)    " << "(MODEL)    " << "(ID)    " << "(LOCN)   " << endl;
	for (int i = 0; i < all_planes.size(); i++)
	{
		cout << i+1 << "   " << all_planes[i]->get_model()
			<< "    " << all_planes[i]->get_id()
			<< "    " << all_planes[i]->get_location()
			<< endl;
	}
	cout << endl << "99   create new plane" << endl << endl;
}

void build_plane_sub_menu(Plane* selection)
{
	//if plane doesn't have an ID yet then one must be set
	while (!selection->check_id())
	{
		cout << MENU_HEADER << "Enter a new ID for this plane: ";
		string newID;
		cin >> newID;
		selection->set_id(newID);
	}
	//static menu. same for all planes
	if (selection->check_id())
	{
		cout << endl << MENU_HEADER << selection->get_id() << ": (enter number)" << endl;
		cout << "1   change ID" << endl
			 << "2   add passengers" << endl
			 << "3   add pilot" << endl
			 << "4   add co Pilot" << endl
			 << "5   refuel" << endl;
		cout << endl << "99   delete this plane" << endl << endl;
	}
}

void build_add_plane_menu()
{
	cout << MENU_HEADER << "Choose plane type: " << endl
		 << "1    A320" << endl
		 << "2    B747" << endl;
}

void build_add_passenger_menu(Airport * airport, int total_passengers)
{
	if (total_passengers > 0)
	{
		cout << "Select Passenger to add from " << airport->get_location() << endl;
		for (int i = 0; i < total_passengers; i++)
		{
			cout << i << "   " << airport->get_passengers_at_airport()[i]->get_name() << endl;
				 //<< " at airport: " << airport->get_passengers_at_airport()[i]->get_location() << endl;
		}
	}
}

void build_set_pilot_menu(vector<Pilot*> all_pilots)
{
	string availability;

	cout << endl << MENU_HEADER << "Select Pilot to assign: (enter number)" << endl;
	for (int i = 0; i < all_pilots.size(); i++)
	{
		if(!all_pilots[i]->get_assigned_plane()) {availability = "TRUE";}
		if(all_pilots[i]->get_assigned_plane()) {availability = "FALSE";}
		cout << i+1 << "   " << all_pilots[i]->get_name()
			<< "   ID number: " << all_pilots[i]->get_id_number()
			<< "   Available: " << availability << endl;
	}
}
void build_set_copilot_menu(vector<Pilot*> all_pilots)
{
	string availability;

	cout << endl << MENU_HEADER << "Select Co-Pilot to assign: (enter number)" << endl;
	for (int i = 0; i < all_pilots.size(); i++)
	{
		if(!all_pilots[i]->get_assigned_plane()) {availability = "TRUE";}
		if(all_pilots[i]->get_assigned_plane()) {availability = "FALSE";}
		cout << i+1 << "   " << all_pilots[i]->get_name()
			<< "   ID number: " << all_pilots[i]->get_id_number()
			<< "   Available: " << availability << endl;
	}
}

//pilot menus
void build_pilot_menu(vector<Pilot*> all_pilots)
{
	//dynamic menu. changes size with number of elements
	cout << endl << MENU_HEADER << "Select Pilot: (enter number)" << endl;
	for (int i = 0; i < all_pilots.size(); i++)
	{
		cout << i+1 << "   " << all_pilots[i]->get_name()
			<< "   ID number: " << all_pilots[i]->get_id_number() << endl;
	}
	cout << endl << "99   create new pilot" << endl << endl;
}

void build_pilot_sub_menu(Pilot* selection)
{
	cout << endl << MENU_HEADER << selection->get_name() << ": (enter number)" << endl;
	cout << "1   change name" << endl;
	cout << endl << "99   fire this pilot" << endl << endl;	
}


//passenger menus
void build_passenger_menu(vector<Passenger*> airportPass)
{
	//dynamic menu. changes size with number of elements
	cout << endl << MENU_HEADER << "Select Passenger: (enter number)" << endl;
	for (int i = 0; i < airportPass.size(); i++)
	{
		cout << i+1 << "    " << airportPass[i]->get_name()
			 << endl;
	}
	cout << endl << "99   create passengers" << endl << endl;
}

void build_passenger_sub_menu(Passenger* selection)
{
	cout << endl << MENU_HEADER << selection->get_name() << ": (enter number)" << endl;
	cout << "1   change name" << endl
		 << "2   *print details" << endl;
	cout << endl << "99   eject this passenger" << endl << endl;	
}