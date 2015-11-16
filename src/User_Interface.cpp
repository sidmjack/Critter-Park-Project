#include "main_menu.hpp"

// Main Program Head
int main(){

	// Set up Critter Map
	std::map<std::string, Critter> critters;
	
	//Prints Welcome
	printWelcome();
	continuePrompt();
	
	//Prints Menu/ Handles Menu Intferface
	bool quit = false; 
	 while(!quit) {
		refreshScreen();
  	 	quit = mainMenu(&critters);
 	 }

	return 0;
}
