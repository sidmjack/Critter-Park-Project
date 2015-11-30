#include "main_menu.hpp"

// Main Program Head
int main(){

	// Set up Critter Map
	std::map<std::string, Critter> barnCritters;
	std::map<std::string, Critter> showCritters;
	
	// make a list of displays for the critters to be shown in
	// note that it's just a list of names, the program references
	// showCritters whenever it needs to know about a particular
	// critter that is on display.
	std::vector< std::string > displays;
	//Set up Time-Lapse Progress Reports
	Progress_Report A;
	Progress_Report B;
	
	//Prints Welcome
	printWelcome();
	continuePrompt();
	
	//Prints Menu/ Handles Menu Intferface
	bool quit = false; 
	 while(!quit) {
		refreshScreen();
  	 	quit = mainMenu(&barnCritters, &showCritters, &displays, &A, &B);
 	 }

	return 0;
}
