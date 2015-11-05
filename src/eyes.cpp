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


