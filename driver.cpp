#include <iostream>
#include <cmath>
#include <string>
#include <cstdbool>
//#include "critter.hpp" //For when we start adding functions

using namespace std;

int menuChoice;


void printMenu(){	   
	cout << "**************************************************";
	cout << "****************************\n";
	cout << "\n    CRITTER PARK MENU: \n\n";
	cout << "\t1) Display \"Critter Park\" Player Manual\n";
	cout << "\t2) Create New Critter \"Creature\" - [Mate][Random][Rename]\n";
	cout << "\t3) Describe Critter\n";
	cout << "\t4) Display Critter Genome\n";
	cout << "\t5) Display List of Critter Park Creatures\n";
	cout << "\t6) About Critter Park - Authors/Game-Info\n";
	cout << "\t7) Leave \"Critter Park\"\n\n";
	cout << "**************************************************";
	cout << "****************************\n";

}

bool menu(){

	printMenu(); //Prints the Menu
	cout << "Enter Menu Option: ";
	cin >> menuChoice; //Recieves User Input (Menu Option)
	switch (menuChoice) { //Initiates the Switch
	
	case 1:   
		  cout << "**************************************************";
		  cout << "****************************\n";
		  cout << "**************************************************";
		  cout << "****************************\n";

		  cout << "\t	*** CRITTER PARK PLAYERS' MANUAL *** \n\n";
		  cout << "\t Welcome to Critter Park - A text based game that allows \n";
		  cout << "\tyou to create, display, and breed critters! \n";
 
		  cout << "\n\n\tWhat are Critters? :";
	  	  cout << "\n\n\t\t Critters are a genetically versatile and flexible species,\n"; 
      	  	  cout << "\tcapable of breeding and producing new creatures with a wide\n";
	   	  cout << "\tarray of characteristics. These are the creature's you, as\n";
	   	  cout << "\tthe player, will be creating and showing off.\n";

		  cout << "\n\n\tHow to Play?\n\n";

	   	  cout << "\t\t\"Critter Park\" is currently under construction...\n";
	  	  cout << "\tAs of now, the scope of feaatures we've implemented\n";
	  	  cout << "\tare fairly limited in number and complexity. \n";
	   	  cout << "\tGiven the menu provided to you at the opening of\n";
	   	  cout << "\tthe game, you are offered a set of options that allow\n";
 	   	  cout << "\tyou to build your collection of critters.\n";
	
		  cout << "\n\t\tBy entering the number of the menu option offered\n";
	   	  cout << "\tto you in the menu list, you're able create, mate, and\n";
	   	  cout << "\tdisplay your critters (along with their genomes for more\n";
	   	  cout << "\tin depth critter studies, if you so choose to study the\n ";
	   	  cout << "\t\"critter genome\".\n ";

            	  cout << "\n\tMenu's Critter Park Game Options: \n";
		  cout << "\t\t(2) Create Critter\n";
	  	  cout << "\t\t(3) Describe Critter\n";
	 	  cout << "\t\t(4) Display Critter Genome\n";
		  cout << "\t\t(5) Display Critters\n";

		  cout << "\n\n\tTo Learn more about us and critter park along with\n";
		  cout << "\tour \"future aspirations\", we invite you to check out \n";
  		  cout <<"\tour \"About Us\" Page (6).\n";
 
		  cout << "\n\t\tTo Exit the Game, Simply Enter (7).\n\n";

		  cout << "**************************************************";
		  cout << "****************************\n";
		  cout << "**************************************************";
		  cout << "****************************\n";

	  	  	  break;
	
	case 2: 
		cout << "\n Create a Critter...\n\n";
		cout << "**************************************************";
		cout << "****************************\n";

		cout <<	"\n///////////////////////////////\n";
		cout <<	"//////	CREATING CRITTER  /////\n";
		cout <<	"///////////////////////////////\n\n";
		
		char choice;

		cout << "a) Would you like to create a random critter? [Random]\n";
		cout << "b) Would you like to breed two critters? [Mate]\n";
		cout << "c) Would you like to create/rename a \"BLANK\" critter? [Make]\n\n";
		
		cout << "Enter \"Create\" Option: ";
		cin >> choice;		
	
		switch(choice){
			
			case 'a':
				{	
				string name_r = " "; 

				cout << "**************************************************";
				cout << "****************************\n";

				cout << "\nGive your Random Critter a Name!\n";
				cout << "Name: ";
				cin >> name_r;

				cout << "\nFeature Not Available...\n";
				cout << "PUT RANDOM CRITTER FUNCTION HERE!\n";
				
				//Make NEW Critter Using New Critter Function.
				//Use Random Critter Function to give it a random genome.
				//Give New Random Critter a Name Using Rename Function.
				
				break;
				}
			
			case 'b':
				{
				string name_b = " ";
				string P_1 = " ";
				string P_2 = " ";
	
				cout << "**************************************************";
				cout << "****************************\n";
				
				cout << "\nProvide the Name of the Critter Parents\n";
							
				cout << "Parent 1: ";
				cin >> P_1;

				cout << "Parent 2: ";
			        cin >> P_2;	
							
				cout << "Give your Baby Critter a Name!\n";
				cout << "Name: ";
				cin >> name_b;

				cout << "\nFeature Not Available...\n";
				cout << "PUT MATE CRITTER FUNCTION HERE!\n";
				
				//Make New Critter Using New Critter Function.
				//Use Mate Critter Function to give it a crossed genome.
				//Give New Baby Critter a Name Using Rename Function.

				break;
				}
			case 'c':
				char choice_2;
				
				cout << "**************************************************";
				cout << "****************************\n";

				cout << "\nWould you like to make a New Critter(a) or Rename a Critter?\n";
				cout << "\ta) Make NEW Critter!\n";
				cout << "\tb) Rename OLD Critter!\n";
				
				cout << "\nEnter Critter Option: ";
				cin >> choice_2;

				switch(choice_2) {
					
					case 'a':
						{
						string name_n = " ";
					
						cout << "**************************************************";
						cout << "****************************\n";
		
						cout << "\nName your NEW Critter:\n";
						cout << "Name: ";
						cin >> name_n;

						cout << "\nFeature Not Available...\n";
						cout << "PUT MAKE CRITTER FUNCTION HERE!\n";

						//Make a New Critter Using Create Critter Function.
						//Use Rename Function to Rename the Critter.
						
						break;
						}
				
					case 'b':
						{
						string name_n = " ";
						string name_o = " ";

						cout << "**************************************************";
						cout << "****************************\n";

						cout << "\nRename your OLD Critter:\n";
						cout << "Name of OLD critter: ";
						cin >> name_o;
											
						cout << "New Name of " << name_o << ": ";
						cin >> name_n;
											
						cout << "\nFeature Not Available...\n";
						cout << "PUT RENAME CRITTER FUNCTION HERE!\n";

						//Given the old name of the critter,
						//Use the rename function to change 
						//critter's name.
						
						break;
						}
					
					default: cout << "Invalid Input.\n";
						break;
				}
				break; //Break for case c: choice_1
			
			default: cout << "Invalid Input.\n";
				break;
		}        
	     	break; //Case 3 Break	

	case 3: 
		{
		string name_critter = " ";

		cout << "\n\"Displaying\" Critter Genome...\n\n";
		cout << "**************************************************";
		cout << "****************************\n";

		cout <<	"\n///////////////////////////////\n";
		cout <<	"///// DESCRIBING CRITTER  /////\n";
		cout <<	"///////////////////////////////\n\n";
		
		cout << "Which Critter would you like to be described to you?\n";
		cout << "Critter's Name: ";
		cin >> name_critter;
		cout << "\n";

		cout << "Feature Not Available...\n";
		cout << "PUT PRINT CRITTER FUNCTION HERE!\n";
		cout << "**************************************************";
		cout << "****************************\n";
			  break;
		}
	case 4: 
		{
		string name_critter = " ";

		cout << "\n Displaying Critter Genome...\n\n";
		cout << "**************************************************";
		cout << "****************************\n";

		cout <<	"\n///////////////////////////////\n";
		cout <<	"//////	CRITTER GENOME  /////\n";
		cout <<	"///////////////////////////////\n\n";
		
		cout << "Which Critter's Genome would you like to have displayed?\n";
		cout << "Critter's Name: ";
		cin >> name_critter;
		cout << "\n";

		cout << "Feature Not Available...\n";
		cout << "PUT DISPLAY BINARY FUNCTION HERE!\n";
		cout << "**************************************************";
		cout << "****************************\n";

	       		break;
		}
	case 5: 
		cout << "\n Displaying List of Critters...\n\n";
		cout << "**************************************************";
		cout << "****************************\n";

		cout <<	"\n///////////////////////////////\n";
		cout <<	"//////	LIST OF CRITTERS  /////\n";
		cout <<	"///////////////////////////////\n\n";
		
		cout << "Feature Not Available...\n";
		cout << "PUT DISPLAY FUNCTION HERE!\n";
		cout << "**************************************************";
		cout << "****************************\n";
	 
	       		break;
	case 6: 
		cout << "**************************************************";
		cout << "****************************\n";
		cout << "\tCRITTER PARK INFORMATION:\n\n";
		cout << "\tAbout Us:\n";
		cout << "\t\tAuthors: Florian Pontani & Sidney Jackson\n";
		cout << "\t\tContact: flo1@jhu.edu & sjacks85@jhu.edu\n";
		cout << "\t\t   (917) 454-8493 & (386) 956-5577\n";
		cout << "\t\tCompany: JHU-Squid Squad Inc.\n\n";
	
		cout << "\tAbout Critter Park:\n";
		cout << "\t\tProject Details:CS 600.120 - Homework 8.1\n";
		cout << "\t\tLast Modification: November 2, 2015\n";
		cout << "\t\tGame Version: JHU.CS.CP.1.0\n\n";

		cout << "\t\tOur game is still currently under construction.\n";
		cout << "\tWe later plan to implement more interactive\n";
		cout << "\tfeatures to critter park that will allow players\n";
 		cout << "\tnot only create and show off their critters, but\n";
		cout << "\tevaluate their critter characteristics, diplay them\n";
		cout << "\tin a virtual \"Critter Park\", build the park, manage\n";
		cout << "\tthe park, and more!\n\n"; 

 		cout << "\t\tMORE TO COME...\n\n";
		cout << "**************************************************";
		cout << "****************************\n";

			  break;

	case 7: 	
		
		cout << "**************************************************";
		cout << "****************************\n";
		cout << "\nAre you sure you want to quit? \n";
		
		char response;
		
		cout << "\t\"a\") Continue Playing!\n";
		cout << "\t\"b\") Quit Game...\n\n\n";
		
		cout << "Enter Response: ";
		cin >> response;
		
		switch (response) {
			case 'a': cout << "\nYeah- We figured you'd want to keep playing!\n\n";
			        break;
			case 'b':
				  cout << "**************************************************";
				  cout << "****************************\n";
				  cout << "\nAre you absolutely sure you want to quit?\n";
			  	 
				 char response_2;
				  
				 cout << "\t\"a\") Continue Playing!\n";
				 cout << "\t\"b\") Quit Game...\n\n\n";
					
				 cout << "Enter Response: ";
				 cin >> response_2;
	
				switch(response_2) {
					case 'a': cout << "\nYeah- We figured you'd want to keep playing.\n\n";
						  return false;
						  break;
					case 'b': 
						  cout << "**************************************************";
						  cout << "****************************\n";
						  cout << "\n\nAlright, if you're sure you want to quit...\n";
						  cout << "Come back again!\n\n";
					          return true;
						  break;
					default: cout << "Invalid Input.\n";
						 break;
				}
			        break;
			default: cout << "Invalid Input.\n";
				 break;
		}
		
		break; //Break for QUIT switch.
	
	default:  cout << "Invalid Input.\n";
		  break;
	
	} //End of Switch Cases
	
	return false; //Don't Quit
	
}

int main(){
	
	cout << "\n\t\t   *********************************\n";
	cout << "\t\t        WELCOME TO CRITTER PARK!\n";
	cout << "\t\t   *********************************\n\n";
	
	bool quit = false;
 	 
	 while(!quit) {
  	 		 quit = menu();
 	 }

	return 0;
}
