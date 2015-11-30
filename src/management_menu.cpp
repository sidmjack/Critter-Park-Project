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
#include "progressReport.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_DISPLAYS 8

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
	cout << "\t5) Set Price of Critter Park Admission/Ticket\n"; 
	cout << "\t6) Sell Critter Park Creature\n";
	cout << "\t7) Leave \"Critter Park Management\"\n\n";
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
	cout << "\t\t(5) Set Price of Critter Park Admission/Ticket\n"; 
	cout << "\t\t(6) Sell Critter Park Creature\n";
	cout << "\t\t(7) Exit Management Domain\n";
   }

void printManagementReport(Progress_Report *A){
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	std::cout << "\t\tCritter Park Management Report: \n";
	std::cout << "CUSTOMER SATISFACTION: \n";
	std::cout << "\tCritter Park Reputation: " <<  A->parkReputation << "\n";
	std::cout << "\tVisitor Numbers: " << A->totalVisitors << "\n";
	std::cout << "FISCAL MATTERS: \n";
	std::cout << "\tInitial Park Balance: $" << A->initialParkBalance << "\n";
	std::cout << "\tCritter Park Investments $: " << A->parkInvestments << "\n";
	std::cout << "\tCurrent Balance: $" << A->resultingBalance << "\n";
	std::cout << "\tTicket Price: $" << A->ticketPrice << "\n";
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	return;
}

void printInvestmentOptions(){
	std::cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	std::cout << "1) Market Strategy (Advertise Cute Critters)\n";
	std::cout << "2) Market Strategy (Advertise Scary Critters)\n";
	std::cout << "3) Market Strategy (Advertise Strange Critters\n";
	std::cout << "4) Market Strategy (Advertise CRITTER PARK)\n";
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
}

void printBlackMarketOptions(){
	std::cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	std::cout << "1) Purchase Cute, Radioactive Critter developed in a Cotton Factory.\n";
	std::cout << "2) Purchase Scary Critter from failed Area 51 Government Project\n";
	std::cout << "3) Purchase Strange Critter from an under ground JHU Research Facility\n";
	std::cout << "4) Hire Fake Visitors/Bloggers to bump up Critter Parks Ratings\n";
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";

	

}

void printDisplayList(std::map<std::string, Critter> *barnCritters, std::vector<std::string> *displays){
  printBorder();
  //print the disply critters and barn critters
  std::cout << "\nCritters currently in the Barn:\n";
  std::cout << "---------------------------------\n";
  
  //list the barn critters
  int counter = 1;
  for(std::map<std::string, Critter>::iterator i = barnCritters->begin(); i != barnCritters->end(); i++){
      std::cout << "\t";
      if(counter < 10){
	std::cout << " ";
      }
  std::cout<<counter<<" -- "<< i->second.getName() << "\n";
  counter++;
  }
  std::cout << "\n";
  counter = 1;
  
  
  // then print the ones on display
  std::cout << "\nCritters currently on display:\n";
  std::cout << "--------------------------------\n";
  for(int i = 0; i < displays->size(); i++){
    std::cout << "\t";
    if(counter < 10){
     std::cout << " ";
    }
    std::cout<<counter<<" -- "<< displays->at(i) << "\n";
    counter++;
  }
  std::cout << "\n";

}

//Randomized function use
void negativePublicity(Progress_Report *A){
	int random;
	srand(time(NULL));
	random = ((rand()%100)+1);
	if (random > 0 && random < 25){
		A->parkReputation-= random*1.5;
		A->maintenanceFees+= random*1500;
		std::cout << "#######################################################\n";
		std::cout << "You were caught! Critter Parks Reputation\n";
		std::cout << "suffers from harsh, negative publicity and mandates\n";
		std::cout << "fiscal reparations to recover from the damage to its image.\n";
		std::cout << "#######################################################\n";
		return;
	} else {
		return;
	}
}

