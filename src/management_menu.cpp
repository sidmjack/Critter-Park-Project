/*
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #11
 *
 *  
 * Last Modified: November 20, 2015
 * 
 * *****************************************************************************/


#include "management_menu.hpp"

using namespace std;

// Prints list of menu options.
void printManagementMenu(){
	
	cout << "\n**************************************************";
	cout << "****************************\n";
	cout << "\n    CRITTER PARK MANAGEMENT MENU: \n\n";
	cout << "\t1) Display \"Critter Park Management\" Manual\n";
	cout << "\t2) View Current Park Management Report\n";
	cout << "\t3) Manage Displays/Critter Park Exhibits\n";
	cout << "\t4) Manage Critter Park Investement/ Black Market\n";
	cout << "\t5) Leave \"Critter Park\"\n\n";
	cout << "**************************************************";
	cout << "****************************\n";
	cout << "Enter Menu Option: ";
}

void printManagementManual(){

	cout << "\n\t	*** CRITTER PARK MANAGEMENT MANUAL *** \n\n";
	cout << "\t Welcome to Critter Management\n"; 
	cout << "\n\tHow to Play?\n";

        cout << "\n\tMenu's Critter Park Game Options: \n";
	cout << "\t\t(1) Display this helpful information\n";
	cout << "\t\t(2) View Current Park Management Report\n";
	cout << "\t\t(3) Manage Displays/Critter Park Exhibits\n";
	cout << "\t\t(4) Manage Critter Park Investement/ Black Market\n";
	cout << "\t\t(5) Exit Management Domain\n";
   }

//Will need to pass critter map and display map to do anything...
bool managementMenu(std::map<std::string, Critter> *critters){ //Start Menu

	char menuChoice = 0;
		
	printManagementMenu(); //Prints the Menu

	cin >> menuChoice; //Recieves User Input (Menu Option)
	
	switch (menuChoice) { //Initiates the Menu Switch Case
	

	case '1': 
		{  //Start Switch 1
	 
		printBorder();
		printBorder();
		printManagementManual();
		printBorder();
		printBorder();
		continuePrompt(); 		  
		break;	

		  } //End Switch 1
	case '2': 
		{ //Start Switch 2			
		
		printBorder();
		borderText("VIEW CRITTER PARK MANAGEMENT REPORT");
		cout << "\"Critter Park Management Report\" Under Construction!\n";
		continuePrompt();		
		break; //Case 2 Break
		} //End Case 2

	case '3': 
		{ //Start Switch 3			
		
		printBorder();
		borderText("MANAGE DISPLAYS/CRITTER PARK EXHIBITS");
		cout << "\"Critter Park Displays/Exhibits\" Under Construction!\n";
		continuePrompt();		
		break; //Case 3 Break
		} //End Case 3

	
	case '4': 
		{ //Start Switch 4			
		
		printBorder();
		borderText("MANAGE CRITTER PARK INVESTMENTS/ BLACK MARKET");
		cout << "\"Critter Park Investments/Black Market\" Under Construction!\n";
		continuePrompt();		
		break; //Case 4 Break
		} //End Case 4

	case '5': 	
		{ //Start Case 5

		return true;
		continuePrompt();
		break;
		
		} //End Case 5
	
	default:{  cout << "Invalid Input!\n";
		  cin.clear();
		  continuePrompt();
		  return false;
		}

		return false; //Just in Case
	}  	

	return false; //Don't Quit, Just in Case
}
