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

#ifndef HW8_MAIN_H
#define HW8_MAIN_H

#include "barn_menu.hpp"
#include "management_menu.hpp"
#include "time_lapse_menu.hpp"
#include "critter.hpp"
#include "progressReport.hpp"
#include <iostream>
#include <string>
#include <cstdbool>
#include <map>

//public:

/*********** Menu Handling Functions **************/

// Repeatedly calls the Menu Function
int main();

bool mainMenu(std::map<std::string, Critter> *critters, Progress_Report *A, Progress_Report *B);

//"Refreshes Screen"
void refreshScreen();

//Calls Continue Prompt
void continuePrompt();

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

//Prints a "graphic"... critter?
//void print_Critter();

//Prints a "graphic" Critter Park Logo.
//void print_Logo();

/***************************************************/

#endif
