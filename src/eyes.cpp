#include <eyes.hpp>
#include <map>
#include <vectors>
#include <string>
#include <bitset>

	/*Feature Maps/Vectors/Arrays*/
	Eyes:Eyes() {
	
	size_map[1] = "beady";
	size_map[2] = "little";
	size_map[3] = "large";
	size_map[4] = "gigantic";

	pupil_map[1] = "indiscernible";
	pupil_map[2] = "slit";
	pupil_map[3] = "compound";
	pupil_map[4] = "round";
	
	color_map[1] = "blood-shot";
	color_map[2] = "azure";
	color_map[3] = "emerald";
	color_map[4] = "golden";

	number_map[1] = "one";
	number_map[2] = "two";
	number_map[3] = "four";
	number_map[4] = "eight";

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

	/*CRITTER GENOME FUNCTIONS*/
	/*Encodes the integer map values to binary*/
	unsigned int encode(int decoded_segment){
		return encoded_bits;
	};

	/*Decodes the binary values to their associated integer map keys*/
	unsigned int decode(int encoded_segment){
		return decoded_bits;
	};

