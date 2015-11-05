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
}

/*****************************************************************************/


