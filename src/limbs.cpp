#include <limbs.hpp>
#include <map>
#include <vectors>
#include <string>
#include <bitset>

	/*Feature Maps/Vectors/Arrays*/
	
	Limbs:Limbs() {

	limb_num_map[1] = "two";
	limb_num_map[2] = "four";
	limb_num_map[3] = "six";
	limb_num_map[4] = "eight";

	limb_shape_map[1] = "spindles";
	limb_shape_map[2] = "tentacles";
	limb_shape_map[3] = "forelegs";
	limb_shape_map[4] = "stubs";

	/*Defines how many descriptors each feature class contains*/
	num_descriptors = 2;
	/*Defines the number of bits needed to categorize those features*/
	length = 2;


	}

	/*Limbs Offset Information: */
	//Fourth Segment (4 Bits)
	//Limb_Num Requires 2 bits (1-2)
	//Limb_Shape Requires 2 bits (3-4)

	/*CRITTER GENOME FUNCTIONS*/
	/*Encodes the integer map values to binary*/
	unsigned int encode(int decoded_segment){
		return encoded_bits;
	};

	/*Decodes the binary values to their associated integer map keys*/
	unsigned int decode(int encoded_segment){
		return decoded_bits;
	};

