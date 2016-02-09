/* Proj3.cpp
 * Author: Wenlan Tian
 * Date:07-15-2014
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>
#include <stdexcept>
#include "tinyxml.h"

using namespace std;

	class Ingredient{
		public:
		float quantity;
		string unit;
		string fooditem;

		public:
		Ingredient();
		Ingredient inputIngredient(TiXmlElement *);

	};

	class Equipment{
		public:
		string equipment;
		int count;

		public:
		Equipment();

	};

	class Recipe{
		public:
		string recipeTitle;
		vector<Ingredient> ingredientsList;
		vector<Equipment> equipmentList;

		public:
		Recipe();
	};
	
	class MenuList{
		public:
		vector <Recipe> recipeCollection;
		vector <Recipe> menuList;
		vector <Ingredient> ingredientInventory;
		vector <Equipment> equipmentInventory;

		int size;

		public:
		void inputRecipe(string);
		void addRecipe(string);
		void removeRecipe(string); 
		void reset();
		void outputMenuList(string);
		void printMenuList();
		void printRecipeName(string);
		void printIngredientsList();
		void printEquipmentList();
		void printIngredientShoppingList();
		void printEquipmentShoppingList();
		void outputIngredientShoppingList(string);
		void outputEquipmentShoppingList(string);
		void inputInventoryFile(string); 
		void subtractInventoryFile(string);
		void increaseIngredientInventoryItem(string); 
		void reduceIngredientInventoryItem(string);
		void insertEquipmentInventoryItem(string);
		void deleteEquipmentInventoryItem(string);
		void printIngredientInventory();
		void printEquipmentInventory();

		MenuList();

		bool verbose;
		bool silent;

	};


	void verboseOutput();
	void menu();

	Ingredient::Ingredient(){
	}
	Equipment::Equipment():count(0){
	}
	Recipe::Recipe(){
	}
	MenuList::MenuList():size(0){
	}


//case 1: empty the current recipe, and fill it with the recipe from a file

	Ingredient Ingredient::inputIngredient(TiXmlElement* ingredientElement){
		Ingredient ingredient;

		TiXmlElement *quantityElement =NULL;
		TiXmlElement *unitElement = NULL;
		TiXmlElement *fooditemElement = NULL;

		if(strcmp(ingredientElement->FirstChild()->Value(),"quantity")==0){
			quantityElement = ingredientElement->FirstChildElement();
			if(strcmp(quantityElement->NextSiblingElement()->Value(),"unit")==0){
				unitElement = quantityElement->NextSiblingElement();
				fooditemElement = unitElement->NextSiblingElement();
			}else{
				fooditemElement = quantityElement->NextSiblingElement();
			}
		}else{
			fooditemElement = ingredientElement->FirstChildElement();
		}

		if (fooditemElement!= NULL){

				if (strcmp(fooditemElement->Value(), "fooditem")==0){
					ingredient.fooditem = fooditemElement->GetText();
				//	cout << ingredient.fooditem << endl;
				}
			
				//get quantity
			try{
				if (strcmp(quantityElement->Value(), "quantity")==0) {
				//	stringstream ss(quantityElement->GetText());
				//	ss >> ingredient.quantity;
					ingredient.quantity = stoi(quantityElement->GetText());

			//		cout << ingredient.quantity  << endl;
				} 
			}catch(runtime_error){
				cerr << "no quantity" << endl;
			}

				//get unit
			try{
				if (strcmp(unitElement->Value(), "unit")==0){
					ingredient.unit = unitElement->GetText();
			//		cout << ingredient.unit << endl;
					}
			} catch(runtime_error){
				cerr << "no unit" ;
			}

					//get Food Item
		}
		return ingredient;
	}



	void MenuList::inputRecipe(string inFileName){
		
			TiXmlDocument doc;

			bool loadOkay = doc.LoadFile(inFileName.c_str());

			if(!loadOkay){
				if(!silent){
					cerr << "File cannot be openned: " << inFileName  << endl;
				}
			}else{

				//define root - recipeCollection
				TiXmlElement *recipeElement = doc.RootElement();
				Recipe recipe;

					//recipe title
					TiXmlElement *titleElement = recipeElement->FirstChildElement();

					TiXmlElement *recipeinfoElement = NULL;
					TiXmlElement * ingredientlistElement = NULL;
					TiXmlElement * servingElement = NULL;
					TiXmlElement * notesElement = NULL;
					TiXmlElement *preparationElement = NULL;
					TiXmlElement *equipmentElement = NULL;

					if(strcmp(recipeElement->Value(),"recipe")!=0){
						cerr << "wrong recipe file: " << inFileName << endl;
					} 


					if(strcmp(titleElement->NextSiblingElement()->Value(),"recipeinfo")==0){
						//recipeinfo
						recipeinfoElement = titleElement->NextSiblingElement();
						//ingredientlist
						ingredientlistElement = recipeinfoElement->NextSiblingElement();
					}else{
						ingredientlistElement = titleElement->NextSiblingElement();
					}

		/*			if(recipeinfoElement){
						TiXmlElement *authorElement = recipeinfoElement->FirstChildElement();
						TiXmlElement *blurbElement = authorElement->NextSiblingElement();
						TiXmlElement *effortElement = blurbElement->NextSiblingElement();
						TiXmlElement *genreElement = effortElement->NextSiblingElement();
						TiXmlElement *preptimeElement =genreElement->NextSiblingElement();
						TiXmlElement *sourceElement = preptimeElement->NextSiblingElement();
						TiXmlElement *yieldElement = preptimeElement->NextSiblingElement();
					}

		*/
					//ingredient
					TiXmlElement *ingredientElement = ingredientlistElement->FirstChildElement();

					//preparation
					preparationElement = ingredientlistElement->NextSiblingElement();

					//equipment
					equipmentElement = preparationElement->FirstChildElement();

					//step
					TiXmlElement *stepElement = equipmentElement->NextSiblingElement();

					//stepequipment
					TiXmlElement *stepEquipmentElement = stepElement->FirstChildElement();

					//Read title
					if(titleElement && (strcmp(titleElement->Value(), "title")== 0)){
						recipe.recipeTitle = titleElement->GetText();
					//	cout << titleElement->GetText() << endl;
					}else{
						cout << "no recipe title" << endl;;
					}

					//Read ingredientList
					while(ingredientlistElement && ingredientElement){
						if(strcmp(ingredientElement->Value(), "ingredient")== 0){
							Ingredient ingredient;
							recipe.ingredientsList.push_back(ingredient.inputIngredient(ingredientElement));
						}else{
							cout << "no ingredient" << endl;
						}
						ingredientElement = ingredientElement->NextSiblingElement();
					}

					//Read equipmentList
					while(preparationElement && equipmentElement){
						if(strcmp(equipmentElement->Value(), "equipment")== 0){
						Equipment equipment;
						equipment.equipment = equipmentElement->GetText();
						equipment.count =1;
						recipe.equipmentList.push_back(equipment);
						//		cout << equipmentElement->GetText() << endl;
						}else{
					//		cout << "no equipment" << endl;
						}
						equipmentElement = equipmentElement->NextSiblingElement();
					}

					//serving
					//notes
					if(preparationElement->NextSiblingElement()){
						if(strcmp(preparationElement->NextSiblingElement()->Value(),"serving")==0){
							servingElement = preparationElement->NextSiblingElement();
							if(strcmp(servingElement->NextSiblingElement()->Value(),"notes")==0){
								notesElement = servingElement->NextSiblingElement();
							}
						}
					}
					
					recipeCollection.push_back(recipe);
					if (!silent){
						cout << "New recipe <" << inFileName << "> loaded" << endl;
				}		
			}
		
	}



