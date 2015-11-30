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
	double val = fabs(value);
	
	if (val == 0){
		net_string = ("   NET: " + std::to_string(0) );
		return net_string;
	}

	if (value >= 0) {
		sign = "+";
	} else {
		sign = "-";
	}

	//Beware, hackish doings beyond this point.
	std::string net_num;
	net_num = std::to_string(val);
	net_num.erase(net_num.find_last_not_of('0') + 1, std::string::npos);
	net_num += "0";
			
	net_string = ("   NET: " + sign + net_num );
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
	
	colorOutput(A.maxVisitors-B.maxVisitors);
	std::cout << "\tMaximum Possible Visitors to Park: " << A.maxVisitors;
	std::cout << netChange(A.maxVisitors, B.maxVisitors) << "\n";
	resetOutput();

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
	
	if ((B.incomePercentage != 0) && (A.timelapse > 1)) {
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

//Allows user to set the ticket price...
void Progress_Report::setTicketPrice(double cost_of_admission, Progress_Report *A) {
	A->ticketPrice = cost_of_admission;
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
//A equals current data

//Variables to RELOAD
	B->cuteRep = A->cuteRep;
	B->scaryRep = A->scaryRep;
	B->strangeRep = A->strangeRep;
	
	B->maxVisitors = A->maxVisitors; 
	B->totalVisitors = A->totalVisitors;
	B->cuteVisitors = A->cuteVisitors;
	B->scaryVisitors = A->scaryVisitors;
	B->strangeVisitors = A->strangeVisitors;
	
	B->initialParkBalance = A->initialParkBalance;
	B->parkInvestments = A->parkInvestments;
	B->parkIncome =	A->parkIncome;
	B->maintenanceFees = A->maintenanceFees;
 	B->resultingBalance = A->resultingBalance;
	B->incomePercentage = A->incomePercentage;

//Variables Reloaded

//A->timelapse++;
return;
}

/*NEW FUNCTION*/
//Non-complicated linear visitor estimator...
void Progress_Report::visitorFactor(Progress_Report *A) {
	

	double num_visitors;
	num_visitors = (((A->parkReputation*.25))/(A->ticketPrice))*A->maxVisitors;
	
	A->totalVisitors = (int)num_visitors;
}


void Progress_Report::fail(Progress_Report *A){
	static int bankrupt = 0;
	if (A->resultingBalance < 0){
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
		A->parkReputation = 10;

		A->cuteRep = 1;
		A->scaryRep = 1;
		A->strangeRep = 1;
	
		A->maxVisitors = 10;
		A->totalVisitors = 0;
		A->cuteVisitors = 0;
		A->scaryVisitors = 0;
		A->strangeVisitors = 0; 	
		
		A->initialParkBalance = 10000.00; 
		A->parkInvestments = 0;
		A->parkIncome =	0;
		A->maintenanceFees = 0;
		A->resultingBalance = 10000.00;
		A->incomePercentage = 0;

		Progress_Report BANKRUPT;
		reload(A, &BANKRUPT);
		A->timelapse += 365;
		
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
	A->cuteRep = (B->cuteRep*.75)+(A->cuteRep*.25);

	impression += (A->scaryRep)*(A->scaryVisitors*.01);
	A->scaryRep = (B->scaryRep*.75)+(A->scaryRep*.25);

	impression += (A->strangeRep)*(A->strangeVisitors*.01);
	A->strangeRep = (B->strangeRep*.75)+(A->strangeRep*.25);

	//A->Reputations will be passed to incremented in another function.

	//Combines old and/to current impression for an overall park reputation.
	A->parkReputation = ((.75*B->parkReputation)+(.25*impression));

	return;
}

void Progress_Report::parkVisitors(Progress_Report *A, Progress_Report *B){
	
	double randomIncrement = (((rand()%20)/100.0) - ((rand()%20)/100.0));

	A->maxVisitors = ((.65*B->maxVisitors)+(.35*A->parkReputation*(1.0 + randomIncrement)));
	
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
	
	percentVisitor(A);
	parkRep(A, B);
	parkVisitors(A, B);
	visitorFactor(A); 
	initialBalance(A, B);
	calcIncome(A);
	getResultingBalance(A);
	getIncomePercentage(A, B);
	fail(A);

	A->timelapse++;	

		return;
}

//New Function
void Progress_Report::update(Progress_Report *A, Progress_Report *B){
	static int timeLapse = -1;
	if (timeLapse == A->timelapse){
		return;
	} else {
		timeLapse = A->timelapse;
		reload(A, B);
		return;
	}
	return; //Just in case?
}


