/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Digits.cpp - Defines the map key/store values, the number of descriptors
 * and the length of the bits required to define the descriptors.
 * 
 * Last Modified: November 2, 2015
 * *****************************************************************************/

//#include "trait.hpp"
#include "critter.hpp"
#include "binary.hpp"
#include "digits.hpp"
#include <map>
#include <vector> 
#include <string>
#include <bitset>
	
Digits::Digits() {

	/*Information Accessible to the User*/
	std::string type;
	std::string amount;
	
	/*Define which trait stings map to what descriptor string*/			       
	digits_map["type"] = {"toes","claws","fingers","talons"};
	digits_map["amount"] = {"two","three","five","seven"};

	//The Vector of Trait Strings
	std::vector<std::string> string_traits = {type, amount};
	//The function that sets the Feature Trair.
	feature_trait.setTraits(string_traits);

}
	
/************************ ENCODE/DECODE FUNCTIONS ****************************/

void Digits::encode (Binary &genotype, unsigned &offset) const {

 	genotype.setBitField(offset, 2, TYPE_descriptor);
 	offset += 2;
  	genotype.setBitField(offset, 2, AMOUNT_descriptor);
  	offset += 2;
}

void Digits::decode (const Binary &genotype, unsigned &offset) {

  	TYPE_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->type = digits_map["type"][TYPE_descriptor]; 

  	AMOUNT_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->amount = digits_map["amount"][AMOUNT_descriptor]; 
	
	this->updateTrait();
}

void Digits::updateTrait(){
  this->feature_trait.setTraits(std::vector<std::string>{this->type, this->amount});
}
/*****************************************************************************/

//UNIT TEST:
void Digits::unitTest () {
	
	//Testing Decode Function
	
	Digits mock_Digits;
	Binary mock_Binary = 0;
	unsigned int mock_Offset = 0;
	
	std::cout << "Beginning unit tests for Digits Class Functions...\n";
		
	//Decode Function
	mock_Digits.decode(mock_Binary, mock_Offset);

	std::string trait_1 = mock_Digits.type;
	std::string trait_2 = mock_Digits.amount;

	std::cout << "Trait 1: " << trait_1 << "\n";
	std::cout << "Trait 2: " << trait_2 << "\n"; 

	//Because the trait string for a Binary Genome initialized to 
	//zero results in the trait strings "two" and "toes", we 
	//know that the decode function works if the strings it returns
	//are "two" and "toes". 
	
	if (((trait_1 == "toes") & (trait_2 == "two"))){
		std::cout << "Decode: PASSED!\n\n";
	} else { 
		std::cout << "Decode: FAILED!\n\n";
	}
	
	/*********************************************************************/
	//Testing Encode Function:
	
	std::cout << "Displaying genome of current Binary Object.\n";
	std::cout << "Current Binary (BEFORE): ";
	printBinary(mock_Binary.getGenome());
	std::cout << "\n";

	std::cout << "Converting genome from 0 to largest binary representation.\n";
	mock_Binary.setGenome(~0);
	std::cout << "Current Binary (POST-CONVERSION): ";
	printBinary(mock_Binary.getGenome());
	std::cout << "\n";

	//Encode Function
	mock_Digits.encode(mock_Binary, mock_Offset);
	mock_Digits.decode(mock_Binary, mock_Offset);
	
	std::cout << "\n";

	trait_1 = mock_Digits.type;
	trait_2 = mock_Digits.amount;

	std::cout << "Trait 1: " << trait_1 << "\n";
	std::cout << "Trait 2: " << trait_2 << "\n"; 

	// Because the trait string for the Binary Genome now is initialized to 
	// all ones the trait string results become "seven" and
	// "talons". We know that the decode function works if the strings
	// it returns are then "seven" and "talons". 
	
	if (((trait_1 == "talons") & (trait_2 == "seven"))){
		std::cout << "ENCODE/DECODE: PASSED!\n\n";
	} else { 
		std::cout << "ENCODE/DECODE: FAILED!\n\n";
	}

	std::cout << "Finished unit tests for Digits Class Functions.\n";
	
	return;
}
	

