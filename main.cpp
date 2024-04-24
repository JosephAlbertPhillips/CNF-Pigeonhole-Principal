#include <vector>
#include <iostream>
#include <fstream>
#include <string>

// Program to generate the CNF pigeon hole pricipal files

using namespace std;

// This controlls the total amount of pigeons
const int TOTAL_PHP = 10;

string CNF_formula (int pigeons, int holes)
{
		string formula = "";
		int amount_no_hole_gets_two_pigeons = pigeons * (pigeons - 1) / 2;
		string pigeon_gets_holes = "";
		string no_hole_gets_two_pigeons = "";


		formula = string("p cnf ") + to_string(pigeons*holes) + string(" ") 
				+ to_string(pigeons + holes * amount_no_hole_gets_two_pigeons);
		formula += '\n';

//		cout << formula << '\n';

		// This is used to get the statements every pigeon i gets a hole
		for (int i = 0; i < pigeons; i++)
		{
				pigeon_gets_holes = "";

				for (int j = 1; j < holes + 1; j++)
				{
						pigeon_gets_holes += to_string(j + i*holes) + string(" ");
				}
				pigeon_gets_holes += "0";
				formula += pigeon_gets_holes;
				formula += '\n';
//				cout << pigeon_gets_holes << '\n';
		}
		// This is used to get no hole j gets two pigeons
		for (int i = 1; i < holes + 1; i++)
		{
				for (int j = 0; j < pigeons; j++)
				{
						for (int k = j + 1; k < pigeons; k++)
						{
								no_hole_gets_two_pigeons = string("-") + 
										to_string(i+j*holes) + " " +
										string("-") + to_string(i + k * holes) 
										+ string(" ");
						no_hole_gets_two_pigeons += string("0");
						formula += no_hole_gets_two_pigeons;
						formula += '\n';
//						cout << no_hole_gets_two_pigeons << '\n';
						}
				}
		}


		return formula;
}

int main()
{
		// Setting up the variables
		ofstream DIMACS_File;
		string PHP_File = "";
		string STRING = "OKAY!";
		
		for (int holes = 1; holes < TOTAL_PHP; holes++)
		{
				for (int pigeons = holes+1; pigeons < TOTAL_PHP + 1; pigeons++)
				{
						PHP_File = string("Pigeon") + to_string(pigeons) + string("Holes")
							   	+ to_string(holes);
						DIMACS_File.open(PHP_File);
						DIMACS_File << CNF_formula(pigeons, holes);
						DIMACS_File.close();
				}
		}

		return 0;
}
