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

#include "display_menu.hpp"

using namespace std;

// Prints list of menu options.
void printDisplayMenu(){
	
	cout << "\n**************************************************";
	cout << "****************************\n";
	cout << "\n    CRITTER PARK DISPLAY & EXHIBIT MANAGEMENT: \n\n";
	cout << "\t1) Display \"Critter Park Exhibit\" Manual\n";
	cout << "\t2) Display Critters in Barn and On Dislpay\n";
	cout << "\t3) Display Active/Non-Active Displays\n";
	cout << "\t4) Display All Info on Displays\n";
	cout << "\t5) View Critters on Display/ Which Display\n";
	cout << "\t6) Leave \"Critter Park Exhibit Menu\"\n\n";
	cout << "**************************************************";
	cout << "****************************\n";
	cout << "Enter Menu Option: ";
}

void printDisplayManual(){

	cout << "\n\t	*** CRITTER PARK Exhibit MANUAL *** \n\n";
	cout << "\t Welcome to Critter Management\n"; 
	cout << "\n\tHow to Play?\n";

        cout << "\n\tMenu's Critter Park Game Options: \n";
	cout << "\t\t(1) Display this helpful information\n";
	cout << "\t\t(2) Display Critters in Barn and On Dislpay\n";
	cout << "\t\t(3) Display Active/Non-Active Displays\n";
	cout << "\t\t(4) Display All Info on Displays\n";
	cout << "\t\t(5) View Critters on Display/ Which Display\n";
	cout << "\t\t(6) Leave \"Critter Park Exhibit Menu\"\n\n";
   }

//Will need to pass critter map and display map to do anything...
bool displayMenu(){ //Start Menu

	
	case '1': 
		{  //Start Switch 1
	 
		printBorder();
		printBorder();
		printDisplayManual();
		printBorder();
		printBorder();
		continuePrompt(); 		  
		break;	

		  } //End Switch 1
	case '2': 
		{ //Start Switch 2			
		
		printBorder();
		borderText("DISPLAY CRITTERS");
		cout << "\"Display Critters\" Under Construction!\n";
		continuePrompt();		
		break; //Case 2 Break
		} //End Case 2

	
	case '3': 
		{ //Start Switch 3			
		
		printBorder();
		borderText("DISPLAY ACTIVE/NON-ACTIVE DISPLAYS");
		cout << "\"Display ACtive/ Non-active Displays\" Under Construction!\n";
		continuePrompt();		
		break; //Case 3 Break
		} //End Case 3

	case '4': 
		{ //Start Switch 4			
		
		printBorder();
		borderText("DISPLAY EXHIBIT INFO");
		cout << "\"Exhibit Info\" Under Construction!\n";
		continuePrompt();		
		break; //Case 4 Break
		} //End Case 4

	case '5': 
		{ //Start Switch 5		
		
		printBorder();
		borderText("VIEW ON DISPLAY CRITTERS");
		cout << "\"On Display Critters\" Under Construction!\n";
		continuePrompt();		
		break; //Case 5 Break
		} //End Case 5

	case '6': 	
		{ //Start Case 6

		return true;
		continuePrompt();
		break;
		
		} //End Case 6
	
	default:{  cout << "Invalid Input!\n";
		  cin.clear();
		  continuePrompt();
		  return false;
		}
	}  
}	
	return false; //Don't Quit

}