//case 4:add a recipe from those stored to a current menu list
	void MenuList::addRecipe(string recipeName){

		cin.clear();
        cin.ignore();

		cout << "Please enter the recipe name to be added:" << endl;

		while(getline(cin, recipeName)){
		
			for (int i =0; i < recipeCollection.size();i++){
				if (recipeCollection[i].recipeTitle == recipeName){
					menuList.push_back(recipeCollection[i]);
					size ++;
					if(!silent){
						cout << "Recipe <" << recipeName << "> has been added to menu list!" << endl;
					}

					return;
				}else{
					if (!silent){
						cerr << "Recipe <" << recipeName << "> is not it current recipe collection!" << endl;
						cout << "Please enter another recipe: " << endl;
					}
				}
			}
		}
	}



//case 5: remove a recipe from the current menu list
	void MenuList::removeRecipe(string recipeName) {

		cin.clear();
		cin.ignore();
		
		cout << "Pleae enter the recipe name to be removed: " << endl;

		while(getline(cin, recipeName)){

			for(int i =0; i< menuList.size();i++){
				if (recipeName == menuList[i].recipeTitle){
					menuList.erase(menuList.begin()+i);
					size --;
					if(!silent){
						cout << "Recipe <" << recipeName << "> has been removed!" << endl;
					}
					return;
				}else if(!silent){
						cerr << "Recipe <" << recipeName << "> is not it current recipe collection!" << endl;
						cout << "Please enter another recipe: " << endl;
				}
			}
		}
	}



//case 6:reset current menu list to the empty set
	
	void MenuList::reset(){
		menuList.clear();
		if (!silent){
			cout << "Reset completed" << endl;
		}
	}


