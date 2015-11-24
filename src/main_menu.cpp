/*
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #11
 *
 * main_menu.cpp - contains implementations for the main menu and related functions
 *
 * Last Modified: November 20, 2015
 * 
 * *****************************************************************************/

#include "main_menu.hpp"

using namespace std;


void print_Critter(){
	
	std::cout << "\x1b[1;33m";
	std::cout << "\t	   		   $$$$$$$$$$$$$$$$$$$$\n";
	std::cout << "\t                       $$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	std::cout << "\t                     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$         $$   $$$$$\n";
	std::cout << "\t     $$$$$$        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$  $$$$$$\n";
	std::cout << "\t $$  $$$$$$      $$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$       $$$$$$$$\n";
	std::cout << "\t  $$ $$$$$$     $$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$    $$$$$$$$\n";
	std::cout << "\t   $$$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$\n";
	std::cout << "\t    $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$     $$$\n";
	std::cout << "\t     $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$$\n";
	std::cout << "\t   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  $$$$$$$$$$$$$$$$$\n";
	std::cout << "\t $$$$$$$$$$$$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$$$$$$$$$$$$$$$$\n";
	std::cout << "\t           $$$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$\n";
 	std::cout << "\t           $$$$$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      $$$$\n";
 	std::cout << "\t             $$$$$     $$$$$$$$$$$$$$$$$$$$$$$$$         $$$\n";
 	std::cout << "\t                $$$$$                                $$$$$\n";
   	std::cout << "\t                 $$$$$$\x1b[1;35m      $$$$$$$$$$$$$$\x1b[1;33m        $$$$$\n";
	std::cout << "\t                   $$$$$$$$\x1b[1;35m     $$$$$$$$$$$$$\x1b[1;33m   $$$$$$$\n";
 	std::cout << "\t                     $$$$$$$$$$$\x1b[1;35m  $$$$$$$$$$$$$\x1b[1;33m$$$$\n";
  	std::cout << "\t                          $$$$$$$$\x1b[1;35m$$$$$$$$$$$$$$\n";
  	std::cout << "\t                                   $$$$$$$$$$$$$$$\n";
     	std::cout << "\t 	                               $$$$$$$$\n\n";
	std::cout << "\x1b[0m";
}

void print_Logo(){
	std::cout << "\x1b[1;34m";
	std::cout << "\t             $$$$$$$$$$      $$$$$$$$$$$$$$\n";
	std::cout << "\t	  $$$$$$$$$$$$$$$    $$$$$$$$$$$$$$$$\n";
	std::cout << "\t        $$$$$$$$     $$$$$$  $$$$$$$      $$$$$\n";
	std::cout << "\t       $$$$$$                $$$$$$$         $$$$$\n";
	std::cout << "\t      $$$$$$$ 	             $$$$$$$         $$$$$\n";
	std::cout << "\t      $$$$$$$                $$$$$$$         $$$$$\n";
	std::cout << "\t      $$$$$$$                $$$$$$$      $$$$$$\n";
	std::cout << "\t      $$$$$$$                $$$$$$$$$$$$$$$$\n";
	std::cout << "\t       $$$$$$$$$     $$$$$$  $$$$$$$$$$$$$$\n";
	std::cout << "\t          $$$$$$$$$$$$$$$    $$$$$$$\n";
	std::cout << "\t             $$$$$$$$$$      $$$$$$$\n";
	std::cout << "\x1b[0m";
}

void print_CritterPark(){
std::cout << "\x1b[1;31m";
std::cout << "\t$$$$$$  $$$$$$  $$$$ $$$$$$ $$$$$$ $$$$$$$ $$$$$$      $$$$$   $$$$  $$$$$   $$  $$   $$ $$ $$\n";
std::cout << "\x1b[1;33m";
std::cout << "\t$$$  $  $$  $$$  $$    $$     $$   $$$     $$  $$$     $$  $$ $$  $$ $$  $$  $$ $$    $$ $$ $$\n";
std::cout << "\x1b[1;31m";
std::cout << "\t$$$     $$$$$$   $$    $$     $$   $$$$$   $$$$$$      $$$$$  $$$$$$ $$$$$   $$$$     $$ $$ $$\n";
std::cout << "\x1b[1;33m";
std::cout << "\t$$$  $  $$  $$   $$    $$     $$   $$$     $$  $$      $$     $$  $$ $$  $$  $$ $$            \n";
std::cout << "\x1b[1;31m";
std::cout << "\t$$$$$$  $$   $$ $$$$   $$     $$   $$$$$$$ $$   $$     $$     $$  $$ $$   $$ $$   $$  $$ $$ $$\n\n";
std::cout << "\x1b[0m";
}

