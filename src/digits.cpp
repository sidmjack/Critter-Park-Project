#include <digits.hpp>
#include <map>
#include <string>
#include <bitset>

class Digits{
	
	public:
	/*Information Accessible to the User*/
		
	private:
	
	/*Feature Maps*/
	std::map<int, std::string> type_map;

	type_map[1] = "paws";
	type_map[2] = "claws";
	type_map[3] = "fingers";
	type_map[4] = "talons";

	std::map<int, std::string> amount_map;

	amount_map[1] = "two";
	amount_map[2] = "three";
	amount_map[3] = "five";
	amount_map[4] = "seven";
	
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

