/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Eyes.cpp - Defines the map key/store values, the number of descriptors
 * and the length of the bits required to define the descriptors.
 * 
 * Last Modified: November 2, 2015
 * *****************************************************************************/


#include "eyes.hpp"
#include <map>
#include <vectors>
#include <string>
#include <bitset>

	/*Feature Maps/Vectors/Arrays*/
	
	Eyes:Eyes() {
	
	/*Define which trait stings map to what descriptor string*/		
	eyes_map["size"] = {"beady","little","large","mammoth"};
	eyes_map["pupil"] = {"indiscernible","slit","compound","round"};
	eyes_map["color"] = {"blood-shot","azure","emerald","golden"};
	eyes_map["number"] = {"one eye","two eyes","four eyes","eight eyes"};

	/*Defines how many descriptors each feature class contains*/
	num_descriptors = 4;
	
	/*Defines the number of bits needed to categorize those features*/
	length = 2;

	}
	
	/*Eyes Offset Information: */
	   //Third Segment (8 Bits)
	   //Size Requires 2 bits (1-2)
	   //Pupil Requires 2 bits (3-4)
	   //Color Requires 2 bits (5-6)
	   //Number Requires 2 bits (7-8)
	

