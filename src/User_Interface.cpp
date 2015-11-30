#include "main_menu.hpp"

void initialCritters(std::map<std::string, Critter> *critters) {

	Binary b;
	Critter c;

	//START
	static bool first_run = true;
	if (first_run == true) {	
		for (int i = 0; i < 3; i++){
			std::string generic_name = "Critter_" + std::to_string(i+1);
			(*critters)[generic_name].mutate(0.5+(i*.1));
			c.setName(generic_name);
			(*critters)[generic_name] = c;

		} 
		first_run = false;
	}
	//END
	return;
}

// Main Program Head
int main(){

	// Set up Critter Map
	std::map<std::string, Critter> barnCritters;
	initialCritters(&barnCritters); //Generates 3 initial critters
	std::map<std::string, Critter> showCritters;
	
	// make a list of displays for the critters to be shown in
	// note that it's just a list of names, the program references
	// showCritters whenever it needs to know about a particular
	// critter that is on display.
	std::vector< std::string > displays;
	//Set up Time-Lapse Progress Reports
	Progress_Report A;
	Progress_Report B;
	// keep track of the user's assests
	int numDisplays = 4;
	
	//Prints Welcome
	printWelcome();
	continuePrompt();
	
	//Prints Menu/ Handles Menu Intferface
	bool quit = false; 
	 while(!quit) {
		refreshScreen();
  	 	quit = mainMenu(&barnCritters, &showCritters, &displays, &A, &B, &numDisplays);
 	 }

	return 0;
}


