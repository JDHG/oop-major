#include <stdlib.h>
#include <string>
//#include <iostream>

std::string rng_name()
{
	std::string NAMESLIST[100] = 
	{
		"Michael",
		"Mauro",
		"Hershel",
		"Clarence",
		"Zachary",
		"Robert",
		"Lyle",
		"Reggie",
		"Kip",
		"Jerrold",
		"Bill",
		"Ernest",
		"Jean",
		"Miquel",
		"Cole",
		"Cedrick",
		"Basil",
		"Cornelius",
		"Angel",
		"Clayton",
		"Denis",
		"Von",
		"Allen",
		"Anibal",
		"Werner",
		"Dante",
		"Andrea",
		"Dominic",
		"Derrick",
		"Carlton",
		"Martin",
		"Emmett",
		"Odell",
		"Milo",
		"Shayne",
		"Gavin",
		"Bud",
		"Laverne",
		"Omar",
		"Dave",
		"Bradford",
		"Ed",
		"Chang",
		"Marlon",
		"Brenton",
		"Henry",
		"Johnathon",
		"William",
		"Gilberto",
		"Chase",
		"Kathi",
		"Judie",
		"Kimi",
		"Arlean",
		"Carleen",
		"Deetta",
		"Avis",
		"Ermelinda",
		"Susana",
		"Chu",
		"Kathe",
		"Georgene",
		"Evelynn",
		"Trisha",
		"Sulema",
		"Maxine",
		"Felisa",
		"Francene",
		"Torie",
		"Adriane",
		"Evia",
		"Tai",
		"Shera",
		"Michaele",
		"Liza",
		"Belen",
		"Lakeesha",
		"Denisse",
		"Zofia",
		"Gilda",
		"Latina",
		"Alyssa",
		"Patsy",
		"Kristal",
		"Zonia",
		"Janie",
		"Janis",
		"Elaina",
		"Hae",
		"Loralee",
		"Ranae",
		"Debra",
		"Malika",
		"Fabiola",
		"Mallie",
		"Daphne",
		"Tamika",
		"Noemi",
		"Mildred",
		"Dwennon"
	};
	int n = rand() % 100;
	//std::cout << "n = " << n << " ";
	return NAMESLIST[n];
}