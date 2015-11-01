/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Digits.hpp - Contains declaration for the digits feature/trait map, 
 * the number of descriptors for the digits feature, and the bit length
 * of the traits defining the digits feature.
 *
 * Last Modified: November 2, 2015
 * *****************************************************************************/

#ifndef HW8_DIGITS_H
#define HW8_DIGITS_H

#include "binary.hpp"
#include <string>
#include <map>

class Digits{
	
	public:
	/*Information Accessible to the User*/
		
	private:
	
	/*NEW FEATURE MAP!*/
	std::map<std::string, std::array<std::string, 4>> digits_map;
		
	/*CRITTER GENOME FUNCTIONS*/

	/*Number of descriptors contained in a class*/
	int num_descriptors;
	/*Defines the number of bits needed to categorize those features*/
	int length;
};

#endif
