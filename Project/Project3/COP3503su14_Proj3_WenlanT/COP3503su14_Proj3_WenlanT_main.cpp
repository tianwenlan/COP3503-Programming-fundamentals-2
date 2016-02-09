/* Proj3.cpp
 * Author: Wenlan Tian
 * Date:07-15-2014
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "COP3503su14_Proj3_WenlanT_menuList.h"
#include "COP3503su14_Proj3_WenlanT_main.h"


using namespace std;


//main function

int main(int argc, char *argv []){

	MenuList myMenuList;

	int num =0;
	string inFileName;
	string outFileName;
	string itemName;
	string line1;
	string line2;
	vector<string> inFileNames;

	bool first = true;
	myMenuList.verbose=false;
	myMenuList.silent = false;

	for (int i = 1; i < argc; i++) { 	// parse cmdline args

		if (argv[i][0] == '-'){
			if (argv[i] == SOPT) {
				myMenuList.silent = true;
				myMenuList.verbose = false;
			}else if (argv[i] == VOPT) {
				myMenuList.verbose = true; 
				myMenuList.silent = false;
				verboseOutput();
			}else if (argv[i] == ROPT){
				for (int j=1; j < argc-i;j++){
					if(strcmp(argv[i+j],"-")!=0){
						myMenuList.inputRecipe(argv[i+j]);
					}
				}
			}else if (argv[i] == IOPT){
				for (int j=1; j < argc-i;j++){
					if(strcmp(argv[i+j],"-")!=0){
						myMenuList.inputInventoryFile(argv[i+j]);
					}
				}
			}
		}
	}

	while (1){
		if (myMenuList.verbose&&!first){
			verboseOutput();
		}
		first = false;
		if (!myMenuList.silent){
			cout << "> " << flush;
		}

		cin >> num;

		while (cin.fail()){
        cin.clear();
        cin.ignore();
        cerr << "Not a valid number. Please reenter a number: ";
		cin >> num;
		}

		switch (num) {
			case 0:
				return 0;
			case 1:
				cin.clear();
				cin.ignore();

				cout << "Please enter the recipe file name(s):" << endl;
		
				while(getline(cin,line1)){
					stringstream record(line1);
					while(getline(record,line2,' '))
					inFileNames.push_back(line2);
					break;
				}
				
				for (int i =0; i < inFileNames.size();i++){
					myMenuList.inputRecipe(inFileNames[i]);
				}

				inFileNames.clear();

				break;
  	    	case 2:
				cin.clear();
				cin.ignore();

				cout << "Please enter the inventory file name(s):" << endl;
		
				while(getline(cin,line1)){
					stringstream record(line1);
					while(getline(record,line2,' '))
					inFileNames.push_back(line2);
					break;
				}
				
				for (int i =0; i < inFileNames.size();i++){
					myMenuList.inputInventoryFile(inFileNames[i]);
				}

				inFileNames.clear();

				break;
			case 3:
				myMenuList.subtractInventoryFile(inFileName);
   				break;
			case 4: 
				myMenuList.addRecipe(itemName);
				break;
			case 5:
				myMenuList.removeRecipe(itemName);  
				break;
			case 6:
				myMenuList.reset();
				break;
			case 7:
				myMenuList.outputMenuList(outFileName);
				break;
		    case 8:
				myMenuList.printMenuList();
				break;
    		case 9:
				myMenuList.printRecipeName(itemName);
				break;
			case 10:
				myMenuList.increaseIngredientInventoryItem(itemName);
				break;
			case 11:
				myMenuList.reduceIngredientInventoryItem(itemName);
				break;
			case 12:
				myMenuList.insertEquipmentInventoryItem(itemName);
				break;
			case 13:
				myMenuList.deleteEquipmentInventoryItem(itemName);
				break;
			case 14:
				myMenuList.printIngredientInventory();
				break;
			case 15:
				myMenuList.printEquipmentInventory();
				break;
			case 16:
				myMenuList.printIngredientsList();
				break;
			case 17:
				myMenuList.printIngredientShoppingList();
				break;
			case 18:
				myMenuList.outputIngredientShoppingList(outFileName);
				break;
			case 19:
				myMenuList.printEquipmentList();
				break;
			case 20:
				myMenuList.printEquipmentShoppingList();
				break;
			case 21:
				myMenuList.outputEquipmentShoppingList(outFileName);
				break;
			case 22:
				cout << HELP << endl;
				break;
			default:
				if (!myMenuList.silent){
				cerr << "Invalid command" << endl;
				}
		}			
    }
   return 0;

}
