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

	/*Defines which trait strings are in the vector*/
	/*std::vector<std::string>*/ traits = {"coat", "texture"};

	/*Define which trait stings map to what descriptor string*/		
	covering_map[coat] = {"pelt","set of scales","layer of plumes","leather hide"};
	covering_map[texture] = {"smooth","course","slimy","bristly"};

	/*****************************************************************/
	/*Critter Genome*/
	genome = 0;

	/*Phenotype Vector*/
	phenotype = {" ", " "};

	/*****************************************************************/

	/*Trait Strings*/
	coat = " ";
	texture = " ";

	/*Defines how many descriptors each feature class contains*/
	num_descriptors = 2;
	
	/*Defines the number of bits needed to categorize those features*/
	length = 2;

		/*Covering Offset Information (1): */
	   //First Segment (4 Bits)
  	   //Coat Requires 2 bits (1-2)
	   //Texture Requires 2 bits (3-4)

	/*The offset of the feature..specifies where feature starts in genome.*/
	offset = 0;
	trait_offset = 0;
	descriptor_offset = 1;

	}
	
	/*Get Feature Function*/

	void Covering::get_Feature(std::vector<std::string>& phenotype){
		Binary::get_Features(phenotype, num_descriptors, offset, trait_offset, length, covering_map, traits, genome);
		return;
	} 
	

	

