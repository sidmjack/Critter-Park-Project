#include <covering.hpp>
#include <map>
#include <string>
#include <bitset>

class Cover{
	
	public:
	/*Information Accessible to the User*/
		
	private:
	
	/*Feature Maps*/
	std::map<int, std::string> coat_map;

	coat_map[1] = "pelt";
	coat_map[2] = "scales";
	coat_map[3] = "leather hide";
	coat_map[4] = "plumes";

	std::map<int, std::string> texture_map;

	texture_map[1] = "smooth";
	texture_map[2] = "course";
	texture_map[3] = "slimy";
	texture_map[4] = "bristly";
	
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

