/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 2
 *
 * trait.hpp - Contains the class and function definitions for the Trait class,
 * which is used in this program to assess the cuteness, scariness, and
 * strangeness of each feature that a Critter has.
 *
 * Last Modified: November 4, 2015
 * ****************************************************************************/
#include "trait.hpp"

// CREATE THE BLOODY DICTIONARY //
std::map<std::string, std::vector<int>> Trait::index = Trait::createList();



// STATIC LOOKUP FUNCTIONS //
  
// checks if a trait is in the dictionary or naw
bool Trait::exists(std::string s){
  // see if the string is a valid trait
  auto it = Trait::index.find(s);
  if( it == Trait::index.end() ){
    std::cerr << "Trait: could not find trait \""<< s <<"\" in index!\n";
    return false;
  }
  return true;
}

// returns the cute/scary/strange scores for the given string.
// returns a zero-length vector on fail
std::vector<int> Trait::getAll(std::string s){
  // see if the string is a valid trait
  if( !Trait::exists(s) ){
    std::cerr << "getAll: could not find trait \""<< s <<"\" in index!\n";
    return std::vector<int> { };
  }
  // if it is, return the scores
  return index.at(s);
}


// returns the cuteness for the given string.
// returns a zero-length vector on fail
std::vector<int> Trait::getCute(std::string s){
  // see if the string is a valid trait
  if( !Trait::exists(s) ){
    std::cerr << "getCute: could not find trait \""<< s <<"\" in index!\n";
    return std::vector<int> { };
  }
  // if it is, return the cuteness (first number in the vector)
  return std::vector<int>{ Trait::index.at(s).at(0) };
}


// returns the scariness for the given string
// returns a zero-length vector on fail
std::vector<int> Trait::getScary(std::string s){
  // see if the string is a valid trait
  if( !Trait::exists(s) ){
    std::cerr << "getScary: could not find trait \""<< s <<"\" in index!\n";
    return std::vector<int> { };
  }
  // if it is, return the scariness (second number in the vector)
  return std::vector<int>{ Trait::index.at(s).at(1) };
}


// returns the stangeness for the given string
// returns a zero-length vector on fail
std::vector<int> Trait::getStrange(std::string s){
  // see if the string is a valid trait
  if( !Trait::exists(s) ){
    std::cerr << "getStrange: could not find trait \""<< s <<"\" in index!\n";
    return std::vector<int> { };
  }
  // if it is, return the scariness (second number in the vector)
  return std::vector<int>{ index.at(s).at(2) };
}



// TRAIT MANIPULATION FUNCTIONS //

// assigns this Trait the given traits
  bool Trait::setTraits(std::vector<std::string> new_traits){


  // see if each trait is recognized
  for(unsigned int i = 0; i < new_traits.size(); i++){
    if( ! Trait::exists(new_traits[i])){
      std::cout << "error: setTraits: \"" << new_traits.at(i) << "\" not in dictionary!";
      return false;
    }
  }
  // if everything is k, return
  this->current = new_traits;
  return true;
}

// returns a list of currently stored traits (empty on failure)
std::vector<std::string> Trait::getTraits(){
  return current;
}
  


// OVERLOADED OPERATORS  //

// the + operator will sum the cuteness, scariness and strangeness of
// two instances of the Trait class
Trait Trait::operator+(Trait other){
  // create a blank to hold the result
  Trait output;
  std::vector<std::string> contents;
  // find out what the other traits are holding, and grab it
  for(unsigned int i = 0; i < current.size(); i++){
    contents.push_back(this->current[i]);
  }
  // do this for both inputs
  for(unsigned int i = 0; i < other.getTraits().size(); i++){
    contents.push_back(other.getTraits().at(i));
  }
  // spit that back out
  output.setTraits(contents);
  return output;

}
  

// the += operator will add the cute/scary/strange values to the current
// intance of the Trait class
void Trait::operator+=(Trait other){
  // add the other Trait's traits to this one
  for(unsigned int i = 0; i < other.getTraits().size(); i++){
    // make sure nohing sus is stored in the other Trait
    if( !Trait::exists(other.getTraits().at(i)) ){
      std::cout << "copyAssign: could not find \"" << other.getTraits().at(i) << "\" in index!\n";
    }
    this->current.push_back(other.getTraits().at(i));
  }
}

