/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #11 
 * 
 * driver.hpp - contains declarations for the menu and related functions
 *
 * Last Modified: November 20, 2015
 * 
 * *****************************************************************************/

#ifndef HW8_MANAGE_H
#define HW8_MANAGE_H

#include "main_menu.hpp"
#include "critter.hpp"
#include <iostream>
#include <string>
#include <cstdbool>
#include <map>

//public:

/*********** Menu Handling Functions **************/

bool managementMenu(std::map<std::string, Critter> *critters);

/************* Print Functions ********************/

//Prints List of Critter Park Menu Options
void printManagementMenu();

//Prints the Player Manual
void printManagementManual();

/***************************************************/

#endif