//case 7:open and write the current menu to a file in RBML  
	void MenuList::outputMenuList(string outFileName){
		
		cout << "Please enter the file name to be saved: " << endl;

		cin >> outFileName;

		TiXmlDocument doc;
		TiXmlDeclaration *declaration = new TiXmlDeclaration ("1.0","UTF-8","");
		doc.LinkEndChild(declaration);

		TiXmlComment *comment = new TiXmlComment ("hi, this is a cook book");
		doc.LinkEndChild(comment);

		TiXmlElement * menuListElement = new TiXmlElement("cookbook");
		doc.LinkEndChild(menuListElement);

		for (int i =0; i < menuList.size(); i++){
		
			TiXmlElement * recipeElement = new TiXmlElement("recipe");
			menuListElement->LinkEndChild(recipeElement);

			TiXmlElement * titleElement = new TiXmlElement("title");
			recipeElement->LinkEndChild(titleElement);

			TiXmlText * titleContent = new TiXmlText("Blackeyed Peas");
			titleElement->LinkEndChild(titleContent);	

		
			TiXmlElement * ingredientslistElement = new TiXmlElement("ingreidentslist");
			recipeElement->LinkEndChild(ingredientslistElement);


			for (int j =0; j < menuList[i].ingredientsList.size();j++){

				TiXmlElement * ingredientElement = new TiXmlElement("ingredient");
				ingredientslistElement->LinkEndChild(ingredientElement);
	
				TiXmlElement * quantityElement = new TiXmlElement("quantity");
				ingredientElement->LinkEndChild(quantityElement);

				TiXmlElement * unitElement = new TiXmlElement("unit");
				ingredientElement->LinkEndChild(unitElement);	

				TiXmlElement * fooditemElement = new TiXmlElement("fooditem");
				ingredientElement->LinkEndChild(fooditemElement);

				//content
				TiXmlText * quantityContent = new TiXmlText("menuList[i].ingredientsList[j].quantity.c_str");
				quantityElement->LinkEndChild(quantityContent);	

				TiXmlText * unitContent = new TiXmlText(menuList[i].ingredientsList[j].unit.c_str());
				unitElement->LinkEndChild(unitContent);	

				TiXmlText * fooditemContent = new TiXmlText(menuList[i].ingredientsList[j].fooditem.c_str());
				fooditemElement->LinkEndChild(fooditemContent);

			}


			TiXmlElement * preparationElement = new TiXmlElement("preparation");
			recipeElement->LinkEndChild(preparationElement);

			for (int j =0; j< menuList[i].equipmentList.size();j++){
				TiXmlElement * equipmentElement = new TiXmlElement("equipment");
				preparationElement->LinkEndChild(equipmentElement);

				TiXmlText* equipmentContent = new TiXmlText(menuList[i].equipmentList[j].equipment.c_str());
				equipmentElement->LinkEndChild(equipmentContent);
			}


		}

		doc.Print();
		doc.SaveFile(outFileName.c_str());

		if (!silent){
			cout << "Save to " << outFileName << " completed" << endl;
		}

		return;
	
	} 


//case 8:print current menu list to the console in formatted plain text

	void MenuList::printMenuList(){

		if(!menuList.empty()){

			cout << "current menuList: " << endl;
			for (int i =0; i< size; i++){
				cout << menuList[i].recipeTitle << endl;

				cout << "\tIngredients: " << endl;

				for (int j =0; j< menuList[i].ingredientsList.size();j++){
					cout << "\t\t" <<menuList[i].ingredientsList[j].fooditem << "  " << flush;
					cout << menuList[i].ingredientsList[j].quantity << "  " << flush;
					cout << menuList[i].ingredientsList[j].unit << endl;		
				}

				cout << "\tEquipment: " << endl;

				for (int j =0; j< menuList[i].equipmentList.size();j++){
					cout << "\t\t" <<menuList[i].equipmentList[j].equipment << " " << flush;
					cout <<menuList[i].equipmentList[j].count << " " << endl;

				}
			}
		}else if(!silent){
			cerr << "No recipe in current menu list!" << endl;
		}
	}


//case 9: find recipe if stored and print it to the console in formatted plain text

	void MenuList::printRecipeName(string recipeName){

		cin.clear();
		cin.ignore();

		cout << "Pleae enter the recipe name to be printed: " << endl;


		while(getline(cin, recipeName)){

			for(int i =0; i< size; i++){
				if (menuList[i].recipeTitle == recipeName){
					cout << recipeName << ": " << endl;

					for (int j =0; j< menuList[i].ingredientsList.size();j++){
						cout << "\t\t" <<menuList[i].ingredientsList[j].fooditem << "  " << flush;
						cout << menuList[i].ingredientsList[j].quantity << "  " << flush;
						cout << menuList[i].ingredientsList[j].unit << endl;		
					}

					cout << "\tEquipment: " << endl;

					for (int j =0; j< menuList[i].equipmentList.size();j++){
						cout << "\t\t" <<menuList[i].equipmentList[j].equipment << " " << flush;
						cout << menuList[i].equipmentList[j].count << " " << endl;
					}
					return;
				}else if (!silent){
					cerr << "Recipe <" << recipeName << "> is not it current menu list!" << endl;
					cout << "Please enter another recipe: " << endl;
				}
			}
		}
	}



