#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//	void verboseOutput();


	void verboseOutput(){
		cout << "0 - exit; 1 - input recipe <filename>; 2 - input inventory <filename>; 3 - subtract inventory file <filename>;" << endl;
		cout << "4 - add <recipe name>; 5 - remove <recipe name>; 6 - reset current menu list" << endl;
		cout << "7 - output menu <filename>; 8 - print current menu list; 9 - print <recipe name>; 10 - increase <ingredient inventory item>;" << endl;
		cout << "11 - reduce <ingredient inventory item>; 12 - insert <equipment item>; 13 - delete <equipment inventory>; " << endl;
		cout << "14 - print ingredient inventory; 15 - print equipemnt inventory; 16 - prient ingredients list; 17 - print ingredient shopping list" << endl;
		cout << "18 - output ingredient shopping list; 19 - print equipemnt list; 20 - print equipment shopping list; 21 - output equipment shopping list; 22 - help" <<endl;
	}


//case 22: get help information
	const string HELP =
		"=================================================================\n" 
		"Usage: proj3 [-s][-v][-r][-i] <filename>]\n"
		"\t-s: silent mode\n"
		"\t-v: verbose mode\n"
		"\t-r <filename>: read recipe <filename> into the current set\n"
		"\t-i <filename>: read inventory <filename> into the current set\n"
		"=================================================================\n"
		"The numbered commands are as follows: \n"
		"0. exit\n"
		"1. input recipe file <filename>: open and read a file containing recipes, storing each recipe as a separate item, named using the title provided in the recipe file\n"
		"2. input inventory file <filename>: open and read a file containing inventory information, combining it with existing inventory information, if any\n"
		"3. subtract inventory file <filename>: open and subtract inventory lists from a file from the current inventory lists\n"
		"4. add <recipe name>: add a recipe from those stored to a current menu list\n"
		"5. remove <recipe name>: remove a recipe from the current menu list\n"
		"6. reset current menu list to the empty set\n"
		"7. output menu <filename>: open and write the current menu to a file in RBML\n"
		"8. print current menu list to the console in formatted plain text\n"
		"9. print <recipe name>: find recipe if stored and print it to the console in formatted plain text\n"
		"10. increase <ingredient inventory item>: add/increase inventory item to the current inventory list\n"
		"11. reduce <ingredient inventory item>: decrease/remove item from the current inventory list\n"
		"12. insert <equipment inventory item>: add inventory item to the current inventory list\n"
		"13. delete <equipment inventory item>: remove inventory item from the current inventory list\n"
		"14. print ingredient inventory: print ingredient inventory to console in formatted plain text\n"
		"15. print equipment inventory: print equipment inventory to console in formatted plain text\n"
		"16. print ingredients list: combine ingredient lists of recipes in current menu and print the combined ingredient list to the console in formatted plain text\n"
		"17. print ingredient shopping list: combine ingredient lists of recipes in current menu, subtract the ingredient inventory list, and print the missing ingredient list to the console in formatted plain text\n"
		"18. output ingredient shopping list <file>:  combine ingredient lists of recipes in current menu, subtract the ingredient inventory list, and store the combined ingredient list to the named file in RBML ingredient list format\n"
		"19. print equipment list: combine equipment lists of recipes in current menu and print the combined equipment list to the console in formatted plain text\n"
		"20. print equipment shopping list: combine equipment lists of recipes in current menu, subtract the equipment inventory list, and print the needed equipment list to the console in formatted plain text\n"
		"21. output equipment shopping list <file>:  combine equipment lists of recipes in current menu, subtract the current equipment inventory list, and store the combined equipment list to the named file in RBML equipment list format\n"
		"22. help\n"
		"=================================================================\n";

	const string SOPT = "-s";
	const string VOPT = "-v";
	const string ROPT = "-r";
	const string IOPT = "-i";

#endif
