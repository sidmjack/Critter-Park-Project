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
}
	
/************************ ENCODE/DECODE FUNCTIONS ****************************/

void Covering::encode (Binary &genotype, unsigned &offset) const {

 	genotype.setBitField(offset, 2, COAT_descriptor);
 	offset += 2;
  	genotype.setBitField(offset, 2, TEXTURE_descriptor);
  	offset += 2;
}

void Covering::decode (const Binary &genotype, unsigned &offset) {

  	COAT_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->coat = covering_map["coat"][COAT_descriptor]; 

  	TEXTURE_descriptor = genotype.getBitField(offset, 2);
  	offset += 2;
	this->texture = covering_map["texture"][TEXTURE_descriptor]; 
}

/*****************************************************************************/

	

	

