/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Limbs.cpp - Defines the map key/store values, the number of descriptors
 * and the length of the bits required to define the descriptors.
 * 
 * Last Modified: November 2, 2015
 * *****************************************************************************/


#include "limbs.hpp"
#include <map>
#include <vectors>
#include <string>
#include <bitset>

	/*Feature Maps/Vectors/Arrays*/
	
	Limbs:Limbs() {
	
	/*Define which trait stings map to what descriptor string*/	      
	limbs_map["number"] = {"two","four","six","eight"};
	limbs_map["shape"] = {"spindles","tentacles","forelegs","stubs"};

	/*Defines how many descriptors each feature class contains*/
	num_descriptors = 2;

	/*Defines the number of bits needed to categorize those features*/
	length = 2;

	}

	/*Limbs Offset Information: */
	   //Fourth Segment (4 Bits)
	   //Limb_Num Requires 2 bits (1-2)
	   //Limb_Shape Requires 2 bits (3-4)

