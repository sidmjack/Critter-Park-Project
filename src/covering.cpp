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
#include "binary.hpp"
#include <map>
#include <vector> 
#include <string>
#include <bitset>
	
	Cover::Cover() {

	/*NEW FEATURE MAP!*/
	/* Finally realized that having a single map containing trait string 
	 * keys that map to an array of their descriptors is probs
	 * WAYYY more efficient than having a map for each trait.*/
	
	/*Define which trait stings map to what descriptor string*/		
	covering_map[coat] = {"pelt","set of scales","layer of plumes","leather hide"};
	covering_map[texture] = {"smooth","course","slimy","bristly"};
	
	/*Defines how many descriptors each feature class contains*/
	num_descriptors = 2;
	
	/*Defines the number of bits needed to categorize those features*/
	length = 2;
	
	}
	
	/*Covering Offset Information: */
	   //First Segment (4 Bits)
  	   //Coat Requires 2 bits (1-2)
	   //Texture Requires 2 bits (3-4)

