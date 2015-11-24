/******************************************************************************
 * Florian Pontani & Sidney Jackson
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

#ifndef HW8_TIME_H
#define HW8_TIME_H

#include "main_menu.hpp"
#include "progressReport.hpp"
#include "critter.hpp"
#include <iostream>
#include <string>
#include <cstdbool>
#include <map>

//public:

/*********** Menu Handling Functions **************/

bool progressMenu(Progress_Report *A, Progress_Report *B);

/************* Print Functions ********************/

//Prints List of Critter Park Menu Options
void printProgressMenu();

//Prints the Player Manual
void printProgressManual();

/***************************************************/

#endif