//case 2: input inventory from a file
	void MenuList::inputInventoryFile(string inFileName){

	  	vector <Ingredient> tempIngredientInventory;
		vector <Equipment> tempEquipmentInventory;

		TiXmlDocument doc;

		bool loadOkay = doc.LoadFile(inFileName.c_str());

		if(!loadOkay){
			cerr << doc.ErrorDesc() << endl;
		}else{

			//define root - recipeCollection
			TiXmlElement *inventoryElement = doc.RootElement();
			Recipe recipe;

			while(inventoryElement){

				//ingredientlist
				TiXmlElement *ingredientlistElement = inventoryElement->FirstChildElement();
				//equipment
				TiXmlElement *equipmentElement = ingredientlistElement->NextSiblingElement();

				//ingredient
				TiXmlElement *ingredientElement = ingredientlistElement->FirstChildElement();
				
				if(strcmp(inventoryElement->Value(),"inventory")!=0){
					if(!silent){
						cerr << "cannot open file: " << inFileName  << endl;
					}					
				} 

				//Read ingredientList
				while(ingredientlistElement && ingredientElement){
					if(strcmp(ingredientElement->Value(), "ingredient")== 0){
						Ingredient ingredient;
						tempIngredientInventory.push_back(ingredient.inputIngredient(ingredientElement));
					}else{
						cerr << "no ingredient" << endl;;
					}
					ingredientElement = ingredientElement->NextSiblingElement();
				}

				//Read equipmentList
				while(equipmentElement){
					if(strcmp(equipmentElement->Value(), "equipment")== 0){
						Equipment equipment;
						equipment.equipment = equipmentElement->GetText();
						equipment.count =1;
						tempEquipmentInventory.push_back(equipment);
				//		cout << equipmentElement->GetText() << endl;
					}else{
						cerr << "no equipment" << endl;
					}
					equipmentElement = equipmentElement->NextSiblingElement();
				}

			break;
			}
		
			//subtract the ingredient inventory list
			for (int i=0; i < tempIngredientInventory.size(); i++){
				for(int j=0; j < ingredientInventory.size() ; j++)
					if(tempIngredientInventory[i].fooditem==ingredientInventory[j].fooditem){
						ingredientInventory[j].quantity=ingredientInventory[i].quantity+tempIngredientInventory[j].quantity;
						if (ingredientInventory[j].unit!=tempIngredientInventory[i].unit){
							ingredientInventory[j].unit=ingredientInventory[j].unit+tempIngredientInventory[i].unit;
						}
						tempIngredientInventory.erase(tempIngredientInventory.begin()+i);
					}		
				}
			}

			for (int i=0; i < tempIngredientInventory.size(); i++){
				ingredientInventory.push_back(tempIngredientInventory[i]);
			}


			for (int i=0; i < tempEquipmentInventory.size(); i++){
				for(int j=0; j < equipmentInventory.size(); j++){
					if(tempEquipmentInventory[i].equipment==equipmentInventory[j].equipment){
						equipmentInventory[j].count=equipmentInventory[j].count+tempEquipmentInventory[i].count;
						tempEquipmentInventory.erase(tempEquipmentInventory.begin()+i);
					}
				}
			}

			for (int i=0; i < tempEquipmentInventory.size(); i++){
				equipmentInventory.push_back(tempEquipmentInventory[i]);
			}
		

			if (!silent){
				cout << "New inventory <<" << inFileName <<"> added" << endl;
			}		
	}


//case 3: open and subtract inventory lists from a file from the current inventory lists
  void 	MenuList::subtractInventoryFile(string inFileName){

		cin.clear();
		cin.ignore();

	  	vector <Ingredient> tempIngredientInventory;
		vector <Equipment> tempEquipmentInventory;

		cout << "Please enter the file name:" << endl;

		cin >> inFileName;

//		while(getline(cin,inFileName)){

		TiXmlDocument doc;

		bool loadOkay = doc.LoadFile(inFileName.c_str());

		if(!loadOkay){
			cerr << doc.ErrorDesc() << endl;
		}else{

			//define root - recipeCollection
			TiXmlElement *inventoryElement = doc.RootElement();
			Recipe recipe;

			while(inventoryElement){

				//ingredientlist
				TiXmlElement *ingredientlistElement = inventoryElement->FirstChildElement();
				//equipment
				TiXmlElement *equipmentElement = ingredientlistElement->NextSiblingElement();

				//ingredient
				TiXmlElement *ingredientElement = ingredientlistElement->FirstChildElement();
				
				if(strcmp(inventoryElement->Value(),"inventory")!=0){
					if(!silent){
						cerr << "cannot open file: " << inFileName  << endl;
					}
				} 

				//Read ingredientList
				while(ingredientlistElement && ingredientElement){
					if(strcmp(ingredientElement->Value(), "ingredient")== 0){
						Ingredient ingredient;
						tempIngredientInventory.push_back(ingredient.inputIngredient(ingredientElement));
						}
					else{
						cout << "no ingredient" << endl;;
					}
					ingredientElement = ingredientElement->NextSiblingElement();
				}

				//Read equipmentList
				while(equipmentElement){
					if(strcmp(equipmentElement->Value(), "equipment")== 0){

						Equipment equipment;
						equipment.equipment = equipmentElement->GetText();
						equipment.count =1;
						tempEquipmentInventory.push_back(equipment);

				//		cout << equipmentElement->GetText() << endl;
					}else{
						cout << "no equipment";
					}
					equipmentElement = equipmentElement->NextSiblingElement();
				}

			break;
			}

			//subtract the ingredient inventory list
			for (int i=0; i < ingredientInventory.size(); i++){
				for(int j=0; j < tempIngredientInventory.size() ; j++)
					if(ingredientInventory[i].fooditem==tempIngredientInventory[j].fooditem){
						if(ingredientInventory[i].quantity-tempIngredientInventory[j].quantity > 0){
							ingredientInventory[i].quantity=ingredientInventory[i].quantity-tempIngredientInventory[j].quantity;
							if(ingredientInventory[i].unit!=tempIngredientInventory[j].unit){
								ingredientInventory[i].unit=ingredientInventory[i].unit+tempIngredientInventory[j].unit;
							}
						}else{
							ingredientInventory.erase(ingredientInventory.begin()+i);
						}
				}
			}

			for (int i=0; i < equipmentInventory.size(); i++){
				for(int j=0; j < tempEquipmentInventory.size(); j++){
					if(equipmentInventory[i].equipment==tempEquipmentInventory[j].equipment){
						if (equipmentInventory[i].count-tempEquipmentInventory[j].count>0){
							equipmentInventory[i].count=equipmentInventory[i].count-tempEquipmentInventory[j].count;
						}else{
							equipmentInventory.erase(equipmentInventory.begin()+i);
						}
					}
				}
			}

			if (!silent){
				cout << "Subtract inventory completed" << endl;
			}

			return;
		}
	}
 

