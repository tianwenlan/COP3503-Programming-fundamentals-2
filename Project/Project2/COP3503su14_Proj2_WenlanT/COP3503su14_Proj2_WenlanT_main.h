#ifndef proj2_main_H
#define proj2_main_H
#include <string>
#include <vector>

using namespace std;

	void verboseOutput();
	void menu();

//case 13: get verbose output
	void verboseOutput(){
		cout << "0 - exit; 1 - input <file>; 2 - union <file>; 3 - subtract <file>;" << endl;
		cout << "4 - difference <file>; 5 - intersect <file>; 6 - reset current set" << endl;
		cout << "7 - write <file>; 8 - print; 9 - find <item>; 10 - insert <item><count>;" << endl;
		cout << "11 - delete <item>; 12 - reduce <item><count>; 13 - verbose; 14 - normal; 15 - silent; 16 - help; 17 - max <file>" << endl;
	}

//case 16: get help information
	const string HELP =
		"=================================================================\n" 
		"Usage: proj2 [-s][-v][-h][-f] <filename>]\n"
		"\t-s: silent mode\n"
		"\t-v: verbose mode\n"
		"\t-h: print this help\n"
		"\t-f <filename>: read <filename> into the current set\n"
		"=================================================================\n"
		"The numbered commands are as follows: \n"
		"0. exit\n"
		"1. input file <filename>: open and read a list from a file to the current multiset\n"
		"2. union file <filename>: open and union a multiset from a file with the current multiset\n"
		"3. subtract file <filename>: open and subtract multiset from a file from the current multiset\n"
		"4. difference file <filename>: open and find the difference between a multiset from a file and the current multiset\n"
		"5. intersect file <filename>: open and find the intersection between a multiset from a file and the current multiset\n"
		"6. reset current set to the empty multiset\n"
		"7. output file <filename>: open and write the current multiset to a file\n"
		"8. print current multiset to the console\n"
		"9. find <item name>: test if <item name> is in the current multiset\n"
		"10. insert <item name><count>: add <item name> to the current multiset with number <count> if <item name> is not in the current multiset, or increase <item name>'s number by <count> if it is\n"
		"11. delete <item name>: remove <item name> from the current multset if it is in it\n"
		"12. reduce <item name><count>: reduce the number of <item name> by <count>\n"
		"13. verbose output\n"
		"14. normal output\n"
		"15. silent output\n"
		"16. help\n"
		"17. max file <filename>:open and find the maximum \n"
		"=================================================================\n";

	const string SOPT = "-s";
	const string VOPT = "-v";
	const string HOPT = "-h";
	const string FOPT = "-f";

#endif
