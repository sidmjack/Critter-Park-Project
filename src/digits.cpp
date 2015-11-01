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

	
	Digits:Digits(){
	
	/*Defines which traits are in the vector*/	       
	std::vector<std::string> traits = {"type", "amount"};
		  
	/*Define which trait stings map to what descriptor string*/		       
	digits_map["type"] = {"toes","claws","fingers","talons"};
	digits_map["amount"] = {"two","three","five","seven"};
		
	/*Defines how many descriptors each feature class contains*/
	num_descriptors = 2;

	/*Defines the number of bits needed to categorize those features*/
	length = 2;
	
		/*Digits Offset Information (2): */
  	   //Second Segment (4 Bits)
	   //Type Requires 2 bits (1-2)
	   //Amount Requires 2 bits (3-4)

	/*The offset of the feature..specifies where feature starts in genome.*/
	offset = 4;
	trait_offset = 0;

	}
	