//case 10: increase inventory item to the current inventory list
	void MenuList::increaseIngredientInventoryItem(string ingredientItemName){

		cin.clear();
		cin.ignore();

		cout << "Please enter the <item description> [<quantity>[[<units>]] to be increased" << endl;

		Ingredient ingredient;
		int quantity;
		string units;
		string line;

				
		while(getline(cin,line)){
			istringstream record(line);
			
			record >> ingredientItemName;
			if (line!= ingredientItemName){
				record >> quantity;
				if(record!=' '){
				record >> units;
				}
			}
			

			if (record.fail()) {
				if (line.empty()){
					if (!silent){
						cerr << "No input!" << endl;
						cout << "Please enter the <item description> [<quantity>[[<units>]] to be inserted" << endl;
					}
				} 
				
				continue;
			}
		
				bool found = false;
				for (int i = 0; i < ingredientInventory.size(); i++){
					if (ingredientInventory[i].fooditem == ingredientItemName){
						ingredientInventory[i].quantity = ingredientInventory[i].quantity + quantity;
						if (ingredientInventory[i].unit != units){
							ingredientInventory[i].unit = ingredientInventory[i].unit + units;
						}
						if(!silent){
							cout << "Item <" << ingredientItemName << "> increased to " 
								 << ingredientInventory[i].quantity << " " << ingredientInventory[i].unit << endl;
						}
					found = true;
					}
				}

				if (!found){
					ingredient.fooditem =ingredientItemName;
					ingredient.quantity = quantity;
					ingredient.unit = units;
					ingredientInventory.push_back(ingredient);
					if (!silent){
						cout << "Item <" << ingredientItemName << "> inserted with " << quantity << " " << units << endl;
					}
				}
				return;
			
		}
		return;
		
	}


//case 11: reduce ingredient item from the current inventory list
	void MenuList::reduceIngredientInventoryItem(string ingredientItemName){

		cin.clear();
		cin.ignore();

		cout << "Please enter the <item description> [<quantity>[[<units>]] to be reduced" << endl;


		int quantity;
		string units;

		string input;

		while(getline(cin,input)){
			istringstream record(input);

			record >> ingredientItemName;
			record >> quantity;
			record >> units;


			if (record.fail()) {
				if (input.empty()){
					if (!silent){
						cerr << "No input!" << endl;
						cout << "Please enter the <item name> and <quantity> to be inserted" << endl;
					}
				} 				
				continue;
			}

			bool found = false;
			for (int i = 0; i < ingredientInventory.size(); i++){
				if (ingredientInventory[i].fooditem == ingredientItemName){
					ingredientInventory[i].quantity=ingredientInventory[i].quantity - quantity;
					found = true;
					if (ingredientInventory[i].quantity >0){
						if(!silent){
							cout << "Ingredient Item <" << ingredientItemName << "> reduced to " 
							     << ingredientInventory[i].quantity << " "
								 << ingredientInventory[i].unit << endl;
						}
					}else{
						ingredientInventory.erase(ingredientInventory.begin()+i);
						if(!silent){
							cout << "Ingredient Item <" << ingredientItemName << "> is removed" << endl;
						}
					}
				}
			}

			if ( !found){
				if (!silent){
					cout << "Item <" << ingredientItemName << "> not in current ingredient inventory" << endl;
				}
			}
			return;
			
				ingredientItemName = "";	
		}
	}


//case 12: insert equipment item to the current inventory list
	void MenuList::insertEquipmentInventoryItem(string equipmentItemName){

		cin.clear();
		cin.ignore();

		cout << "Please enter the equipment to be inserted:" << endl;
		
		while(getline(cin,equipmentItemName)){
				Equipment equipment;
				equipment.equipment = equipmentItemName;
				equipment.count = 1;


				bool found = false;
				for (int i = 0; i < equipmentInventory.size(); i++){
					if (equipmentInventory[i].equipment == equipmentItemName){
						{
							equipmentInventory[i].count++;
						}
						if(!silent){
							cerr << "Equipment item <" << equipmentItemName << "> inserted to " << equipmentInventory[i].count << endl;
						}
					found = true;
					}
				}

				if (!found){
					equipmentInventory.push_back(equipment);
					if (!silent){
						cout << "Equipment item <" << equipmentItemName << "> is inserted with count 1." << endl;
					}
				}
			return;
		}
		
	}


//case 13: delete equipment item from the current inventory list
	void MenuList::deleteEquipmentInventoryItem(string equipmentItemName){

		cin.clear();
		cin.ignore();

		cout << "Please enter the equipment to be deleted:" << endl;

		while(getline(cin,equipmentItemName)){

			bool found = false;
			for (int i = 0; i < equipmentInventory.size(); i++){
				if (equipmentInventory[i].equipment == equipmentItemName){
					found = true;
					equipmentInventory.erase(equipmentInventory.begin()+i);
					if(!silent){
						cout << "Equipment item <" << equipmentItemName << "> is deleted" << endl;
					}
				}
			}

			if ( !found){
				if (!silent){
					cerr << "Equipment item <" << equipmentItemName << "> is not in current inventory" << endl;
				}
			}
			return;
		}
	}


//case 14:print ingredient inventory to console in formatted plain text
	void MenuList::printIngredientInventory(){

		cout << "Ingredients:" << endl;
		for (int i = 0; i < ingredientInventory.size(); i++)
		{
			cout << "\t" <<ingredientInventory[i].fooditem << " " << flush;
			cout << ingredientInventory[i].quantity << " " << flush;
			cout << ingredientInventory[i].unit << endl;
		} 
	}


