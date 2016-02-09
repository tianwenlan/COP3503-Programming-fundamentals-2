/* Proj3.cpp
 * Author: Wenlan Tian
 * Date:07-15-2014
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

	class Ingredient{
		public:
		int quantity;
		string unit;
		string foodItem;
	};

	class Recipe{
		public:
		string recipeTitle;
		vector<Ingredient> ingredientsList;
		vector<string> equipmentList;
		Recipe * nextRecipe;

		public:
		Recipe();
		void getRecipeTitle();
		string setRecipeTitle(string);
		void inputRecipe();
		void printRecipe();
		void printIngredientsList();
		void printEquipmentList();
	};
	
	class RecipeCollection{
		public:
		Recipe *recipe;
		vector<string> v;

		public:
		RecipeCollection();
		void inputRecipeCollection();
		void printRecipeCollection();

	};

	class MenuList{
		public:
		vector *recipe;

		public:
		void addRecipe(string);
		void removeRecipe(string); 
		void reset();
		void outputMenu(string);
		void printMenuList();
		void printRecipeName(string);

		MenuList();
	};


	Recipe::Recipe(){
	//	ingredientslist = NULL;
	//	equipmentList = NULL;
	//	vector<Ingredient> ingredientsList;
	//	vector<string> equipmentList;

	}

	RecipeCollection::RecipeCollection(){
		recipe = NULL;
	}
//case 1: empty the current recipe, and fill it with the recipe from a file
//
	void Recipe::inputRecipe(){
//		vector<Ingredient> ingredientsList;
//		vecotr<string> equipmentList;
//
		int i=0;
//		Ingredient ingredient;
		string equipment;

		if(nextRecipe==NULL){
			nextRecipe = new Recipe();
			nextRecipe->recipeTitle="aaa";

//			ingredient.quantity= 3;
//			ingredient.unit= "oze";
//			ingredient.foodItem= "water";
			
//			nextRecipe->ingredientsList.push_back(ingredient);

	//		cout << nextRecipe->ingredientsList[0].quantity << endl;

			nextRecipe->equipmentList.push_back(equipment);
			return;
			delete nextRecipe;
		}else{
			nextRecipe->inputRecipe();
		}
	}

	void RecipeCollection::inputRecipeCollection(){
		int i =0;

		Ingredient ingredient;
		string equipment;

		if(recipe == NULL){
			recipe = new Recipe();
			recipe->recipeTitle="bbb";

			ingredient.quantity= 3;
			ingredient.unit= "oz";
			ingredient.foodItem= "water";

			equipment = "knife";

			recipe->ingredientsList.push_back(ingredient);

	//		cout << "haha" <<recipe->ingredientsList[0].quantity << endl;
	//		cout << "haha" << recipe->ingredientsList[0].unit << endl;


			recipe->equipmentList.push_back(equipment);

//			cout << equipment << endl;

//			cout << "haha" << recipe->equipmentList[0]<< endl;


			delete recipe;
		}else{
			recipe->inputRecipe();
		}
		return;
	}

	void Recipe::printRecipe(){
		if(nextRecipe!=NULL){
			nextRecipe->printRecipe();
		}
				cout << recipeTitle << endl;

	//	cout << nextRecipe->recipeTitle << endl;

//		for (int i =0; i<ingredientsList.size();i++){
//		cout << ingredientsList[i].quantity << " " << flush;
//		cout << ingredientsList[i].unit << " " << flush;
//		cout << ingredientsList[i].foodItem << endl;
//		}

//		for (int i =0; i<equipmentList.size();i++){
//		cout << equipmentList[i] << " " << flush;
//		}

	}

	void RecipeCollection::printRecipeCollection(){
		if(recipe==NULL){
			cout << "Empty Recipe Collection" << endl;
			return;
		}else{
			recipe->printRecipe();
			cout << endl;
			return;
		}
	}
/*
	void RecipeCollection::inputRecipeCollection(string inFileName){

		Recipe recipe;
		Ingredient ingredient;
		Equipment equipment;
	//	vector<Ingredient> ingredientsList;
	//	vector<Equipment> equipmentList;
	//	vector<Recipe> recipeCollection;
		vector<Recipe> recipeCollection;

		ifstream inStream;
		string line1;
		string line2;

		v.clear();

		inStream.open(inFileName.c_str());

		if(inStream.fail()) {
			cerr << "Unable to open file: " << inFileName << endl;
		}
		
		// get next line 
		while(getline(inStream,line1,'<')){

			istringstream record(line1);

			while(getline(record,line2,'>')){ /// how to remove the empty lines??
				while(line2=="title" && line2=="/title")
				recipe->recipeTitle=line2;
				}
		}

		for(int i =0; i<v.size();i++){
			cout << v[i] << endl;
		}
	}

	

		vector<int> index;

		for (int i =0; i<v.size(); i++){
			if((v[i]=="<recipe>")||(v[i]=="</recipe>")){
				index.push_back(i);
			}
		}

		/////Test index[i]

//		for (int i =0; i< index.size();i++){
//			cout << index[i] << endl;
//		}

		for(int i=0; i< index.size();i+=2){

			for (int j= index[i]; j< index[i+1]; j++){

				int	pos1=0;
				int pos2=0;

				if((pos1 = v[j].find("<title>"))!= string::npos){
					pos1 = (v[j].find("<title>")+6);  //locate the location of <name>
					pos2 = v[j].find("</title>");  //locate the location of </name>
					recipe.recipeTitle=(v[j].substr(pos1 + 1, pos2-pos1-1));
					cout <<recipe.recipeTitle << endl;
				}
			

				if((pos1 = v[j].find("<quantity>"))!= string::npos){
					pos1 = (v[j].find("<quantity>")+9);  
					pos2 = v[j].find("</quantity>");  
					ingredient.quantity=stof(v[j].substr(pos1+1,pos2-pos1-1));

			//	cout << ingredient.quantity << endl;
				}

				if((pos1 = v[j].find("<unit>"))!= string::npos){
					pos1 = (v[j].find("<unit>")+5);  
					pos2 = v[j].find("</unit>");  
					ingredient.unit=v[j].substr(pos1+1,pos2-pos1-1);

			//		cout << ingredient.unit << endl;

				}

				if((pos1 = v[j].find("<fooditem>"))!= string::npos){
					pos1 = v[j].find("<fooditem>"+9);  
					pos2 = v[j].find("</fooditem>");
					ingredient.foodItem=v[j].substr(pos1+1,pos2-pos1-1);
					
			//		cout <<	ingredient.foodItem << endl;
					
					ingredientsList.push_back(ingredient);
				}

				if((pos1 = v[j].find("<equipment>"))!= string::npos){
					pos1 = (v[j].find("<equipment>")+10);  
					pos2 = v[j].find("</equipment>");  
					equipment.equipmentItem=v[j].substr(pos1+1,pos2-pos1-1);

		//			cout << equipment.equipmentItem << endl;
			
					equipmentList.push_back(equipment);
				}

			//	recipeColletion.recipeTile.push_back(recipe.recipeTitle);

			//	recipeColletion.ingredientsList.push_back()

			}
		}
	}

//case 16: print ingredients list
	void Recipe::printIngredientsList(){
		for (int i=0; i<ingredientsList.size(); i++){
			cout << ingredientsList[i].quantity << " " << flush;
			cout << ingredientsList[i].unit << " " << flush;
			cout << ingredientsList[i].foodItem << endl;
		}

	}

//case 19: print equipment list
	void Recipe::printEquipmentList(){
		for (int i=0; i<equipmentList.size(); i++){
			cout << equipmentList[i].equipmentItem << endl;
			}

	}


	void unitCoversion(){

	}

*/
int main(){
	RecipeCollection recipeCollection;

	string inFileName;
	cout << "Please enter the file name: " << endl;

	cin >> inFileName;

	recipeCollection.inputRecipeCollection();
//	recipeCollection.printRecipeCollection();
//	recipe.printIngredientsList();
//	recipe.printEquipmentList();

}
