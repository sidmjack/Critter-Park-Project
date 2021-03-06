/*
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * driver.cpp - contains implementations for the menu and related functions
 *
 * Last Modified: November 20, 2015
 * 
 * *****************************************************************************/

#include "barn_menu.hpp"

using namespace std;

// Prints list of menu options.
void printBarnMenu(){
	
	cout << "\n**************************************************";
	cout << "****************************\n";
	cout << "\n    CRITTER PARK MENU: \n\n";
	cout << "\t1) Display \"Critter Park\" Player Manual\n";
	cout << "\t2) Create New Critter \"Creature\" - [Mate][Random][Rename]\n";
	cout << "\t3) Describe Critter\n";
	cout << "\t4) Display Critter Genome\n";
	cout << "\t5) Display List of Critter Park Creatures\n";
	cout << "\t6) Remove Critter from Park\n";
	cout << "\t7) Leave \"Critter Park Barn\"\n\n";
	cout << "**************************************************";
	cout << "****************************\n";
	cout << "Enter Menu Option: ";
}

void printBarnManual(){

	cout << "\n\t	*** CRITTER PARK PLAYERS' MANUAL *** \n\n";
	cout << "\t Welcome to the Critter Park Barn\n"; 

	cout << "\n\t It is here that critters are a created, \n"; 
      	cout << "bred, and \"studied\". The critters kept here are\n";
	cout << "the critter's avaiable to be put on display in the Park.\n";

	cout << "\n\tWhat's there to do in the Critter Barn?\n";
	
	cout << "\n\tBy entering the number of the menu option offered ";
	cout << " to you in the menu list, you're able create, mate, and\n";
	cout << "\tdisplay your critters (along with their genomes for more ";
	cout << " in depth critter studies).\n";

        cout << "\n\tMenu's Critter Park Game Options: \n";
	cout << "\t\t(1) Display this helpful information\n";
	cout << "\t\t(2) Create a random new Critter\n";
	cout << "\t\t(3) Describe a Critter\n";
	cout << "\t\t(4) Display a Critter's Genome\n";
	cout << "\t\t(5) List the Critters in the barn\n";
	cout << "\t\t(6) Remove a Critter from the barn\n";
	cout << "\t\t(7) Exit the Critter Park Barn\n";

   }