//case 15:print equipment inventory to console in formatted plain text
	void MenuList::printEquipmentInventory(){

		cout << "Equipment:" << endl;
		for (int i = 0; i < equipmentInventory.size(); i++)
		{
			cout << "\t" << equipmentInventory[i].equipment << " " << flush;
			cout << equipmentInventory[i].count << endl;
		} 
	}
	

//case 16: combine ingredient lists of recipes in current menu and print the combined ingredient list
//to the console in formatted plain text


	void MenuList::printIngredientsList(){

		vector<Ingredient> tempIngredientsList;

		//Put all the ingredients into one vector
		for (int i =0; i<size ; i++){
			for (int j =0; j< menuList[i].ingredientsList.size();j++)
			tempIngredientsList.push_back(menuList[i].ingredientsList[j]);
		}

		//combine the duplicated ingredients
		for (int i=0; i < tempIngredientsList.size(); i++){
			for(int j=i+1; j < tempIngredientsList.size(); j++)
				if(tempIngredientsList[i].fooditem==tempIngredientsList[j].fooditem){
					if(tempIngredientsList[i].unit!=tempIngredientsList[j].unit){
						tempIngredientsList[i].quantity+=tempIngredientsList[j].quantity;
						tempIngredientsList[i].unit+=tempIngredientsList[j].unit;
					}else{
						tempIngredientsList[i].quantity+=tempIngredientsList[j].quantity;
					}
					tempIngredientsList.erase(tempIngredientsList.begin()+j);
				}
		}

		for (int i =0; i<tempIngredientsList.size(); i++){
			cout << tempIngredientsList[i].fooditem << " " << flush;
			cout << tempIngredientsList[i].quantity << " " << flush;
			cout << tempIngredientsList[i].unit << endl;
		}
	}


//case 17: combine ingredient lists of recipes in current menu, subtract the ingredient inventory list
//and print the missing ingredient list to the console in formatted plain text
	void MenuList::printIngredientShoppingList(){

		vector<Ingredient> tempIngredientsList;

		//Put all the ingredients into one vector
		for (int i =0; i<size ; i++){
			for (int j =0; j< menuList[i].ingredientsList.size();j++)
			tempIngredientsList.push_back(menuList[i].ingredientsList[j]);
		}

		//combine the duplicated ingredients
		for (int i=0; i < tempIngredientsList.size(); i++){
			for(int j=i+1; j < tempIngredientsList.size(); j++)
				if(tempIngredientsList[i].fooditem==tempIngredientsList[j].fooditem){
					tempIngredientsList[i].quantity+=tempIngredientsList[j].quantity;
					if(tempIngredientsList[i].unit!=tempIngredientsList[j].unit){
						tempIngredientsList[i].unit+=tempIngredientsList[j].unit;
					}
					tempIngredientsList.erase(tempIngredientsList.begin()+j);
				}
		}

		cout << "Ingredient shopping list: " << endl;

		//subtract the ingredient inventory list
		for (int i=0; i < tempIngredientsList.size(); i++){
			for(int j=0; j < ingredientInventory.size(); j++)
				if(tempIngredientsList[i].fooditem==ingredientInventory[j].fooditem){
					if(tempIngredientsList[i].quantity-ingredientInventory[j].quantity > 0){
						tempIngredientsList[i].quantity=tempIngredientsList[i].quantity-ingredientInventory[j].quantity;
						if(tempIngredientsList[i].unit!=tempIngredientsList[j].unit){
							tempIngredientsList[i].unit=tempIngredientsList[i].unit+tempIngredientsList[j].unit;
						}
					}else{
						tempIngredientsList.erase(tempIngredientsList.begin()+i);
					}
				}
		}

		
		//print the missing ingredient list
		for (int i=0; i<tempIngredientsList.size(); i++){
			cout << "\t" << tempIngredientsList[i].fooditem << " " << flush;
			cout << tempIngredientsList[i].quantity << " " << flush;
			cout << tempIngredientsList[i].unit << endl;
		}
	}


