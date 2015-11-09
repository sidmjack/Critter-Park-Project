/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Limbs.cpp - Defines the map key/store values, the number of descriptors
 * and the length of the bits required to define the descriptors.
 * 
 * Last Modified: November 2, 2015
 * *****************************************************************************/

#include "binary.hpp"
#include "limbs.hpp"
#include <map>
#include <vector>
#include <string>
#include <bitset>

Limbs::Limbs() {

	/*Information Accessible to the User*/
	std::string number;
	std::string shape;
	
	/*Define which trait stings map to what descriptor string*/		
	limbs_map["number"] = {"two","four","six","eight"};
	limbs_map["shape"] = {"spindles","tentacles","forelegs","stubs"};
}
	
/************************ ENCODE/DECODE FUNCTIONS ****************************/

void Limbs::encode (Binary &genotype, unsigned &offset) const {

 	genotype.setBitField(offset, 2, NUMBER_descriptor);
 	offset += 2;
  	genotype.setBitField(offset, 2, SHAPE_descriptor);
  	offset += 2;
}

void Limbs::decode (const Binary &genotype, unsigned &offset) {

  	NUMBER_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->number = limbs_map["number"][NUMBER_descriptor]; 

  	SHAPE_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->shape = limbs_map["shape"][SHAPE_descriptor]; 
}

/*****************************************************************************/

//UNIT TEST:
void Limbs::unitTest () {
	
	//Testing Decode Function
	
	Limbs mock_Limbs;
	Binary mock_Binary = 0;
	unsigned int mock_Offset = 0;
	
	std::cout << "Beginning unit tests for Limbs Class Functions...\n";
		
	//Decode Function
	mock_Limbs.decode(mock_Binary, mock_Offset);

	std::string trait_1 = mock_Limbs.number;
	std::string trait_2 = mock_Limbs.shape;

	std::cout << "Trait 1: " << trait_1 << "\n";
	std::cout << "Trait 2: " << trait_2 << "\n"; 
	
	if (((trait_1 == "two") & (trait_2 == "spindles"))){
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
	mock_Limbs.encode(mock_Binary, mock_Offset);
	mock_Limbs.decode(mock_Binary, mock_Offset);
	
	std::cout << "\n";

	trait_1 = mock_Limbs.number;
	trait_2 = mock_Limbs.shape;

	std::cout << "Trait 1: " << trait_1 << "\n";
	std::cout << "Trait 2: " << trait_2 << "\n"; 
	
	if (((trait_1 == "eight") & (trait_2 == "stubs"))){
		std::cout << "ENCODE/DECODE: PASSED!\n\n";
	} else { 
		std::cout << "ENCODE/DECODE: FAILED!\n\n";
	}

	std::cout << "Finished unit tests for Limbs Class Functions.\n";
	
	return;
}
	
	