void print_WelcomeTo(){
std::cout << "\x1b[1;31m";
std::cout << "\n";
std::cout << "\t$$       $$ $$$$$$ $$     $$$$$   $$$$$  $$$     $$$ $$$$$$   $$$$$$$$ $$$$$            \n";
std::cout << "\t$$   $   $$ $$     $$    $$    $ $$   $$ $$$$   $$$$ $$          $$   $$   $$           \n";
std::cout << "\t$$  $$$  $$ $$$$$  $$   $$$      $$   $$ $$ $$ $$ $$ $$$$$       $$   $$   $$           \n";
std::cout << "\t$$ $   $ $$ $$     $$    $$    $ $$   $$ $$  $$$  $$ $$          $$   $$   $$           \n";
std::cout << "\t$$$$   $$$$ $$$$$$ $$$$$  $$$$$   $$$$$  $$       $$ $$$$$$      $$    $$$$$   $$ $$ $$ \n\n";
std::cout << "\x1b[0m";
}

void printWelcome(){
	
	print_WelcomeTo();
	print_Critter();
	print_CritterPark();
	
	return;
}

void refreshScreen(){

	cout << "\x1b[?47h"; //Deletes Former Screen Content
	cout << "\x1b[0m"; //Resets Lingering Text Edits

	return;
}

void continuePrompt(){
	
	char continue_prompt;

	do {
		cout << "\n >>> ENTER \"C\" to Continue... <<< \n";
		cout << "Prompt: ";
		cin >> continue_prompt;
			
	} while (continue_prompt != 'c');
}

// Prints list of menu options.
void printMenu(){
	
	cout << "\n**************************************************";
	cout << "****************************\n";
	cout << "\n    CRITTER PARK MENU: \n\n";
	cout << "\t1) Display \"Critter Park\" Player Manual\n";
	cout << "\t2) Critter Park Barn\n";
	cout << "\t3) Critter Park Management\n";
	cout << "\t4) Critter Park Progress Report\n";
	cout << "\t5) About Critter Park - Authors/Game-Info\n";
	cout << "\t6) Leave \"Critter Park\"\n\n";
	cout << "**************************************************";
	cout << "****************************\n";
	cout << "Enter Menu Option: ";
}

//Print the About Us Page
void printAboutUs(){

	cout << "\tCRITTER PARK INFORMATION:\n\n";
	cout << "\tAbout Us:\n";
	cout << "\t\tAuthors: Florian Pontani & Sidney Jackson\n";
	cout << "\t\tContact: flo1@jhu.edu & sjacks85@jhu.edu\n";
	cout << "\t\t   (917) 454-8493 & (386) 956-5577\n";
	cout << "\t\tCompany: JHU-Squid Squad Inc.\n\n";
	
	cout << "\tAbout Critter Park:\n";
	cout << "\t\tProject Details:CS 600.120 - Homework 11.1\n";
	cout << "\t\tLast Modification: November 20, 2015\n";
	cout << "\t\tGame Version: JHU.CS.CP.3.0\n\n";

	cout << "\t\t Our game can best be described as a cross\n"; 
	cout <<	"\t between Jurassic Park and Sims Zoo Tycoon.\n";
	cout << "\t Rather then working with highly unpredictable,\n";
	cout << "\t life threatning creatures of the Jurassic Age,\n";
	cout << "\t however, we're working with extremely genetically\n"; 
	cout << "\t pliable creatures we call \"critters\"!\n";
	cout << "\n Having said that, player's get the chance to breed\n";
	cout << "\n these critters and manage an entire park showing off\n";
	cout << "\n the critter's they breed!\n";

}

//Prints a Border
void printBorder(){
	std::string border(80, '*');	
	cout << border << endl;
}

void borderText(std::string text){
	
	const std::string spaces(text.size(), ' ');
	const std::string second = "////   " + spaces + "   ////";
	const std::string first(second.size(), '/');

	cout << endl;
	cout << first << endl;
	cout << second << endl;
	cout << "////   " + text + "   ////" << endl;
	cout << second << endl;
	cout << first << endl;
	cout << endl;
}

void printManual(){

	cout << "\n\t	*** CRITTER PARK PLAYERS' MANUAL *** \n\n";
	cout << "\t Welcome to Critter Park - A text based game that allows \n";
	cout << "\t you to create, display, and breed critters! \n";
 
	cout << "\n\tWhat are Critters? :";
	cout << "\n\t Critters are a genetically versatile and flexible species, "; 
      	cout << "capable of breeding and \n\t producing new creatures with a wide ";
	cout << "array of characteristics.\n";

	cout << "\n\tHow to Play?\n";
	cout << "\t\t\"Displayed in the main menu are 3 options that\n";	
	cout << "\t allow, you, the player to enter one of three Critter\n";
	cout << "\t areas of the Critter Park Game domains. The first domain\n";
	cout << "\t, option (1), is the Critter Barn where you're able to create\n";
	cout << "\t and breed critters. The second domain, option (2), is where\n";
	cout << "\t you actually manage and alter your Critter Park (Zoo).\n";
	cout << "\t Finally, the third domain, option (3), is the Critter Park\n";
	cout << "\t Progress Report, where you're able to observe the progress of\n";
	cout << "\t and recieve feed back in regards to the success of your park!\n";

        cout << "\n\tCritter Park Main Menu Game Options: \n";
	cout << "\t\t(1) Displays this helpful information\n";
	cout << "\t\t(2) Critter Park Barn\n";
	cout << "\t\t(3) Critter Park Management\n";
	cout << "\t\t(4) Critter Park Progress Report\n";
	cout << "\t\t(5) Display information about the game\n";
	cout << "\t\t(6) Exit the program\n";

	cout << "\n\tTo Learn more about critter park we invite\n";
	cout << "\t you to check out our \"About Us\" Option (5). \n\n";
   }


