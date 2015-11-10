/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * CS 600.120
 * Homework #8, part 1
 *
 * Binary.cpp - contains utilities for printing and manipulating the binary
 *      strings used to store Critter traits in this program.
 *
 * Last Modified: November 9, 2015
 *****************************************************************************/


//// if we need more than a long, change it here: ////
///                                                ///
             #define BINARY_TYPE long int          ///
///                                                ///
//////////////////////////////////////////////////////

#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include "binary.hpp"
#include <random>

std::uniform_int_distribution<BINARY_TYPE> Binary :: uniform_ul;

std::uniform_real_distribution<double> Binary :: double_ul(0.0, 1.0);

// constructor
Binary::Binary(BINARY_TYPE genotype)
  : genome(genotype)
{
}

// destructor
Binary::~Binary(){
}

// wrapper for the mutate function - mutates a Binary's genome in situ
//
// severity - number within [0,1] that determines the mutation strength
void Binary::mutate(float severity){
  // call the basic mutate() function on this Binary
  this->setGenome(mutate(this->getGenome(), severity));
  return;
}

// warpper for the cross function - returns a binary from two parent binaries
//
// parent1, parent2 - Binary instances to cross
// jitter - number within [0,1] that determines how "mixed" the result will be
void Binary::cross(Binary parent1, Binary parent2, float jitter){
  // call the basic cross() function, set the genome to its result
  this->setGenome(cross(parent1.getGenome(), parent2.getGenome(), jitter));
  // return
  return;
}
  
/**************** FUNCTIONS USED MOSTLY BY OTHER FUNCTIONS *******************/

// function for crossing two binary strings with a given jitter
//
// n1, n2 - the binary strings that will be crossed
// jitter - the probability that the next bit will come from the opposite
//          input string, should be in range [0,1]
BINARY_TYPE Binary::cross(const BINARY_TYPE n1, const BINARY_TYPE n2, float jitter){
  float random;
  char parent = 'a';
  BINARY_TYPE baby = 0;

  // make sure jitter is within the specified bounds
  if(jitter < 0.0 || jitter > 1.0){
    std::cerr << "Jitter must be in range [0,1]!\n";
    return 0;
  }

  // initialize random number generator using the current time
  srand(time(NULL));
  
  // go through each bit in the strings, starting with the most significant
  for(int i = sizeof(n1)*8-1; i > -1; i--){
    // get a random number, scale from zero to one
    random = (float)rand() / (float)RAND_MAX;

    // shift the baby by one binary digit to prepare for (maybe) writing a one
    baby = baby << 1;

    // if our number is less than the jitter, switch parents
    if(random < jitter){
      if(parent == 'a'){
        parent = 'b';
      }else{
        parent = 'a';
      }
    }

    // copy the next bit from the appropriate parent
    if(parent == 'a'){
      // if the next bit is a one, write a one from PARENT A a to the baby
      if(((n1 >> i) % 2) != 0){
        baby++;
      }
    }else{
      // if the next bit is a one, write a one from PARENT B to the baby
      if(((n2 >> i) % 2) != 0){
        baby++;
      }
    }
  }
  // finished
  return baby;
}

// Function for mutating a given binary string by a given factor
// Number - the string to mutate
// Severity - controls the strength of the changes, should be within [0,1]
// Returns a mutated version of the first string.

BINARY_TYPE Binary::mutate(BINARY_TYPE number, float severity){
  float random;
  BINARY_TYPE mask = 0;
  BINARY_TYPE mutant = 0;

  // make sure severity is within the specified bounds
  if(severity < 0.0 || severity > 1.0){
    std::cerr << "Severity must be in range [0,1]!\n";
    return 0;
  }

  // initialize random number generator using the current time
  srand(time(NULL));
  
  // go through each bit in the string, starting with the most significant
  for(int i = 0; i < (BINARY_TYPE)sizeof(number)*8; i++){
    // get a random number, scale from zero to one
    random = (float)rand() / (float)RAND_MAX;
    
    // advance the mask by one binary bit to prepare for (maybe) writing a one
    mask = mask << 1;

    // if our number is less than the jitter, invert the current bit via mask
    if(random < severity){
      mask++;
    }// otherwise, do nothing
  }

  // apply the mask (i.e. flip all bits whose mask bit is one)
  mutant = number ^ mask;

  // finished
  return mutant;
}

// function for reading the raw binary string
BINARY_TYPE Binary::getGenome() const{
  return this->genome; 
}

// function for setting the genome to a new string
void Binary::setGenome(BINARY_TYPE genome){
  this->genome = genome;
  return;
}

// utility for printing bit strings to the console in readable form
// NOTE: don't use "<<" in combination with this function because I
// didn't overload the "<<" operator
void printBinary(const BINARY_TYPE n){
  BINARY_TYPE number = n;
  for(int i = (int)sizeof(number)*8-1; i > -1; i--){
    if((number >> i) % 2 == 0){
      std::cout << "0";
    }else{
      std::cout << "1";
    }
  }
  return;
}
/************************* Set and Get Bit Field *****************************/

