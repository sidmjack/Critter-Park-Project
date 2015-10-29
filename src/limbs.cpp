#include <limbs.hpp>
#include <map>
#include <string>
#include <bitset>

class Limbs{
	
	public:
	/*Information Accessible to the User*/
		
	private:
	
	/*Feature Maps*/
	std::map<int, std::string> limb_num_map;

	limb_num_map[1] = "two";
	limb_num_map[2] = "four";
	limb_num_map[3] = "six";
	limb_num_map[4] = "eight";

	std::map<int, std::string> limb_shape_map;

	limb_shape_map[1] = "spindles";
	limb_shape_map[2] = "tentacles";
	limb_shape_map[3] = "forelegs";
	limb_shape_map[4] = "stubs";
	
	/*CRITTER GENOME FUNCTIONS*/
	/*Encodes the integer map values to binary*/
	unsigned int encode(int decoded_segment){
		return encoded_bits;
	};

	/*Decodes the binary values to their associated integer map keys*/
	unsigned int encode(int decoded_segment){
		return encoded_bits;
	};

}

