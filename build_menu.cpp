#include "airport.h"
#include "person.h"
#include "pilot.h"
#include "plane.h"
//#include "b747.h"
//#include "a320.h"
#include <iostream>
#include <vector>
using namespace std;

//functions for creating menus in main program

//airport menus
void build_airport_menu(vector<Airport*> all_airports)
{
	//dynamic menu. changes size with number of elements
	cout << endl << "Select Airport: (enter number)" << endl;
	for (int i = 0; i < all_airports.size(); i++)
	{
		cout << i+1 << "   " << all_airports[i]->get_location() << endl;
	}
	cout << endl << "99  *create new airport" << endl << endl;
}

void build_airport_sub_menu(Airport* selection)
{
	//static menu. same for all airports
	cout << endl << selection->get_location() << ": (enter number)" << endl;
	cout << "1   *depart plane" << endl
		 << "2   *add new plane" << endl
		 << "3   *list planes" << endl;
	cout << endl << "99   *delete this airport" << endl << endl;
}

void build_departure_menu_1(vector<Plane*> planesAtLocation)
{
	//dynamic menu. changes size with number of elements
	cout << endl << "Select Plane to depart: (enter number)" << endl;
	for (int i = 0; i < planesAtLocation.size(); i++)
	{
		cout << i+1 << "    " << planesAtLocation[i]->get_id() << endl;
	}
	cout << endl;
}
void build_departure_menu_2(vector<Airport*> destinationList)
{
	cout << endl << "Select Destination: (enter number)" << endl;
	for (int i = 0; i < destinationList.size(); i++)
	{
		cout << i+1 << "    " << destinationList[i]->get_location() << endl;
	}
	cout << endl;
}

void build_add_plane_to_airport_menu(vector<Plane*> all_planes)
{
	cout << endl << "Select plane to add: (enter number)" << endl;
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
	cout << endl << "Select Plane: (enter number)" << endl;
	cout << "(#)    " << "(MODEL)    " << "(ID)    " << "(LOCN)   " << "(DEST)    " << endl;
	for (int i = 0; i < all_planes.size(); i++)
	{
		cout << i+1 << "   " << all_planes[i]->get_model()
			<< "    " << all_planes[i]->get_id()
			<< "    " << all_planes[i]->get_location()
			<< "    " << all_planes[i]->get_destination()
			<< endl;
			//sub menu of a plane selected will be: set plane ID, add available passengers, remove passengers, or delete plane
	}
	cout << endl << "99   *create new plane" << endl << endl;
}

void build_plane_sub_menu(Plane* selection)
{
	//if plane doesn't have an ID yet then one must be set
	while (!selection->check_id())
	{
		cout << "Enter a new ID for this plane: ";
		string newID;
		cin >> newID;
		selection->set_id(newID);
	}
	//static menu. same for all planes
	if (selection->check_id())
	{
		cout << endl << selection->get_id() << ": (enter number)" << endl;
		cout << "1   *change ID" << endl
			 << "2   *add passengers" << endl
			 << "3   *remove passengers" << endl;
		cout << endl << "99   *delete this plane" << endl << endl;
	}
}

void build_add_plane_menu()
{
	cout << "Choose plane type: " << endl
		 << "1    A320" << endl
		 << "2    B747" << endl;
}


//pilot menus
void build_pilot_menu(vector<Pilot*> all_pilots)
{
	//dynamic menu. changes size with number of elements
	cout << endl << "Select Pilot: (enter number)" << endl;
	for (int i = 0; i < all_pilots.size(); i++)
	{
		cout << i+1 << "   " << all_pilots[i]->get_name()
			<< "   ID number: " << all_pilots[i]->get_id_number() << endl;
	}
	cout << endl << "99   *create new pilot" << endl << endl;
}
