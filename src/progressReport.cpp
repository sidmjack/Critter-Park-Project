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
 * 
 * *****************************************************************************/

#include "progressReport.hpp"

//Progress Report Constuctor
Progress_Report :: Progress_Report()
{
}

// Progress Report Destructor
Progress_Report::~Progress_Report(){
}

template <typename T>
std::string Progress_Report::netChange(T A, T B)
{
	std::string net_string;
	std::string sign;

	T value = A-B;
	int val = std::abs(value);
	
	if (val < 0){
		net_string = ("   NET: " + std::to_string(0) );
		return net_string;
	}

	if (value >= 0){
		sign = "+";
	} else {
		sign = "-";
	}

	net_string = ( "   NET: " + sign + std::to_string((val)));

	return net_string;
}

void Progress_Report::colorOutput(double input){
	if (input < 0){
		std::cout << "\x1b[1;31m";
	} else if (input == 0) {
		std::cout << "\x1b[1;33m";
	} else {
		std::cout << "\x1b[1;32m";
	}
	return;
}

void Progress_Report::resetOutput(){
	std::cout << "\x1b[1;37m";
	return;
}

//Maybe pass a struct containing all the information.
void Progress_Report::printReport(Progress_Report A, Progress_Report B) 
{
	resetOutput();
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
	std::cout << "***PARK REPUTATION***\n";
	std::cout << "Park Appeal Visitor Poll Results: \n";
	
	colorOutput(A.parkReputation-B.parkReputation);
	std::cout << "\t Overall Critter Park Reputation: " << A.parkReputation;
	std::cout << netChange(A.parkReputation, B.parkReputation) << "\n";
	resetOutput();
	
	colorOutput(A.cuteRep-B.cuteRep);
	std::cout << "\t Cute Critter Reputation: " << A.cuteRep;
	std::cout << netChange(A.cuteRep, B.cuteRep) << "\n";
	resetOutput();
	
	colorOutput(A.scaryRep-B.scaryRep);	
	std::cout << "\t Scary Critter Reputation: " << A.scaryRep;
	std::cout << netChange(A.scaryRep, B.scaryRep) << "\n";
	resetOutput();

	colorOutput(A.strangeRep-B.strangeRep);
	std::cout << "\t Strange Critter Reputation: " << A.strangeRep;	
	std::cout << netChange(A.strangeRep, B.strangeRep) << "\n\n";
	resetOutput();

	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
	std::cout <<  "***VISITOR STATISTICS***\n";	
	std::cout << "Vistor Interest Statistics: \n";
	
	colorOutput(A.cuteVisitors-B.cuteVisitors);
	std::cout << "\t\"Cute\" Critter Interest: " << A.cuteVisitors << "%";
	std::cout << netChange(A.cuteVisitors, B.cuteVisitors) << "%\n";
	resetOutput();
	
	colorOutput(A.scaryVisitors-B.scaryVisitors);	
	std::cout << "\t\"Scary\" Critter Interest: " << A.scaryVisitors << "%";
	std::cout << netChange(A.scaryVisitors, B.scaryVisitors) << "%\n";
	resetOutput();
	
	colorOutput(A.strangeVisitors-B.strangeVisitors);	
	std::cout << "\t\"Strange\" Critter Interest: " << A.strangeVisitors << "%";
	std::cout << netChange(A.strangeVisitors, B.strangeVisitors) << "%\n";
	resetOutput();
	
	std::cout << "Park Visting Statistics: \n";
	
	colorOutput(A.totalVisitors-B.totalVisitors);
	std::cout << "\tTotal Visitors to Park: " << A.totalVisitors;
	std::cout << netChange(A.totalVisitors, B.totalVisitors) << "\n";
	resetOutput();
		
	if (B.totalVisitors != 0) {
	double visitorPercentage = (A.totalVisitors/B.totalVisitors);
	colorOutput(visitorPercentage);
	std::cout << "\tPercent Increase/Decrease: " << visitorPercentage << "%\n\n";
	resetOutput();
	} else {
	std::cout << "\tPercent Increase/Decrease: Information Not Available...\n\n";
	}
	
	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n";
	std::cout << "***FINANCIAL STATEMENT***\n";
	std::cout << "General Fiscal Report:\n";
        
	
	colorOutput(A.initialParkBalance);
	std::cout << "\tInitial Park Balance: $" << A.initialParkBalance;
	if (A.timelapse == 0){
	resetOutput();
	std::cout << " NET: Information Not Available...\n";
	} else {
	colorOutput(A.initialParkBalance - B.initialParkBalance);
	std::cout << netChange(A.initialParkBalance, B.initialParkBalance) << "\n";
	}
	resetOutput();

	colorOutput((-1)*A.parkInvestments);
	std::cout << "\tPark Investments: $" << (A.parkInvestments);
	colorOutput(A.parkInvestments - B.parkInvestments);
	std::cout << netChange(A.parkInvestments, B.parkInvestments) << "\n";
	resetOutput();
	
	colorOutput(A.parkIncome);
	std::cout << "\tPark Income: $" << A.parkIncome;
	colorOutput(A.parkIncome-B.parkIncome);
	std::cout << netChange(A.parkIncome, B.parkIncome) << "\n";
	resetOutput();

	colorOutput(((-1)*A.maintenanceFees));
	std::cout << "\tMaintenance Fees/Costs: $" << A.maintenanceFees;
	colorOutput(B.maintenanceFees - A.maintenanceFees);
	std::cout << netChange(A.maintenanceFees, B.maintenanceFees) << "\n";
	resetOutput();
	
	colorOutput(A.resultingBalance);
	std::cout << "\tCurrent Balance: $" << A.resultingBalance;
	colorOutput(A.resultingBalance-B.resultingBalance);
	std::cout << netChange(A.resultingBalance, B.resultingBalance) << "\n";
	resetOutput();

	std::cout << "Financial Trend: \n";

	colorOutput(A.resultingBalance-A.initialParkBalance);
	std::cout << "\tTotal Monetary Income: $" << (A.resultingBalance-A.initialParkBalance);
	if (A.timelapse == 0){
	resetOutput();
	std::cout << " NET: Information Not Available...\n";
	} else {
	colorOutput(A.resultingBalance - B.resultingBalance);
	std::cout << netChange(A.resultingBalance-A.initialParkBalance, B.resultingBalance-B.initialParkBalance) << "\n";
	}
	resetOutput();
	
	if (B.incomePercentage != 0) {
	colorOutput(A.incomePercentage);
	std::cout << "\tPercent Income Increase/Decrease: " << (A.incomePercentage) << "%";
	colorOutput(A.incomePercentage - B.incomePercentage);
	std::cout << netChange(A.incomePercentage, B.incomePercentage) << "\n\n";
	resetOutput();
	} else {
	std::cout << "\tPercent Income Increase/Decrease: Information Not Available...\n\n";
	}

	std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
	std::cout << "\x1b[0m";

}

