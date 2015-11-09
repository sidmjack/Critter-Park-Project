/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Eyes.cpp - Defines the map key/store values, the number of descriptors
 * and the length of the bits required to define the descriptors.
 * 
 * Last Modified: November 2, 2015
 * *****************************************************************************/

#include "binary.hpp"
#include <map>
#include <vector>
#include <string>
#include <bitset>
#include "eyes.hpp"
		
Eyes::Eyes() {

	/*Information Accessible to the User*/
	std::string size;
	std::string pupil;
	std::string color;
	std::string number;

	/*Define which trait stings map to what descriptor string*/		
	eyes_map["size"] = {"beady","little","large","mammoth"};
	eyes_map["pupil"] = {"indiscernible","slit","compound","round"};
	eyes_map["color"] = {"blood-shot","azure","emerald","golden"};
	eyes_map["number"] = {"one","two","four","eight"};
}
	
/************************ ENCODE/DECODE FUNCTIONS ****************************/

void Eyes::encode (Binary &genotype, unsigned &offset) const {

 	genotype.setBitField(offset, 2, SIZE_descriptor);
 	offset += 2;
  	genotype.setBitField(offset, 2, PUPIL_descriptor);
  	offset += 2;
	genotype.setBitField(offset, 2, COLOR_descriptor);
 	offset += 2;
  	genotype.setBitField(offset, 2, NUMBER_descriptor);
  	offset += 2;

}

void Eyes::decode (const Binary &genotype, unsigned &offset) {

  	SIZE_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->size = eyes_map["size"][SIZE_descriptor]; 

  	PUPIL_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->pupil = eyes_map["pupil"][PUPIL_descriptor]; 

	COLOR_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->color = eyes_map["color"][COLOR_descriptor]; 

  	NUMBER_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->number = eyes_map["number"][NUMBER_descriptor]; 

}

/*****************************************************************************/

//UNIT TEST:
void Eyes::unitTest () {
	
	//Testing Decode Function
	
	Eyes mock_Eyes;
	Binary mock_Binary = 0;
	unsigned int mock_Offset = 0;
	
	std::cout << "Beginning unit tests for Eyes Class Functions...\n";
		
	//Decode Function
	mock_Eyes.decode(mock_Binary, mock_Offset);

	std::string trait_1 = mock_Eyes.size;
	std::string trait_2 = mock_Eyes.pupil;
	std::string trait_3 = mock_Eyes.color;
	std::string trait_4 = mock_Eyes.number;

	std::cout << "Trait 1: " << trait_1 << "\n";
	std::cout << "Trait 2: " << trait_2 << "\n"; 
	std::cout << "Trait 3: " << trait_3 << "\n";
	std::cout << "Trait 4: " << trait_4 << "\n"; 
	
	if (((trait_1 == "beady") & (trait_2 == "indiscernible") &
		(trait_3 == "blood-shot") & (trait_4 == "one"))){
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
	mock_Eyes.encode(mock_Binary, mock_Offset);
	mock_Eyes.decode(mock_Binary, mock_Offset);
	
	std::cout << "\n";

	trait_1 = mock_Eyes.size;
	trait_2 = mock_Eyes.pupil;
	trait_3 = mock_Eyes.color;
	trait_4 = mock_Eyes.number;

	std::cout << "Trait 1: " << trait_1 << "\n";
	std::cout << "Trait 2: " << trait_2 << "\n"; 
	std::cout << "Trait 3: " << trait_3 << "\n";
	std::cout << "Trait 4: " << trait_4 << "\n"; 


	if (((trait_1 == "mammoth") & (trait_2 == "round") &
		(trait_3 == "golden") & (trait_4 == "eight"))){
		std::cout << "Decode: PASSED!\n\n";
	} else { 
		std::cout << "Decode: FAILED!\n\n";
	}
	
	std::cout << "Finished unit tests for Eyes Class Functions.\n";
	
	return;
}
	

