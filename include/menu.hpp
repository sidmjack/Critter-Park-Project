/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * CS 600.120
 * Homework #8, part 1
 *
 * menu.hpp - header file for the menu/driver program utilities
 *
 * Last Modified: November 2, 2015
 *****************************************************************************/
#ifndef HW8_MENU_H
#define HW8_MENU_H

// the commands in this menu are handled internally as integers, their actual
// meaning is listed here:
#define CMD_A 1
#define CMD_L 2
#define CMD_K 3
#define CMD_B 4
#define CMD_R 5
#define CMD_Q 0

#include <vector>
#include <iostream>
#include <cstdio>
#include <string>

// print the menu options to the console (cout)
void printMenu();

// get the user input
int getInput(int* cmd, int* ID1, int* ID2);

// print a list of current Critters to cout
void printCritterList(std::vector<Critter> vec);

#include "menu.cpp"

#endif  