//case 18: combine ingredient lists of recipes in current menu, subtract the ingredient inventory list, 
//and store the combined ingredient list to the named file in RBML ingredient list format
	void MenuList::outputIngredientShoppingList(string outFileName){
		
		cout << "Please enter the file name to be saved: " << endl;
		cin >> outFileName;

		vector<Ingredient> tempIngredientsList;

		//Put all the ingredients into one vector
		for (int i =0; i<size ; i++){
			for (int j =0; j< menuList[i].ingredientsList.size();j++)
			tempIngredientsList.push_back(menuList[i].ingredientsList[j]);
		}

		//combine the duplicated ingredients
		for (int i=0; i < tempIngredientsList.size(); i++){
			for(int j=i+1; j < tempIngredientsList.size(); j++)
				if(tempIngredientsList[i].fooditem==tempIngredientsList[j].fooditem){
					tempIngredientsList[i].quantity+=tempIngredientsList[j].quantity;
					if(tempIngredientsList[i].unit!=tempIngredientsList[j].unit){
						tempIngredientsList[i].unit+=tempIngredientsList[j].unit;
					}
					tempIngredientsList.erase(tempIngredientsList.begin()+j);
				}
		}

		//subtract the ingredient inventory list
		for (int i=0; i < tempIngredientsList.size(); i++){
			for(int j=0; j < ingredientInventory.size(); j++)
				if(tempIngredientsList[i].fooditem==ingredientInventory[j].fooditem){
					if(tempIngredientsList[i].quantity-ingredientInventory[j].quantity > 0){
						tempIngredientsList[i].quantity=tempIngredientsList[i].quantity-ingredientInventory[j].quantity;
						if(tempIngredientsList[i].unit!=tempIngredientsList[j].unit){
							tempIngredientsList[i].unit=tempIngredientsList[i].unit+tempIngredientsList[j].unit;
						}
					}else{
						tempIngredientsList.erase(tempIngredientsList.begin()+i);
					}
				}
		}

		TiXmlDocument doc;
		TiXmlDeclaration *declaration = new TiXmlDeclaration ("1.0","UTF-8","");
		doc.LinkEndChild(declaration);

		TiXmlComment *comment = new TiXmlComment ("hi, this is a recipe book");
		doc.LinkEndChild(comment);

		TiXmlElement * ingredientslistElement = new TiXmlElement("ingreidentslist");
		doc.LinkEndChild(ingredientslistElement);	



		for (int i =0; i < tempIngredientsList.size();i++){

			TiXmlElement * ingredientElement = new TiXmlElement("ingredient");
			ingredientslistElement->LinkEndChild(ingredientElement);

	
			TiXmlElement * quantityElement = new TiXmlElement("quantity");
			ingredientElement->LinkEndChild(quantityElement);

			TiXmlElement * unitElement = new TiXmlElement("unit");
			ingredientElement->LinkEndChild(unitElement);	

			TiXmlElement * fooditemElement = new TiXmlElement("fooditem");
			ingredientElement->LinkEndChild(fooditemElement);

			//content
			TiXmlText * quantityContent = new TiXmlText("tempIngredientsList[i].quantity.c_str");
			quantityElement->LinkEndChild(quantityContent);	

			TiXmlText * unitContent = new TiXmlText(tempIngredientsList[i].unit.c_str());
			unitElement->LinkEndChild(unitContent);	

			TiXmlText * fooditemContent = new TiXmlText(tempIngredientsList[i].fooditem.c_str());
			fooditemElement->LinkEndChild(fooditemContent);

		}

		doc.Print();
		doc.SaveFile(outFileName.c_str());

		if (!silent){
			cout << "Save to <" << outFileName << "> completed" << endl;
		}

		return;


	}

	
//case 19: combine equipment lists of recipes in current menu and print the combined equipment list
//to the console in formatted plain text
	void MenuList::printEquipmentList(){
		vector<Equipment> tempEquipmentList;

		//Put all the equipment into one vector
		for (int i =0; i<size ; i++){
			for (int j =0; j< menuList[i].equipmentList.size();j++){
				tempEquipmentList.push_back(menuList[i].equipmentList[j]);
			}
		}

		//combine the duplicated ingredients
		for (int i=0; i < tempEquipmentList.size(); i++){
			for(int j=i+1; j < tempEquipmentList.size(); j++)
				if(tempEquipmentList[i].equipment==tempEquipmentList[j].equipment){
					tempEquipmentList[i].count = tempEquipmentList[i].count + tempEquipmentList[j].count;
					tempEquipmentList.erase(tempEquipmentList.begin()+j);
				}
		}

		for (int i =0; i<tempEquipmentList.size(); i++){
			cout << "\t" << tempEquipmentList[i].equipment << " " << flush;
			cout << tempEquipmentList[i].count << endl;
		}

	}

//case 20:combine equipment lists of recipes in current menu, subtract the equipment inventory list, 
//and print the missing equipment list to the console in formatted plain text
	void MenuList::printEquipmentShoppingList(){

		vector<Equipment> tempEquipmentList;

		//Put all the equipment into one vector
		for (int i =0; i<size ; i++){
			for (int j =0; j< menuList[i].equipmentList.size();j++){
				tempEquipmentList.push_back(menuList[i].equipmentList[j]);
			}
		}

		//combine the duplicated ingredients
		for (int i=0; i < tempEquipmentList.size(); i++){
			for(int j=i+1; j < tempEquipmentList.size(); j++)
				if(tempEquipmentList[i].equipment==tempEquipmentList[j].equipment){
					tempEquipmentList[i].count = tempEquipmentList[i].count + tempEquipmentList[j].count;
					tempEquipmentList.erase(tempEquipmentList.begin()+j);
				}
		}

		cout << "Equipment shopping list: " << endl;

		//subtract the equipment inventory list
		for (int i=0; i < tempEquipmentList.size(); i++){
			for(int j=i+1; j < tempEquipmentList.size(); j++)
				if(tempEquipmentList[i].equipment==tempEquipmentList[j].equipment){
					tempEquipmentList[i].count = tempEquipmentList[i].count + tempEquipmentList[j].count;
					tempEquipmentList.erase(tempEquipmentList.begin()+j);
				}
		}

		for (int i =0; i<tempEquipmentList.size(); i++){
			cout << "\t" << tempEquipmentList[i].equipment << " " << flush;
			cout << tempEquipmentList[i].count << endl;
		}

	}



