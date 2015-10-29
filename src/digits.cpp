#include <digits.hpp>
#include <map>
#include <vector>
#include <string>
#include <bitset>

	
	/*Feature Maps/Arrays/Vectors*/
	Digits:Digits(){
	
	type_map[1] = "paws";
	type_map[2] = "claws";
	type_map[3] = "fingers";
	type_map[4] = "talons";

	amount_map[1] = "two";
	amount_map[2] = "three";
	amount_map[3] = "five";
	amount_map[4] = "seven";
	
	/*Defines how many descriptors each feature class contains*/
	num_descriptors = 2;
	/*Defines the number of bits needed to categorize those features*/
	length = 2;

	}
	
	/*Digits Offset Information: */
	//Second Segment (4 Bits)
	//Type Requires 2 bits (1-2)
	//Amount Requires 2 bits (3-4)

	/*CRITTER GENOME FUNCTIONS*/
	/*Encodes the integer map values to binary*/
	unsigned int encode(int decoded_segment){
		return encoded_bits;
	};

	/*Decodes the binary values to their associated integer map keys*/
	unsigned int decode(int encoded_segment){
		return decoded_bits;
	};