/********************/

//rename_Critter_Switch_Case(std::string choice){
//} //End of Function

/********************/


// do everything the user wants, given a vector full of critters
bool mainMenu(std::map<std::string, Critter> *critters, Progress_Report *A, Progress_Report *B){ //Start Menu
	
        char menuChoice = 0;
		
	printMenu(); //Prints the Menu

	cin >> menuChoice; //Recieves User Input (Menu Option)
	
	switch (menuChoice) { //Initiates the Menu Switch Case
	
	case '1': 
		{  //Start Switch 1
	 
		printBorder();
		printBorder();
		printManual();
		printBorder();
		printBorder();
		continuePrompt(); 		  
		break;	

		  } //End Switch 1

	case '2': 
		{ //Start Switch 2			
		
		printBorder();
		borderText("CRITTER PARK BARN");
		//cout << "\"Critter Park Barn\" Under Construction!\n";	
		//Prints Menu/ Handles Menu Intferface
		bool quit = false; 
		 while(!quit) {
			refreshScreen();
  	 		quit = barnMenu(critters);
 	 	}	
		continuePrompt();		
		break; //Case 2 Break
		} //End Case 2
	
	case '3': 
		{ //Start Case 3
		
		printBorder();
		borderText("CRITTER PARK MANAGEMENT");
		cout << "\"Critter Park Management\" Under Construction!\n";
		//PLACE CRITTER PARK MANAGEMENT MENU HERE!	
		bool quit = false; 
		 while(!quit) {
			refreshScreen();
  	 		quit = managementMenu(critters);
 	 	}	
		continuePrompt();		
		break; //Case 3 Break
		} //End Case 3
	
	case '4': 
		{ //Start Case 4

		printBorder();
		borderText("CRITTER PARK PROGRESS REPORT");
		cout << "\"Critter Park Progress Report\" Under Construction!\n";
		//PLACE CRITTER PARK PROGRESS REPORT MENU HERE!
		bool quit = false; 
		 while(!quit) {
			refreshScreen();
  	 		quit = progressMenu(A, B);
 	 	}	
		continuePrompt();		
		break; //Case 4 Break
		} //End Case 4
	
	case '5':
		{ //Start Case 5

		printBorder();
		printAboutUs();
		printBorder();
		continuePrompt();	
		break;
		} //End Case 5

	case '6': 	
		{ //Start Case 6
		
		printBorder();
		cout << "\nAre you sure you want to quit? \n";
		
		char response;
		
		cout << "\t\"a\") Continue Playing!\n";
		cout << "\t\"b\") Quit Game...\n\n\n";
		
		cout << "Enter Response: ";
		cin >> response;
		
		switch (response) { //Start Nested Switch 1
			case 'a':{ //Start Case a
				cout << "\nYeah- We figured you'd want to keep playing!\n\n";
			        break;
				 } //End Case A
			case 'b':{ //Start Case B
				
				 printBorder();      	 
       				 cout << "\nAre you absolutely sure you want to quit?\n";
			  	 
				 char response_2;
				  
				 cout << "\t\"}\") Continue Playing!\n";
				 cout << "\t\"`\") Quit Game...\n\n\n";
					
				 cout << "Enter Response: ";
				 cin >> response_2;
	
				switch(response_2) { //Start Nest Switch 2
					case '}':{ //Start Case }
						  cout << "\nYeah- We figured you'd want to keep playing.\n\n";
						  return false;
						  break;
					} //End Case }
					case '`': 
				 		{ //Start Case `
						  printBorder();
      						  cout << "\n\nAlright, if you're sure you want to quit...\n";
						  borderText("COME BACK AGAIN!");
					          return true;
						  break;
						} //End Case `
					default: { 
						 cout << "Invalid Input.\n";
						 return false;
						 break;
						 }
				} //End Nested Switch 2
				} //End Case B
			
			default:{ cout << "Invalid Input.\n";
				 return false;
			}
		
		continuePrompt();

		break; //Break for QUIT switch.
		} //End Nested Switch 1
	} //End Case 8
	
	default:{  cout << "Invalid Input!\n";
		  cin.clear();
		  continuePrompt();
		  return false;
		}

	} //Ends GIANT switch statement.

	return false; //Don't Quit
}


