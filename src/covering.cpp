/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Covering.cpp - Defines the map key/store values, the number of descriptors
 * and the length of the bits required to define the descriptors.
 * 
 * Last Modified: November 2, 2015
 * *****************************************************************************/
//#include "trait.hpp"
#include "binary.hpp"
#include "covering.hpp"
#include <map>
#include <vector> 
#include <string>
#include <bitset>
	
Covering::Covering() {

	/*Information Accessible to the User*/
	std::string coat;
	std::string texture;
	
	/*Define which trait stings map to what descriptor string*/		
	covering_map["coat"] = {"pelt","set of scales","layer of plumes","leather hide"};
	covering_map["texture"] = {"smooth","course","slimy","bristly"};

	//The Feature's Trait
	feature_trait;
	//The Vector of Trait Strings
	std::vector<std::string> string_traits = {coat, texture};
	//The function that sets the Feature Trair.
	feature_trait.setTraits(std::vector<std::string>{this->coat, this->texture});

}
	

/************************ ENCODE/DECODE FUNCTIONS ****************************/

void Covering::encode (Binary &genotype, unsigned &offset) const {

 	genotype.setBitField(offset, 2, COAT_descriptor);
 	offset += 2;
  	genotype.setBitField(offset, 2, TEXTURE_descriptor);
  	offset += 2;
	return;
}

void Covering::decode (const Binary &genotype, unsigned &offset) {

  	COAT_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->coat = covering_map["coat"][COAT_descriptor]; 

  	TEXTURE_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->texture = covering_map["texture"][TEXTURE_descriptor]; 
	return;
	
	this->updateTrait();
}

void Covering::updateTrait(){
  this->feature_trait.setTraits(std::vector<std::string>{this->texture, this->coat});
}

/*****************************************************************************/

//UNIT TEST:
void Covering::unitTest () {
	
	//Testing Decode Function
	
	Covering mock_Covering;
	Binary mock_Binary = 0;
	unsigned int mock_Offset = 0;
	
	std::cout << "Beginning unit tests for Covering Class Functions...\n";
		
	//Decode Function
	mock_Covering.decode(mock_Binary, mock_Offset);

	std::string trait_1 = mock_Covering.coat;
	std::string trait_2 = mock_Covering.texture;

	std::cout << "Trait 1: " << trait_1 << "\n";
	std::cout << "Trait 2: " << trait_2 << "\n"; 

	//Because the trait string for a Binary Genome initialized to 
	//zero results in the trait strings "pelt" and "smooth", we 
	//know that the decode function works if the strings it returns
	//are "pelt" and "smooth". 
	
	if (((trait_1 == "pelt") & (trait_2 == "smooth"))){
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
	mock_Covering.encode(mock_Binary, mock_Offset);
	mock_Covering.decode(mock_Binary, mock_Offset);
	
	std::cout << "\n";

	trait_1 = mock_Covering.coat;
	trait_2 = mock_Covering.texture;

	std::cout << "Trait 1: " << trait_1 << "\n";
	std::cout << "Trait 2: " << trait_2 << "\n"; 

	// Because the trait string for the Binary Genome now is initialized to 
	// all ones the trait string results become "leather hide" and
	// "bristly". We know that the decode function works if the strings
	// it returns are then "leather hide" and "bristly". 
	
	if (((trait_1 == "leather hide") & (trait_2 == "bristly"))){
		std::cout << "ENCODE/DECODE: PASSED!\n\n";
	} else { 
		std::cout << "ENCODE/DECODE: FAILED!\n\n";
	}

	std::cout << "Finished unit tests for Covering Class Functions.\n";
	
	return;
}
	

	

