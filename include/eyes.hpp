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
	std::string size;
	std::string pupil;
	std::string color;
	std::string number;

	private:

	/*New Feature Map*/
	std::map<std::string, std::array<std::string, 4>>eyes_map;

	/*Vector containing trait strings*/
	std::vector<std::string> traits;

	/*CRITTER GENOME FUNCTIONS VARIABLES*/

	/*Number of descriptors contained in a class*/
	int num_descriptors;
	
	/*Defines the number of bits needed to categorize those features*/
	int length;

	/*The offset of the feature..specifies where feature starts in genome.*/
	int offset; //Feature Offset
	int trait_offset; //Trait Offset
	int descriptor_offset; //Trait # of the first feature trait (relative to genome).


};

#endif
