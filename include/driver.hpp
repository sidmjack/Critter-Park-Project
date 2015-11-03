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

// print a list of things the user may do
void printMenu();

// using a list of critters, apply the user's desired changes
// or show the desired information
bool menu(std::map<std::string, Critter> *critters);

// used for repeatedly calling the menu function and for little else
int main();

#endif
