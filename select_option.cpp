#include <iostream>
using namespace std;
/*
function checks menu selection input of a menu of n_options choices.
returns an index of (input-1) if input is valid.
eg. If user input '3', this would be element 2 of the choices in the menu (array of choices). hence return (3-1) = 2.
returns -1 if input is invalid (no corresponding element).

used to avoid invalid menu selections from dynamic menus
*/

int select_option(int input, int n_options)
{
	if (input == 99) {return input;} //used for special menu selections not in array/vector options

	int values[n_options];

	//fill array
	for (int i = 0; i < n_options; i++)
	{
		values[i] = i + 1; // 0 is not a valid selection
	}

	//search for valid input comparison
	for (int i = 0; i < n_options; i++)
	{
		if (values[i] == input)
		{
			return (input-1); //valid input found
		}
	}

	//if input is not found in array
	cout << "***failed select_option() checks***" << endl;
	return -1;
}