//Will need to pass critter map and display map to do anything...
bool managementMenu(std::map<std::string, Critter> *barnCritters, std::map<std::string, Critter> *showCritters, std::vector<std::string> *displays, Progress_Report *A, Progress_Report *B){ //Start Menu

    
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
		printManagementReport(A);
		continuePrompt();		
		break; //Case 2 Break
		} //End Case 2

	case '3': 
		{ //Start Switch 3			
		
		printBorder();
		borderText("MANAGE DISPLAYS/CRITTER PARK EXHIBITS");
		//cout << "\"Critter Park Displays/Exhibits\" Under Construction!\n";
		printDisplayList(barnCritters, displays);
		cout << "\na) move critter [name] from BARN to DISPLAY\n";
		cout << "b) move critter [name] from DISPLAY to BARN\n";
		cout << "Enter choice: ";
		std::string toMove = "";
		char mvOption = ' ';
		cin >> mvOption;
		
		switch(mvOption){
		  case 'a':
		  {
		    cout << "\nMOVE CRITTER FROM BARN TO DISPLAY\n\nwhich critter do you want to move?\n\n";
		    cin >> toMove;
		    //see if the user picked a barn critter
		    auto itt = barnCritters->find(toMove);
		    if(itt == barnCritters->end()){
		      cout << "\nSorry, that Critter couldn't be found in the Barn.";
		      break;
		    }
		    // otherwise, see if there is display space left
		    if(!(showCritters->size() < MAX_DISPLAYS) ){
		      cout << "\nSorry, you haven't any space left in your displays!\n";
		      break;
		    }
		    // if nothing's ammiss, transfer the critter to the nearest open display
		    (*showCritters)[toMove] = (*barnCritters)[toMove];
		    barnCritters->erase(toMove);
		    
		    displays->push_back(toMove);
		    cout << "\n\nSucessfully put \"" << toMove << "\" on display.\n";
		    break;
		    
		  }//end barn-to-display move
		  
		  case 'b':
		  {
		   cout << "\nMOVE CRITTER FROM DISPLAY TO BARN\n\nwhich critter do you want to move?\n\n";
		    cin >> toMove;
		    //see if the user picked a display critter
		    auto itt = showCritters->find(toMove);
		    if(itt == showCritters->end()){
		      cout << "\nSorry, that Critter couldn't be found in the displays.";
		      break;
		    }
		    // if nothing's ammiss, transfer the critter the display to the barn
		    (*barnCritters)[toMove] = (*showCritters)[toMove];
		    showCritters->erase(toMove);
		    
		    // find and delete a critter with the given name
		    for(int i = 0; i < displays->size(); i++){
		      if( displays->at(i) == toMove ){
			displays->erase(displays->begin() + i);
			break;
		      }
		    }
		    cout << "\n\nSucessfully returned \"" << toMove << "\" to the Barn.\n";
		    break;
		  }
		  
		}//end mvOption switch
		
		A->maintenanceFees += ((barnCritters->size()+showCritters->size())*250);
		continuePrompt();		
		break; //Case 3 Break
		} //End Case 3

	
	case '4': 
		{ //Start Switch 4				
		printBorder();
		borderText("MANAGE CRITTER PARK INVESTMENTS/ BLACK MARKET");
		cout << "Select how you'd like to invest in Critter Park.\n";
		cout << "\ta) Would you like to look into investing in Critter Park?\n";
		cout << "\tb) OR! Would you rather divert your attention toward the Critter Black Market?\n";
		cout << "\t\t[Don't get caught!]\n";
		cout << "Enter Menu Option Here: ";
		
		char menuOption = ' ';
		cin >> menuOption; //Recieves User Input (Menu Option)
	
			switch (menuOption) { //Initiates the Menu Switch Case
			
				case 'a':{
				 	printInvestmentOptions();

					char a_option = ' ';
					cin >> a_option;

					switch (a_option) { //Initiates Option_A Switch Case
						
						double investment_cost;

						case '1': {
							//Determines the Cost to Advertise...	  
							investment_cost = (A->cuteRep)*5000;
							//Determines whether the Player Can Afford to Invest.
							if (investment_cost > A->initialParkBalance || A->parkInvestments> A->initialParkBalance){
							    std::cout << "Critter Park Can't Afford this right now!\n";
								break;
							}
							//Adds the Cost of the Investment
							A->parkInvestments += investment_cost;
							//Increases the Parks "Cute"Reputation
							A->cuteRep += 5;
							std::cout << "Critter Park CUTE Reputation successfully bulstered!\n";

							break;
							  }
		
						case '2': {
							//Determines the Cost to Advertise...	  
							investment_cost = (A->scaryRep)*5000;
							//Determines whether the Player Can Afford to Invest.
							if (investment_cost > A->initialParkBalance || A->parkInvestments> A->initialParkBalance){
							    std::cout << "Critter Park Can't Afford this right now!\n";
								break;
							}
							//Adds the Cost of the Investment
							A->parkInvestments += investment_cost;
							//Increases the Parks "Cute"Reputation
							A->scaryRep += 5;
							std::cout << "Critter Park SCARY Reputation successfully bulstered!\n";
	  
								  break;
							  }
						case '3': {
							//Determines the Cost to Advertise...	  
							investment_cost = (A->strangeRep)*5000;
							//Determines whether the Player Can Afford to Invest.
							if (investment_cost > A->initialParkBalance || A->parkInvestments> A->initialParkBalance){
							    std::cout << "Critter Park Can't Afford this right now!\n";
								break;
							}
							//Adds the Cost of the Investment
							A->parkInvestments += investment_cost;
							//Increases the Parks "Cute"Reputation
							A->strangeRep += 5;
							std::cout << "Critter Park STRANGE Reputation successfully bulstered!\n";

								  break;
							  }
						case '4': {
								//Determines the Cost to Advertise...	  
							investment_cost = (A->parkReputation)*5000;
							//Determines whether the Player Can Afford to Invest.
							if (investment_cost > A->initialParkBalance || A->parkInvestments> A->initialParkBalance){
							    std::cout << "Critter Park Can't Afford this right now!\n";
								break;
							}
							//Adds the Cost of the Investment
							A->parkInvestments += investment_cost;
							//Increases the Parks "Cute"Reputation
							A->parkReputation += 2;
							std::cout << "CRITTER PARK Reputation successfully bulstered!\n";

								  break;
							  }
						default: {
								cout << "Invalid Input!\n";
		  						cin.clear();
		  						continuePrompt();
				       				break;
	 						 }
					} //End of Option_A Switch Case

				 	break;
				 } //End Case A
			
				case 'b':{
				  
					printBlackMarketOptions();
				  
					char b_option = ' ';
					cin >> b_option;
					
					//Stuff that may need to be moved...
					Binary B; //Binary just cause
					Critter C; //General Purpose Critter

					switch (b_option) { //Initiates Option_B Switch Case
						
						double investment_cost;
					
						case '1': {
							investment_cost = 75000;
							if (investment_cost > A->initialParkBalance || A->parkInvestments> A->initialParkBalance){
							    std::cout << "Critter Park Can't Afford this right now!\n";
							    //messageBox("Critter Park can't afford to invest in that right now!","You're Broke!");
								break;
							}
							//Critter Added Here!
							std::string name = "PuffBall";
							C.setName(name);
							(*barnCritters)[name] = C;
							(*barnCritters)[name].engineer(945408);				
							std::cout << "~Mutant Cotton-Ball Critter: ACQUIRED~\n";

							break;
							  }
						
						case '2': {
							investment_cost = 75000;
							if (investment_cost > A->initialParkBalance || A->parkInvestments> A->initialParkBalance){
							    std::cout << "Critter Park Can't Afford this right now!\n";
								break;
							}
							//Critter Added Here!
							std::string name = "MartianBob";
							C.setName(name);
							(*barnCritters)[name] = C;
							(*barnCritters)[name].engineer(393433);	
							std::cout << "~Area 51 Critter Martian: ACQUIRED~\n";
							break;
							  }
						
						case '3': {
							investment_cost = 80000;
							if (investment_cost > A->initialParkBalance || A->parkInvestments> A->initialParkBalance){
							    std::cout << "Critter Park Can't Afford this right now!\n";
								break;
							}
							//Critter Added Here!
							std::string name = "LabRat";
							C.setName(name);
							(*barnCritters)[name] = C;
							(*barnCritters)[name].engineer(260990);	
							std::cout << "~John Hopkins Bio-engineered Critter, ACQUIRED~\n";
							break;
							  }
						
						case '4': {
									//Determines the Cost to Advertise...	  
							investment_cost = (A->parkReputation)*2500;
							//Determines whether the Player Can Afford to Invest.
							if (investment_cost > A->initialParkBalance || A->parkInvestments> A->initialParkBalance){
							    std::cout << "Critter Park Can't Afford this right now!\n";
								break;
							}
							//Adds the Cost of the Investment
							A->parkInvestments += investment_cost;
							//Increases the Parks "Cute"Reputation
							A->parkReputation += 2;
							std::cout << "CRITTER PARK Reputation successfully bulstered!\n";

							 	  break;
							  }
						default: {
								cout << "Invalid Input!\n";
		  						cin.clear();
		  						continuePrompt();
				       				break;
	 						 }
					} //End of Option_B Switch Case

					negativePublicity(A);
				 	break;
				 } //End Case B
			
				default:{
					cout << "Invalid Input!\n";
		  			cin.clear();
		  			continuePrompt();
					break;
		  		} //End of Default
			} //End of First Nested Loop	
		
		continuePrompt();		
		break; //Case 4 Break
		} //End Case 4

	case '5': 
		{ //Start Switch 5			
		
		printBorder();
		borderText("SET CRITTER PARK TICKET FEE");
		cout << "Enter your desired price of admission into Critter Park.\n";
		cout << "[MAX ADMISSION PRICE IS $100.00!]\n";
		cout << "Cost of Admission: ";
		double cost_of_admission;
		cin >> cost_of_admission;
		while (cost_of_admission < 0 || cost_of_admission > 100.00){
			cout << "Not a valid admission price!\n";
			cout << "Cost of Admission: ";
			cin >> cost_of_admission;
		}
		Progress_Report::setTicketPrice(cost_of_admission, A);
		cout << "Ticket Price successfully set to $" << cost_of_admission << "!\n";
		continuePrompt();		
		break; //Case 5 Break
		} //End Case 5


	case '6':
		{//Start Case 6
		printBorder();
		borderText("SELL CRITTER");
		
		std::string name_k;

		// if there aren't any critters left, say so
		if(barnCritters->size() == 0){
			cout << "There aren't any Critters left in the barn to sell!\n";
			continuePrompt();
			break;
		}
		
		cout << "Enter the name of the critter you'd like to sell from the barn.\n";	
		cout << "Name of Critter: ";
		cin >> name_k;

		//see if this critter is real
		/*it = critters->find(name_k);
		if(it == critters->end()){
			cout << "I couldn't find a critter called \'"<<name_k<<"\'."<<endl;
			break;
		}*/
		
		int best_feature = 0;
		int feature = 0;
		double critters_value = 0;

		for (int i = 0; i < 3; i++){
			feature = (*barnCritters)[name_k].getTraitScores().at(i); 
			if (feature > best_feature){
				best_feature = feature;
			}
		}
		
		critters_value = (best_feature*2000) + (best_feature*B->parkReputation*100);
		A->parkIncome += critters_value;

		//"Sell" the critter
		barnCritters->erase(name_k);
		
		//return back to the menu
		cout << "Successfully sold "<<name_k<< " for $" << (int)critters_value <<".00 !"<<endl;
		
		continuePrompt();

		break;
		} //End Case 6
	case '7': 	
		{ //Start Case 7

		return true;
		continuePrompt();
		break;
		
		} //End Case 7
	
	default:{  cout << "Invalid Input!\n";
		  cin.clear();
		  continuePrompt();
		  return false;
		}

		return false; //Just in Case
	}  	

	return false; //Don't Quit, Just in Case
}