//Test Helper Function
double Progress_Report::rando() {
 	  int random_integer = (unsigned(rand()%100));
	  return random_integer;	
}

void Progress_Report::getIncomePercentage(Progress_Report *A, Progress_Report *B) {
	A->incomePercentage = (A->parkIncome/B->parkIncome)*10; 
	return;
}

//Random Assignment Function
void Progress_Report::assign(Progress_Report *input)
{
	input->cuteRep = rando(); //Critter Park Decides
	input->scaryRep = rando(); //Critter Park Decides
	input->strangeRep = rando(); //Critter Park Decides
		
	input->parkInvestments = rando();  //User decides!
	input->maintenanceFees = rando() + 250; //Critter Count Decides
	
	return;
}

void Progress_Report::initialBalance(Progress_Report *A, Progress_Report *B){
	A->initialParkBalance = B->resultingBalance;
	return;
}

void Progress_Report::getResultingBalance(Progress_Report *A){
	A->resultingBalance = (A->initialParkBalance+A->parkIncome)-(A->maintenanceFees+A->parkInvestments);
	return;
}

void Progress_Report::reload(Progress_Report *A, Progress_Report *B)
{
//B equals former timelapse data
//A equals current timelapse data
*B = *A;
A->timelapse++;
return;
}

void Progress_Report::fail(Progress_Report A){
	static int bankrupt = 0;
	if (A.resultingBalance < 0){
		bankrupt++;
	} else {
		bankrupt = 0;
	}

	if (bankrupt == 5){
		std::cout << "\n";
		std::cout << "\t#######################################################\n";
		std::cout << "\t     CRITTER PARK: REDUCED TO BANKRUPTCY!!!\n";
		std::cout << "\t  Your hand has been forced to shutdown for a year...\n";
		std::cout << "\t#######################################################\n\n";

		//Simulate a year passing then...
		//RESET EVERYTHING TO INITIAL STATS...
		Progress_Report BANKRUPT;
		for (int i = 0; i < 365; i++){
			reload(&A, &BANKRUPT);
		}
		return;
	} else {
		return;
	}
}