unsigned Binary::getBitField (unsigned offset, unsigned length) const {
  BINARY_TYPE mask = 0;
  for (unsigned i=0; i<length; i++) {
    mask <<= 1;
    mask += 1;
  }
  mask <<= offset;
  //std::cout << "mask: " << toBitString(mask) << "\n";
  BINARY_TYPE field = genome & mask;
  field >>= offset;
  return field;
}

void Binary::setBitField (unsigned offset, unsigned length, unsigned value) {

  if (value >= 1u << length) {
   // std::cout << "error: value " << value << " is to big to be held in field!\n";
    //std::cout << "\t (width: " << length <<", max value: " << (1 << length)-1 << ")\n";
    return;
    //TODO throw something
  }

  BINARY_TYPE mask = 0;
  for (unsigned i=0; i<length; i++) {
    mask <<= 1;
    mask += 1;
  }
  mask <<= offset;
  //std::cout << "mask: " << toBitString(mask) << "\n";
  BINARY_TYPE field = value;
  field <<= offset;
  genome &= ~mask; // set field to 0
  genome |= field; // then put in the new value
}

/*****************************************************************************/

//UNIT TEST:
void Binary::unitTest () {

	std::cout << "Beginning unit tests for Binary Class Functions...\n";

/*****************************************************************************/	
	//CREATING BINARY OBJECTS!
	Binary A;
	Binary B;
	Binary C;

/*****************************************************************************/
	//TESTING MUTATE!
	//Before
	std::cout << "Genome \"Before Mutate\": " << B.genome << "\n";
	BINARY_TYPE before = B.genome;
	
	//Set Genome using Mutate Function
	B.setGenome(mutate(B.getGenome(), .5));

	//After
	std::cout << "Genome \"After Mutate\": " << B.genome << "\n";
	BINARY_TYPE after = B.genome;


	if(before != after) {
		std::cout << "Mutate Function: PASSED!\n\n";
	} else {
		std::cout << "Mutate Function: FAILED!\n\n";
	}

/*****************************************************************************/
	//TESTING CROSS OVER!
	
	std::cout << "Genome \"Before Cross Over\": " << C.genome << "\n";
	before = C.genome;
	
	//Crossing Binary A and B to make C
	C.cross(A, B, .2);
	
	std::cout << "Genome \"After Cross Over\": " << C.genome << "\n";
	after = C.genome;

	if(before != after) {
		std::cout << "Cross-Over Function: PASSED!\n\n";
	} else {
		std::cout << "Cross-Over Function: FAILED!\n\n";
	}

/*****************************************************************************/
//TEST Get GENOME AND BINARY PRINT FUNCTIONS (Visually)
	std::cout << "Binary A: " << A.getGenome() << "\n";
	std::cout << "Binary Representation of A: ";
	printBinary(A.genome);
	std::cout << "\n";
	
	std::cout << "Binary B: " << B.getGenome() << "\n";
	std::cout << "Binary Representation of B: ";
	printBinary(B.genome);
	std::cout << "\n";

	std::cout << "Binary C: " << C.getGenome() << "\n";
	std::cout << "Binary Representation of C: ";
	printBinary(C.genome);
	std::cout << "\n";

	if ((A.getGenome() != 0) | (B.getGenome() != 0) | (C.getGenome() != 0)){
		std::cout << "Get Genome PASSED!\n\n";
	} else {
		std::cout << "Get Genome Failed!\n\n";
	}	

/*****************************************************************************/
//Testing Set Bit Field and Get Bitfield
/*	
	BINARY_TYPE A_field;

	std::cout << "Binary A (Before): ";
	printBinary(A.genome);
	std::cout << "\n";
	std::cout << "Bianry B (Before): ";
	printBinary(B.genome);
	std::cout << "\n";

	std::cout << "Goal: Set Binary A equal to Binary B...\n";

	for (unsigned int i = 0; i < 32; i++){
		//Determines Position along Genome to Alter
		A_field = A.getBitField(i, 2); 
		std::cout << "Iteration " << i << ": " << A_field << "\n";

		//Sets Genome for specified length at specified location to passed value.
		A.setBitField(i, 2, i); 
		std::cout << "Iteration " << i << ": " << A.genome << "\n\n";
	}

	std::cout << "Binary A (After): ";
	printBinary(A.genome);
	std::cout << "\n";
	std::cout << "Bianry B (After): ";
	printBinary(B.genome);
	std::cout << "\n";


	if (((A.genome) == (B.genome))) {
		std::cout << "Get Genome and Set Genome: PASSED!\n\n";
	} else {
		std::cout << "Get Genome and Set Genome: FAILED!\n\n";
	}
*/
/*****************************************************************************/

	std::cout << "Finished unit tests for Binary Class Functions.\n";
	
	return;
}

