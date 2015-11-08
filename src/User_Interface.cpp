#include "driver.hpp"

// Main Program Head
int main(){
	
	// Set up Critter Map
	std::map<std::string, Critter> critters;
	
	//Prints Welcome
	printWelcome();
	
	//Prints Menu/ Handles Menu Intferface
	bool quit = false; 
	 while(!quit) {
		refreshScreen();
  	 	quit = menu(&critters);
 	 }

	return 0;
}
