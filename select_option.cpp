/*
function checks menu selection input of a menu of n_options choices.
returns an index of (input-1) if input is valid.
If user input selection 1, this would be element 0 of the choices. hence return input -1.
returns -1 if input is invalid (no corresponding element).

used to pass user selections between menus.
*/

int select_option(int input, int n_options)
{
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
	return -1;
}