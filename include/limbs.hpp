/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Limbs.hpp - Contains declaration for limbs feature/trait map, 
 * the number of descriptors for the limbs feature, and the bit length
 * of the traits defining the limbs feature.
 *
 * Last Modified: November 2, 2015
 * *****************************************************************************/

#ifndef HW8_LIMBS_H
#define HW8_LIMBS_H

#include "binary.hpp"
#include <string>
#include <map>

class Limbs{
	
	public:
	/*Information Accessible to the User*/
		
	
	
	/*New Feature Map*/
	std::map<std::string, std::array<std::string, 4>> limbs_map;

	/*Vector containing trait strings*/
	std::vector<std::string> traits;
	
	/*CRITTER GENOME FUNCTION VARIABLES*/
	
	/*String Traits*/
	std::string number;
	std::string shape;

	/*Number of descriptors contained in a class*/
	int num_descriptors;
	
	/*Defines the number of bits needed to categorize those features*/
	int length;

	/*The offset of the feature..specifies where feature starts in genome.*/
	int offset; //Feature Offset
	int trait_offset; // Trait Offset
	int descriptor_offset; //Trait # of the first feature trait (relative to genome).


};

#endif