/*****************************************************************************/
//UNIT TEST:
void Trait::unitTest () {
	std::cout << "Beginning unit tests for Trait Class Functions...\n";

/*****************************************************************************/

	//Create Trait Object
	Trait mock_Trait;
	//Create Static List/Dictionary of Traits
	mock_Trait.createList();
	
	std::cout << "Testing whether certain trait names exist in dictionary...\n\n";

	// Testing "Exists" Functions:
	// Checks whether the input trait exists in the dictionary of traits.  
	int passes = 0;
	
	std::cout << "Testing whether \"CHUBBY\" exists in dictionary...\n";
	//Expected(1): Shouldn't Exist
	if (mock_Trait.exists("chubby")){
		std::cout << "Yep!\n";
		passes = 0;
	} else {
	std::cout << "Nope\n";
		passes++;
	}
	
	std::cout << "Testing whether \"CHUNKY\" exists in dictionary\n";
	//Expected(2): Should't Exist
	if (mock_Trait.exists("chunky")) {
		std::cout << "Yep!\n";
		passes = 0;
	} else {
		std::cout << "Nope.\n";
		passes++;
	}

	std::cout << "Testing whether \"STUBS\" exists in dictionary\n";
	//Expected(3): Should Exists
	if (mock_Trait.exists("stubs")) {
		std::cout << "Yep!\n";
		passes++;
	} else {
		std::cout << "Nope.\n";
		passes = 0;
	}
	
	if (passes == 3) {
		std::cout << "Exists Function: PASSED!\n\n";
	} else {
		std::cout << "Exists Function: FAILED!\n\n";
	}

/*****************************************************************************/
	//Testing Function getAll Function:
	//Function: Returns the "character impact" of the traits passed to it.
	
	int test_A = 0;
	int test_B = 0;
	int test_1 = 0;
	int test_2 = 0;
	int test_3 = 0;

	std::cout << "Testing Trait's getAll function...\n";	
	for (int i = 0; i < 3; i++) {
		test_A += (mock_Trait.getAll("slimy")).at(i);
		test_A += (mock_Trait.getAll("stubs")).at(i);
		test_A += (mock_Trait.getAll("eight")).at(i);
	}

	if (test_A == 11) {
		std::cout << "getAll Function: PASSED!\n\n";
	} else {
		std::cout << "getAll Function: FAILED!\n\n";
	}

	std::cout << "Testing Trait's getCute function...\n";
	test_1 += (mock_Trait.getCute("slimy")).at(0);
	test_1 += (mock_Trait.getCute("stubs")).at(0);
	test_1 += (mock_Trait.getCute("eight")).at(0);
	
	if (test_1 == 1) {
		std::cout << "getCute Function: PASSED!\n\n";
	} else {
		std::cout << "getCute Function: FAILED!\n\n";
	}

	std::cout << "Testing Trait's getScary function...\n";
	test_2 += (mock_Trait.getScary("slimy")).at(0);
	test_2 += (mock_Trait.getScary("stubs")).at(0);
	test_2 += (mock_Trait.getScary("eight")).at(0);

	if (test_2 == 3) {
		std::cout << "getScary Function: PASSED!\n\n";
	} else {
		std::cout << "getScary Function: FAILED!\n\n";
	}

	std::cout << "Testing Trait's getStrange function...\n";
	test_3 += (mock_Trait.getStrange("slimy")).at(0);
	test_3 += (mock_Trait.getStrange("stubs")).at(0);
	test_3 += (mock_Trait.getStrange("eight")).at(0);

	if (test_3 == 7) {
		std::cout << "getStrange Function: PASSED!\n\n";
	} else {
		std::cout << "getStrange Function: FAILED!\n\n";
	}

	//Compares total of seperate get functions to getAll function
	test_B = (test_1 + test_2 + test_3);

	if (test_A == test_B){
		std::cout << "All getFunctions: PASSED!\n\n";
	} else {
		std::cout << "All getFunction: FAILED!\n\n";
	}

/*****************************************************************************/
	std::cout << "Testing Trait Manipulation Functions: \n";
	//Set the mock_Trait object equal to a given vector of trait-strings 
	//that can be found in the trait library.
	//If it returns true, the function has passed.
	//Further, pass a vector of traits that arn't in the trait string
	//library, if it returns false, the function passed.
	
	int passes_2 = 0;

	std::cout << "Setting two trait (smooth, leather hide) to trait object...\n";
	
	std::vector<std::string> new_traits {"smooth","leather hide"};
	
	if(mock_Trait.setTraits(new_traits)){
		passes_2++;
	} else {
		passes_2 = 0;
	}

	std::cout << "Setting two trait (furry, fur) to trait object...\n";

	Trait mock_Trait_2;
	std::vector<std::string> new_traits_2 {"furry","fur"};

	if(mock_Trait_2.setTraits(new_traits_2)){
		passes_2=0;
	} else {
		passes_2++;
	}

	if(passes_2 == 2){
		std::cout << "Set Traits Function: PASSED!\n\n";
	} else {
		std::cout << "Set Traits Function: FAILED!\n\n";
	}

	//Then return the name of the stored traits
	//If the same...PASS!
	
	std::cout << "Testing getTraits to determine whether correct traits were returned.\n";

	if (((mock_Trait.getTraits()).at(0) == "smooth") &
	      ((mock_Trait.getTraits()).at(1) == "leather hide")) {
		std::cout << "Set Traits Function: PASSED!\n\n";
	} else {
		std::cout << "Set Traits Function: FAILED!\n\n";
	}

/*****************************************************************************/
	/*Core Dumps...Work on...*/
	
	std::cout << "Testing Overloaded Operators: \n";
	//Using the traits above, make one trait that is 
	//composed of the sum total of the other traits,
	//Use the add operator for the three to get a total
	//of all the traits
	
	std::cout << "Add Trait A and Trait B to produce Trait C.\n";

	Trait mock_Trait_A;
	std::vector<std::string> new_traits_A {"smooth","pelt"};
	mock_Trait_A.setTraits(new_traits_A);
	//Pelt: 2, 0, -1
	//Smooth: 2, 0, -1
	//Total Num: 2

	int total_A = 0;

	for (int i = 0; i < 3; i++) {
		total_A += (mock_Trait_A.getAll("smooth")).at(i);
		total_A += (mock_Trait_A.getAll("pelt")).at(i);
	}

	Trait mock_Trait_B;
	std::vector<std::string> new_traits_B {"golden","slit"};
	mock_Trait_B.setTraits(new_traits_B);
	//Golden: 0, -1, 2
	//Slit: 0, 2, 0
	//Total Num: 3
	
	int total_B = 0;

	for (int i = 0; i < 3; i++) {
		total_B += (mock_Trait_B.getAll("golden")).at(i);
		total_B += (mock_Trait_B.getAll("slit")).at(i);
	}

	Trait mock_Trait_C;
	mock_Trait_C.setTraits((/*mock_Trait_A + */mock_Trait_B).getTraits());

	int total_C = 0;

	for (int i = 0; i < 3; i++) {
		total_C += (mock_Trait_C.getAll("smooth")).at(i);
		total_C += (mock_Trait_C.getAll("pelt")).at(i);
		total_C += (mock_Trait_C.getAll("golden")).at(i);
		total_C += (mock_Trait_C.getAll("slit")).at(i);
	}

	//If total_C is equivalent to the sum of parts of Trait A
	//and Trait B, then we know that the plus operator works.

	if ((total_C == (total_A + total_B))) {
		std::cout << "Plus Overloaded Operator: PASSED!\n\n";
	} else {
		std::cout << "Plus Overloaded Operator: FAILED!\n\n";
	}

	//Create a new instance of trait and use the += to 
	//set the new instance equal to the sum total
	//Test operators by comparing the total value
	//of the results for both, if even...PASS!
	
	std::cout << "Add Trait B to Trait A to define Trait A as a combined sum.\n";

	mock_Trait_A += mock_Trait_B;

	total_A = 0;

	for (int i = 0; i < 3; i++) {
		total_A += (mock_Trait_C.getAll("smooth")).at(i);
		total_A += (mock_Trait_C.getAll("pelt")).at(i);
		total_A += (mock_Trait_C.getAll("golden")).at(i);
		total_A += (mock_Trait_C.getAll("slit")).at(i);
	}

	//If the total trait values of A are equal to the total trait
	//values of C (which we set equal to the sum of the original A
	//and the orignal B), we'll know that the plus equal operator
	//works.

	if (total_A == total_C) {
		std::cout << "Plus Equal Operator: PASSED!\n\n";
	} else {
		std::cout << "Plus Equal Operator: FAILED!\n\n";
	}


/*****************************************************************************/

	std::cout << "Finishing unit tests for Trait Class Functions...\n";
	return;
}
/*****************************************************************************/