// do everything the user wants, given a vector full of critters
bool barnMenu(std::map<std::string, Critter> *critters, Progress_Report *A){ //Start Menu
	
        char menuChoice = 0;
	int counter = 0;
	
	Binary b;
	Critter c; //General Purpose Critter
	        
	std::map<std::string, Critter>::iterator it;
	
	

	float jitter; // number for some function parameters
	
	printBarnMenu(); //Prints the Menu

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
		borderText("CREATING CRITTER");
		
		char choice;

		cout << "a) Would you like to purchase a new critter? [Random]\n";
		cout << "b) Would you like to breed two critters? [Mate]\n";
		cout << "c) Would you like to create/rename a \"BLANK\" critter? [Make]\n\n";	
		cout << "Enter \"Create\" Option: ";
		
		cin >> choice;		
	
		switch(choice){ //Start Nested Switch 1
			
			case 'a':
				{ //Start Case A	
				string name_r = " "; 

				printBorder();
				
				double price = 35000;
				if (price > A->initialParkBalance || A->parkInvestments > A->initialParkBalance){
				    std::cout << "Critter Park Can't Afford this right now!\n";
					break;
				}
				
				A->parkInvestments += price;

				cout << "\nGive your Random critter a Name!\n";
				cout << "Name: ";
				//get a string from the user
				cin >> name_r;
				//rename the Critter, store by name
				c.setName(name_r);
				// see if a critter by this name exists already
				it = critters->find(name_r); //This doesn't do anything for some reason, ask Ben.
				if(it != critters->end()){
					cout << "A critter by the name " << name_r << " already exists!" << endl;
					break;
				}
				// if there isn't one, add it
				(*critters)[name_r] = c;
				(*critters)[name_r].mutate(0.5);
				cout << "Congrats, you've adopted a new critter!\n";				
				break;
				} //End Case A
			
			case 'b':
				{//Start Case B
				// make sure there are enough critters
				if(critters->size() < 2){
					cout << "You must have at least two critters for reproduction to occur!" << endl;
					break;
				}
				string name_b = " ";
				string P_1 = " ";
				string P_2 = " ";
	
				printBorder();	
			
				cout << "\nProvide the Name of the Critter Parents\n";
							
				cout << "Parent 1: ";
				cin >> P_1;
				it = critters->find(P_1);
				// see if the parent is real
				if(it == critters->end()){
					cout << "Could not find a critter called "<<P_1<<"!" << endl;
					break;
				}
				// do the same for another parent
				cout << "Parent 2: ";
			        cin >> P_2;
				it = critters->find(P_2);
				if(it == critters->end()){
					cout << "Could not find a critter called "<<P_2<<"!" << endl;
					break;
				}
				// get a value for the jitter
				cout << "Breeding jitter (number from 0 to 1): ";
				cin >> jitter;
				// make sure the number was reasonable
				if(jitter < 0 || jitter > 1){
					cout << "I literally just told you, a number between zero and one. Please." << endl;
					break;
				}
							
				cout << "Give your Baby Critter a Name!\n";
				cout << "Name: ";
				cin >> name_b;
				//make sure nobody already has the baby's name
				it = critters->find(name_b);
				if(it != critters->end()){
					cout << "There's already a critter by the name "<<name_b<<"!" << endl;
					break;
				}
			//	cout << "they finna bone rn"<<endl;		
				//edit burner critter to have parents' genes
				c.parents((*critters)[P_1], (*critters)[P_2], jitter);
				//Give New Baby Critter a Name Using Rename Function.
				c.setName(name_b);
				// add the baby to the list of existing critters
				(*critters)[name_b] = c;
				(*critters)[name_b].parents((*critters)[P_1], (*critters)[P_2], jitter);
				cout << "One night, "<<P_1<<" and "<<P_2<<" got a little friendly, and "<<name_b<<" was born.\n";
				
				break;

				} //End Case B
		
			case 'c':{ //Start Case C
				char choice_2;
				
				printBorder();

				cout << "\nWould you like to make a New Critter(a) or Rename a Critter?\n";
				cout << "\ta) Make NEW Critter!\n";
				cout << "\tb) Rename OLD Critter!\n";
				
				cout << "\nEnter Critter Option: ";
				cin >> choice_2;
				
				//Nested Switch 2 Here!
				switch(choice_2) { //Start Switch Case
					
	case 'a':
		{ //Start Case A
		
		string name_n = " ";
					
		printBorder();

		cout << "\nName your NEW Critter:\n";
		cout << "Name: ";
		cin >> name_n;
	
		//Rename the Critter, store by name
		c.setName(name_n);
	
		// See if a critter by this name exists already
		it = critters->find(name_n); //THIS IS USELESS FOR SOME REASON ASK TA
		if (it != critters->end()){
			cout << "A critter by the name " << name_n << " already exists!" << endl;
			break;
		}

		// If name isn't taken, add it
		(*critters)[name_n] = c;
		(*critters)[name_n].mutate(0.5);
		cout << "Generated a new critter!\n";
		
		break;

		} //End Case A
				
	case 'b':
		{ //Start Case B
		string name_n = " ";
		string name_o = " ";
		
		// See if any critters exist to be renamed
		if (critters->size() == 0){
			cout << "There aren't any critters to rename!"<<endl;
			break;
		}
						
		printBorder();

		cout << "\nRename your OLD Critter:\n";
		cout << "Name of OLD critter: ";
		cin >> name_o;
	
		// Check if it exists
		it = critters->find(name_o);
		if (it == critters->end()){
			cout << "There aren't any critters by that name!\n";
			break;
		}
												
		cout << "New Name of " << name_o << ": ";
		cin >> name_n;
						
		// NOTE THAT THERE ARE TWO 'NAME's, one is stored as a member 
		// of the Critter class, and the other is used as a key for
		// the map that stores the critters in this diver program. The
		// latter is mostly used here, but change both just to be sure.
		(*critters)[name_o].setName(name_n);

		// copy critter to new entry in map
		(*critters)[name_n] = (*critters)[name_o];

		// delete the old one
		critters->erase(name_o);
											
		break;

		} //End Case B
					
	default:
		{ //Start Default
		cout << "Invalid Input.\n";
		break;

		} //End Default

	} //End Switch Case

				//End Nested Switch 2
				
				break; //End Case C
			
			default:{ cout << "Invalid Input.\n";
				break;
				}
		}  // End Nested Loop 1     
	     	
				 break; //Case 2 Break	
		} //End Case 2
		
		continuePrompt();

		break;
	
	case '3': 
		{//Start Case 3
		string name_critter = " ";

		printBorder();
		borderText("DESCRIBING CRITTER");
		
		cout << "Which Critter would you like to be described to you?\n";
		cout << "Critter's Name: ";
		cin >> name_critter;
		cout << "\n";
		
		// check if it exists
		it = critters->find(name_critter);
		if(it == critters->end()){
		cout << "There aren't any critters by that name!\n";
		break;
		}
		//Adding Critter Here...
		(*critters)[name_critter].printCritter();
				
	  	continuePrompt();

			break;

		} //End Case 3
	case '4': 
		{ //Start Case 4
		string name_critter = " ";

		printBorder();
		// do we even have critters?
		if(critters->size() == 0){
			cout << "Ruh-Roh! There aren't any critters to analyze!"<<endl;
			break;
		}

		borderText("CRITTER GENOME");
		
		cout << "Which Critter's Genome would you like to have displayed?\n";
		cout << "Critter's Name: ";
		cin >> name_critter;
		cout << "\n";
		// see if we know that critter
		it = critters->find(name_critter);
		if(it == critters->end()){
			cout << "Are you sure you spelled that correctly? I can't find anyone by that name." << endl;
			break;
		}
		cout << "Analyzing the genome of the critter known as \'"<<(*critters)[name_critter].getName()<<"\'....\n";
		cout << "RESULTS: Our scientists conclude that the critter's genes look like this:"<<endl<<endl;
		cout << "\t";
		printBinary((*critters)[name_critter].getBinary().getGenome());
		cout << endl << endl << "Pretty neat, huh?"<<endl;

		continuePrompt();

	       		break;
		} //End Case 4
	case '5':
		{//Start Case 5	
		
		printBorder();
		borderText("LIST OF CRITTERS");
					
		//make sure the park has critters in it first
		if(critters->size() == 0){
			cout<<"The park doesn't have any critters in it at all! How sad!\n";
			break;
		}
		//otherwise, iterate through all of them
		counter = 1;
		for(std::map<std::string, Critter>::iterator i = critters->begin(); i != critters->end(); i++){
			cout << "\t";
			if(counter < 10){
				cout << " ";
			}
			cout<<counter<<" -- "<< i->second.getName()<<endl;
			counter++;
		}
		cout << endl;

		printBorder();		

	        continuePrompt();

	       		break;
		} //End Case 5
	case '6':
		{//Start Case 6
		std::string name_k;
	
		printBorder();

		// if there aren't any critters left, say so
		if(critters->size() == 0){
			cout << "There aren't any Critters left!\n";
			break;
		}
		
		borderText("REMOVE CRITTER");
	
		cout << "\nWhich innocent critter would you like to safely and humanely tear from this world?\n";
		cout << "Name: ";
		//get a string from the user
		cin >> name_k;
		//see if this critter is real
		it = critters->find(name_k);
		if(it == critters->end()){
			cout << "I couldn't find a critter called \'"<<name_k<<"\'."<<endl;
			break;
		}
		//otherise, remove the critter
		critters->erase(name_k);
		//return back to the menu
		cout << "Successfully.. er.. disposed of "<<name_k<<"!"<<endl;
		
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
	}  
}	
	return false; //Don't Quit
}


