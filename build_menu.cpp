#include "airport.h"
#include "person.h"
#include "pilot.h"
#include "plane.h"
#include "b747.h"
#include "a320.h"
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
}

void build_airport_sub_menu(Airport* selection)
{
	//static menu. same for all elements
	cout << endl << selection->get_location() << ": (enter a number)" << endl;
	

}


//plane menus
void build_plane_menu(vector<Plane*> all_planes)
{
	//dynamic menu. changes size with number of elements
	cout << endl << "Select Plane: (enter number)" << endl;
	for (int i = 0; i < all_planes.size(); i++)
	{
		cout << i+1 << "   " << all_planes[i]->get_model()
			<< "    " << all_planes[i]->get_id() << endl;
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