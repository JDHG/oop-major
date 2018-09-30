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
}

void build_plane_sub_menu(Plane* selection)
{
	//if plane doesn't have an ID yet then one must be set
	if (!selection->check_id())
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
}