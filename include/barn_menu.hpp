/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * barn_menu.hpp - contains declarations for the menu and related functions
 *
 * Last Modified: November 20, 2015
 * 
 * *****************************************************************************/

#ifndef HW8_BARN_H
#define HW8_BARN_H

#include <iostream>
#include <string>
#include <cstdbool>
#include "main_menu.hpp"
#include "binary.hpp"
#include "critter.hpp"

//public:

/*********** Menu Handling Functions **************/

// Repeatedly calls the Menu Function
bool barnMenu(std::map<std::string, Critter> *critters);

/************* Print Functions ********************/

//Prints List of Critter Park Menu Options
void printBarnMenu();

//Prints the Player Manual
void printBarnManual();


/***************************************************/

#endif