//case 21: combine equipment lists of recipes in current menu, subtract the ingredient inventory list, 
//and store the combined ingredient list to the named file in RBML ingredient list format

	void MenuList::outputEquipmentShoppingList(string outFileName){
		
		cout << "Please enter the file name to be saved: " << endl;

		cin >> outFileName;

		vector<Equipment> tempEquipmentList;

		//Put all the equipment into one vector
		for (int i =0; i<size ; i++){
			for (int j =0; j< menuList[i].equipmentList.size();j++){
				tempEquipmentList.push_back(menuList[i].equipmentList[j]);
			}
		}

		//combine the duplicated ingredients
		for (int i=0; i < tempEquipmentList.size(); i++){
			for(int j=i+1; j < tempEquipmentList.size(); j++)
				if(tempEquipmentList[i].equipment==tempEquipmentList[j].equipment){
					tempEquipmentList[i].count = tempEquipmentList[i].count + tempEquipmentList[j].count;
					tempEquipmentList.erase(tempEquipmentList.begin()+j);
				}
		}

		//subtract the equipment inventory list
		for (int i=0; i < tempEquipmentList.size(); i++){
			for(int j=i+1; j < tempEquipmentList.size(); j++)
				if(tempEquipmentList[i].equipment==tempEquipmentList[j].equipment){
					tempEquipmentList[i].count = tempEquipmentList[i].count + tempEquipmentList[j].count;
					tempEquipmentList.erase(tempEquipmentList.begin()+j);
				}
		}


		TiXmlDocument doc;
		TiXmlDeclaration *declaration = new TiXmlDeclaration ("1.0","UTF-8","");
		doc.LinkEndChild(declaration);

		TiXmlComment *comment = new TiXmlComment ("hi, this is a recipe book");
		doc.LinkEndChild(comment);

		TiXmlElement *equipmentListElement = new TiXmlElement("equipmentList");
		doc.LinkEndChild(equipmentListElement);


		for (int i =0; i< tempEquipmentList.size();i++){
			TiXmlElement * equipmentElement = new TiXmlElement("equipment");
			equipmentListElement->LinkEndChild(equipmentElement);

			TiXmlText* equipmentContent = new TiXmlText(tempEquipmentList[i].equipment.c_str());
			equipmentElement->LinkEndChild(equipmentContent);
		}
		
		doc.Print();
		doc.SaveFile(outFileName.c_str());

		if (!silent){
			cout << "Save to <" << outFileName << "> completed" << endl;
		}

		return;
	}


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


	void menu(){
		cout << "0=exit, 1=input file, 2=union file, 3=subtract file, 4=difference file, 5=intersect file," << endl;
		cout << "6=reset, 7=save, 8=print, 9=find item, 10=insert item count, 11=delete item," << endl;
		cout << "12=reduce item count, 13=verbose, 14=normal, 15=silent, 16=help" << endl;
	}


//main function

int main(int argc, char *argv []){

	int num =0;

	string inFileName;
	string outFileName;
	string itemName;
	MenuList menuList;
	string line1;
	string line2;
	vector<string> inFileNames;

   
	bool first = true;
	menuList.verbose=false;
	menuList.verbose=false;


	for (int i = 1; i < argc; i++) { 	// parse cmdline args

		if (argv[i][0] == '-'){
			if (argv[i] == SOPT) {
				menuList.silent = true;
				menuList.verbose = false;
			}else if (argv[i] == VOPT) {
				menuList.verbose = true; 
				menuList.silent = false;
				verboseOutput();
			}else if (argv[i] == ROPT){
				for (int j=1; j < argc-i;j++){
					if(strcmp(argv[i+j],"-")!=0){
						menuList.inputRecipe(argv[i+j]);
					}
				}
			}else if (argv[i] == IOPT){
				for (int j=1; j < argc-i;j++){
					if(strcmp(argv[i+j],"-")!=0){
						menuList.inputInventoryFile(argv[i+j]);
					}
				}
			}
		}
	}

	while (1){
		if (menuList.verbose&&!first){
			verboseOutput();
		}
		first = false;
		if (!menuList.silent){
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
					menuList.inputRecipe(inFileNames[i]);
				}

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
					menuList.inputInventoryFile(inFileNames[i]);
				}

				break;
			case 3:
				menuList.subtractInventoryFile(inFileName);
   				break;
			case 4: 
				menuList.addRecipe(itemName);
				break;
			case 5:
				menuList.removeRecipe(itemName);  
				break;
			case 6:
				menuList.reset();
				break;
			case 7:
				menuList.outputMenuList(outFileName);
				break;
		    case 8:
				menuList.printMenuList();
				break;
    		case 9:
				menuList.printRecipeName(itemName);
				break;
			case 10:
				menuList.increaseIngredientInventoryItem(itemName);
				break;
			case 11:
				menuList.reduceIngredientInventoryItem(itemName);
				break;
			case 12:
				menuList.insertEquipmentInventoryItem(itemName);
				break;
			case 13:
				menuList.deleteEquipmentInventoryItem(itemName);
				break;
			case 14:
				menuList.printIngredientInventory();
				break;
			case 15:
				menuList.printEquipmentInventory();
				break;
			case 16:
				menuList.printIngredientsList();
				break;
			case 17:
				menuList.printIngredientShoppingList();
				break;
			case 18:
				menuList.outputIngredientShoppingList(outFileName);
				break;
			case 19:
				menuList.printEquipmentList();
				break;
			case 20:
				menuList.printEquipmentShoppingList();
				break;
			case 21:
				menuList.outputEquipmentShoppingList(outFileName);
				break;
			case 22:
				cout << HELP << endl;
				break;
			default:
				if (!menuList.silent){
				cerr << "Invalid command" << endl;
				}
		}			
    }
   return 0;

}
