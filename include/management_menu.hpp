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
#include "binary.hpp"
#include "progressReport.hpp"
#include <iostream>
#include <string>
#include <cstdbool>
#include <map>

//public:

/*********** Menu Handling Functions **************/

bool managementMenu(std::map<std::string, Critter> *barnCritters, std::map<std::string, Critter> *showCritters, std::vector<std::string> *displays, Progress_Report *A, Progress_Report *B);

/************* Print Functions ********************/

//Prints List of Critter Park Menu Options
void printManagementMenu();

//Prints the Player Manual
void printManagementManual();

//Prints the General Management Report
void printManagementReport(Progress_Report *A);

//Prints the Legal Investement Options Available to the Player
void printInvestmentOptions();

//Prints the Illegal Investement Options Available to the Player
void printBlackMarketOptions();

/************* Helper Functions **********************/

//A Randomized "Punishing" Function used when the user dabbles in the Black Market.
void negativePublicity(Progress_Report *A);

/*****************************************************/

#endif
