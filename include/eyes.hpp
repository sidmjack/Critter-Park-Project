/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Eyes.hpp - Contains declaration for eyes feature/trait map, 
 * the number of descriptors for the eyes feature, and the bit length
 * of the traits defining the eyes feature.
 *
 * Last Modified: November 2, 2015
 * *****************************************************************************/

#ifndef HW8_EYES_H
#define HW8_EYES_H

#include "binary.hpp"
#include <string>
#include <map>

class Eyes{
	
	public:
	/*Information Accessible to the User*/
		
	private:

	/*New Feature Map*/
	std::map<string, std::string[]> eyes_map;

	/*CRITTER GENOME FUNCTIONS*/

	/*Number of descriptors contained in a class*/
	int num_descriptors;
	/*Defines the number of bits needed to categorize those features*/
	int length;

}

#endif
