#include "main_menu.hpp"

// Main Program Head
int main(){

	// Set up Critter Map
	std::map<std::string, Critter> critters;
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
  	 	quit = mainMenu(&critters, &A, &B);
 	 }

	return 0;
}
