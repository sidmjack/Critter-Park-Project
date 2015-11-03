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
 * Last Modified: November 2, 2015
 *****************************************************************************/


//// if we need more than a long, change it here: ////
///                                                ///
             #define BINARY_TYPE long int          ///
///                                                ///
//////////////////////////////////////////////////////

#include "binary.hpp"
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cmath>


#include <iostream>

// constructor
Binary::Binary(){
  genome = 0;
 // std::cout << "new Binary!";
}

// destructor
Binary::~Binary(){
  //std::cout << "genome is kill.\n";
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



// function for mutating a given binary string by a given factor
// 
// number - the string to mutate
// severity - controls the strength of the changes, should be within [0,1]
//
// returns a mutated version of the first string
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
BINARY_TYPE Binary::getGenome(){
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

// this is a hack, for now
//BINARY_TYPE genome;

//ENCODE DECODE FUNCTIONS:

//Encode Function: Encodes integer values onto a "blank" binary genome canvas

void encode(BINARY_TYPE noncoded_genome, BINARY_TYPE* genome_canvas, int descriptor_offset, int num_descriptors, int trait_offset, int length, int offset){
	
	BINARY_TYPE NON_CODED_COPY = noncoded_genome;

	//Shifts the non_coded genome to be ANDED with the appropriate integer
	for (int i = 0; i < descriptor_offset-1; i++){
		NON_CODED_COPY = (NON_CODED_COPY/10); 
	}
	
	//Loops through and encodes all traits of the feature.
	for (int i = 0; i < num_descriptors; i++){
		BINARY_TYPE temp; //Evaluated integer
	
		//Grabs decoded number defining the feature
		temp = (NON_CODED_COPY%10);
		NON_CODED_COPY = (NON_CODED_COPY/10);
		
		//Trait Offset (ie How many traits read in feature)
		trait_offset = i*length;

		//Shifts temp to the appropriate position to be
		//ANDED with the genome_canvas.
		temp = ( temp << (offset + trait_offset));
	
		//Adds the binary interpretation of the 
		// encoded feature to the genome canvas.
		*genome_canvas = (temp | *genome_canvas);		
	}
	return;	
}

//Decode Function: Decodes single traits from within the encoded genome
int decode_trait(const BINARY_TYPE* encoded_genome, int offset, int trait_offset, int length) {
	
	BINARY_TYPE GENOME_COPY = *encoded_genome;

	GENOME_COPY = (*encoded_genome >> (offset + trait_offset));

	int mask = (pow(2,length) -1);	
	int trait_number = 0;	  
	trait_number = (GENOME_COPY & mask);
	
	return trait_number;
}

//Get Feature Function
// This function returns the strings of a specfic critter into 
// an easy to access vector containing all of the traits of that feature 
// for the critter...

void get_Features(std::vector<std::string>* phenotype, int num_descriptors, int feature_offset, int trait_offset, int length, std::map<std::string, std::array<std::string, 4>> feature_map, std::vector<std::string> traits, BINARY_TYPE encoded_Genome) {
//Passing a Map.

	//Variable that temporarily holds the string	
	std::string var;
		
	for (int i = 0; i < num_descriptors; i++){			
		//Keeps track of which decode trait is evaluated
		trait_offset = i*length; 
		/*Gets trait strings using the encoded genome & trait maps*/
		var = feature_map[traits.at(i)][decode_trait(&encoded_Genome, feature_offset, trait_offset, length)];	
		/*Pushes the string traits into the critter trait feature vector*/
		phenotype->push_back(var);
	}
	
	return;
}


