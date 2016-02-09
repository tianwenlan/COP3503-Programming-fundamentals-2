#ifndef MENULIST_H
#define MENULIST_H

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



#endif
