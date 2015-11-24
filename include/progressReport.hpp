/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #11
 *
 * Last Modified: November 29, 2015
 * *****************************************************************************/

#ifndef HW8_PROGRESS_REPORT
#define HW8_PROGRESS_REPORT

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

class Progress_Report
{

public:

/************************** CONSTRUCTOR AND DESTRUCTOR ***********************/

// Constructor
Progress_Report();

// Destructor
~Progress_Report();

/*************************** PRINT/OUTPUT FUNCTIONS **************************/

//Sets the ANSI II Terminal Output Text Color Setting Based on Input Fed
static void colorOutput(double input);

//Resets the ANSI II Terminal Settings 
static void resetOutput();

//Prints the Critter Park Report Progress Report.
static void printReport(Progress_Report A, Progress_Report B);	

/************************** RANDOMIZED INPUT FEEDER **************************/

/*Test Helper Function*/
static double rando();

/*Random Assignment Function*/
static void assign(Progress_Report *input);

/**************************** SIMULATOR FUNCTIONS ****************************/

//Deterimines the net change between any two values fed to it.
template <typename T>
static std::string netChange(T A, T B);

//Determines the Income Percentage
static void getIncomePercentage(Progress_Report *A, Progress_Report *B);

//Set the Initial Balance for the Progress Report
static void initialBalance(Progress_Report *A, Progress_Report *B);

//Determines the resulting balance after all fiscal transactions have been made
static void getResultingBalance(Progress_Report *A);

//"Refreshes" the Progress Report Objects 
static void reload(Progress_Report *A, Progress_Report *B);

//Determines whether Critter Park has gone Bankrupt
static void fail(Progress_Report A);

//Determines Park Reputation for the most recent Progress Report 
static void parkRep(Progress_Report *A, Progress_Report *B);

//Determines the number of Critter Park Visitors for the simulation
static void parkVisitors(Progress_Report *A, Progress_Report *B);

//Calculates Critter Park's Income for most recent Progress Report
static void calcIncome(Progress_Report *input);

//Calculates the percentage of each type of visitor at Critter Park
static void percentVisitor(Progress_Report *input); 

//Runs a combination of the abov
static void simulateWeek(Progress_Report *A, Progress_Report *B);

/*****************************************************************************/

private:

	int parkReputation = 0;
	
	/*The character reputations are just a sum of the met expectations
	 * of all the visitors for the particular interest they had*/

	//These will be set by looping "visitors" through the critters in CP.
	double cuteRep = 0;
	double scaryRep = 0;
	double strangeRep = 0;
	
	//Calculated by "weight multiplying" old num of visitors by the prak reputation
	int totalVisitors = 0;
	//Percentages of visitors interests at the park. (Helps calculate the people vector)
	double cuteVisitors = 0;
	double scaryVisitors = 0;
	double strangeVisitors = 0;
	
	//Where fiscal biz is dealt with...
	float initialParkBalance = 0;
	float parkInvestments = 0;
	float parkIncome = 0;
	float maintenanceFees = 0;
	float resultingBalance = 1000.00;
	float incomePercentage = 0;

	//Ticket Fee, this is something that should be set by the player.
	//For now, it'll just be set to 10 dollores!
	double ticketPrice = 10.00;
	
	//Keeps track of how many timelaspes have occured.
	int timelapse = 0;

/*****************************************************************************/

};

/*int main(){

	pr A, B;	

	//Tests Progress Report
	bool quit = false; 
       	while(!quit) {
		//assign(&A);
  	 	quit = reportMenu(&A, &B);
 	 }

	return 0;
}*/

#endif
