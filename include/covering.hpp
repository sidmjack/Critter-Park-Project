/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Covering.hpp - Contains declaration for covering feature/trait map, 
 * the number of descriptors for the cover feature, and the bit length
 * of the traits defining the covering feature.
 *
 * Last Modified: November 2, 2015
 * *****************************************************************************/


#ifndef HW8_COVERING_H
#define HW8_COVERING_H

#include "binary.hpp"
#include <string>
#include <map>

class Covering{
	
	public:
	
	/*Information Accessible to the User*/
	std::string coat;
	std::string texture;
		
	private:
	
	/*New Feature Map*/
	std::map<std::string, std::array<std::string, 4>> covering_map;
	
	/*Vector containing trait strings*/
	std::vector<std::string> traits;
	
	/*******************************************************************/
	/*Phenotype (AKA: String of Critter's Unique Traits)*/
	std::vector<std::string> phenotype;

	/* Get_Feature Function uses the phenotype vector above to 
	 * define the variables (accessible to Critter) containing
	 * the Critters traits.*/

	void get_Feature(std::vector<std::string>* phenotype);
	/********************************************************************/
	
	/*CRITTER GENOME FUNCTION VARIABLES*/

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
