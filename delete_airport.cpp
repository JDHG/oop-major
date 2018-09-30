#include "airport.h"
#include "plane.h"
//#include "b747.h"
//#include "a320.h"
#include <vector>
using namespace std;

//does not currently work
//airport remains in vector after function executes

//must remove location from any planes
bool delete_airport(vector<Airport*> all_airports, int vectorIndex)
{
	vector<Plane*> planes = all_airports[vectorIndex]->get_list_planes();
	for (int i = 0; i < planes.size(); i++)
	{
		planes[i]->remove_location();
	}
	all_airports.erase(all_airports.begin()+vectorIndex);
	//all_airports.erase(vectorIndex);
	return true;
}