void Progress_Report::parkRep(Progress_Report *A, Progress_Report *B)
{
	int impression = 0;
	//Calculates the general impression of the park from most recent visitors.
	impression += (A->cuteRep)*(A->cuteVisitors*.01);
	impression += (A->scaryRep)*(A->cuteVisitors*.01);
	impression += (A->strangeRep)*(A->cuteVisitors*.01);

	//Combines old and/to current impression for an overall park reputation.
	A->parkReputation = ((.75*B->parkReputation)+(.25*impression));

	return;
}

void Progress_Report::parkVisitors(Progress_Report *A, Progress_Report *B){
	
	double randomIncrement = (((rand()%20)/100.0) - ((rand()%20)/100.0));

	A->totalVisitors = ((.65*B->totalVisitors)+(.35*A->parkReputation*(1.0 + randomIncrement)));
	return;
}

void Progress_Report::calcIncome(Progress_Report *input){
 input->parkIncome = (input->ticketPrice*input->totalVisitors);
}

void Progress_Report::percentVisitor(Progress_Report *input) 
{

	int totalRep; //Variable that contains total characteristic reputations.
	totalRep = (input->cuteRep) + (input->scaryRep) + (input->strangeRep);

	double genCuteRep = (input->cuteRep/totalRep);
	double genScaryRep = (input->scaryRep/totalRep);
	double genStrangeRep = (input->strangeRep/totalRep);
	
	double rand_num;

	for (int i = 0; i < 3; i ++){	
		rand_num = ((unsigned(rand()%3))*.01);
		genCuteRep += rand_num;
		genScaryRep -= (rand_num/2);
		genStrangeRep -= (rand_num/2);
	}

	for (int i = 0; i < 3; i ++){
		rand_num = ((unsigned(rand()%3))*.01);
		genStrangeRep += rand_num;
		genCuteRep -= (rand_num/2);
		genScaryRep -= (rand_num/2);
	}

	for (int i = 0; i < 3; i ++){
		rand_num = ((unsigned(rand()%3))*.01);
		genScaryRep += rand_num;
		genStrangeRep -= (rand_num/2);
		genCuteRep -= (rand_num/2);
	}

	input->cuteVisitors = floor(genCuteRep*1000)/10.0;
	input->scaryVisitors = floor(genScaryRep*1000)/10.0;
	input->strangeVisitors = floor(genStrangeRep*1000)/10.0;

	return;
}

void Progress_Report::simulateWeek(Progress_Report *A, Progress_Report *B){
for (int i = 0; i < 7; i++)
{		
	assign(A); //Assigns needed randos...WILL NOT REMAIN
	percentVisitor(A);
	parkRep(A, B);
	parkVisitors(A, B);
	initialBalance(A, B);
	calcIncome(A);
	getResultingBalance(A);
	getIncomePercentage(A, B);
	fail(*A);
	reload(A, B);	
}
		return;
}



