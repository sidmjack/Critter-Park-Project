/*
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #11 
 *
 * Last Modified: November 20, 2015
 * 
 * *****************************************************************************/

#include "time_lapse_menu.hpp"
#include "progressReport.hpp"

using namespace std;

// Prints list of menu options.
void printProgressMenu(){
	
	cout << "\n**************************************************";
	cout << "****************************\n";
	cout << "\n    CRITTER PARK PROGRESS REPORT: \n\n";
	cout << "\t1) Display \"Critter Park Progress Report\" Manual\n";
	cout << "\t2) Initiate Time-Lapse\n";
	cout << "\t3) View Progress Report\n";
	cout << "\t4) Leave \"Critter Park Progress Report Menu\"\n\n";
	cout << "**************************************************";
	cout << "****************************\n";
	cout << "Enter Menu Option: ";
}

void printProgressManual(){

	cout << "\n\t	*** CRITTER PARK MANAGEMENT MANUAL *** \n\n";
	cout << "\t Welcome to Critter Management\n"; 
	cout << "\n\tHow to Play?\n";

        cout << "\n\tMenu's Critter Park Game Options: \n";
	cout << "\t\t(1) Display this helpful information\n";
	cout << "\t\t(2) Initiate Time-Lapse\n";
	cout << "\t\t(3) View Progress Report\n";
	cout << "\t\t(4) Leave \"Critter Park Progress Report Menu\"\n\n";
   }

//Will need to pass critter map and display map to do anything...
bool progressMenu(Progress_Report *A, Progress_Report *B){ //Start Menu

	char menuChoice = 0;
		
	printProgressMenu(); //Prints the Menu

	cin >> menuChoice; //Recieves User Input (Menu Option)
	
	switch (menuChoice) { //Initiates the Menu Switch Case
	
	case '1': 
		{  //Start Switch 1
	 
		printBorder();
		printBorder();
		printProgressManual();
		printBorder();
		printBorder();
		continuePrompt(); 		  
		break;	

		  } //End Switch 1
	case '2': 
		{ //Start Switch 2			
		
		printBorder();
		borderText("INITIATE TIME LAPSE");
		Progress_Report::simulateWeek(A, B);
		cout << "Timelapse successfully run!\n";
		cout << "One Week has passed since your last Critter Park Modifications were made...\n";
		cout << "Check the Critter Park Progress Report to view your park's statistics.\n";
		continuePrompt();		
		break; //Case 2 Break
		} //End Case 2

	
	case '3': 
		{ //Start Switch 3			
		
		printBorder();
		borderText("View Progress Report");
		//cout << "\"Progress Report\" Under Construction!\n";
		Progress_Report::reload(A, B);	
		Progress_Report::printReport(*A, *B);
	
		continuePrompt();		
		break; //Case 3 Break
		} //End Case 3

	case '4': 	
		{ //Start Case 4

		return true;
		continuePrompt();
		break;
		
		} //End Case 4
	
	default:{  cout << "Invalid Input!\n";
		  cin.clear();
		  continuePrompt();
		  return false;
		}

		return false; //Just in Case

	}  //End Switch Statements
	
	return false; //Don't Quit, Just in Case
}
