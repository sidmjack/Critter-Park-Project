/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * driver.hpp - contains declarations for the menu and related functions
 *
 * Last Modified: November 2, 2015
 * 
 * *****************************************************************************/

#ifndef HW8_DRIVER_H
#define HW8_DRIVER_H

#include <iostream>
#include <cmath>
#include <string>
#include <cstdbool>
#include "binary.hpp"
#include "critter.hpp"

//public:

/*********** Menu Handling Functions **************/

// Repeatedly calls the Menu Function
int main();

//"Refreshes Screen"
void refreshScreen();

//Calls Continue Prompt
void continuePrompt();

/************* Menu Variables **********************/

// Using a list of critters, presents and
// applies users' desired changes/ info. 
bool menu(std::map<std::string, Critter> *critters);


/************* Print Functions ********************/

//Critter Park Welcome "Page"
void printWelcome();

//Prints List of Critter Park Menu Options
void printMenu();

//Prints Menu Border
void printBorder();

//Prints input text with "fancy" border
void borderText(std::string text);

//Prints the Player Manual
void printManual();

//Print the "About Us" Page
void printAboutUs();


/************* Switch Cases Functions **************/

//Prints and Handles the Rename Critter Switch Case
void rename_Critter_Switch_Case(std::string choice);

/*************** Unit Test Function ****************/

//static void unitTest();

/***************************************************/

#endif
