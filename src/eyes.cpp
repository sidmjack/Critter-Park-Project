#include <eyes.hpp>
#include <map>
#include <string>
#include <bitset>

class Eyes{
	
	public:
	/*Information Accessible to the User*/
		
	private:
	
	/*Feature Maps*/
	std::map<int, std::string> size_map;

	size_map[1] = "beady";
	size_map[2] = "little";
	size_map[3] = "large";
	size_map[4] = "gigantic";

	std::map<int, std::string> pupil_map;

	pupil_map[1] = "indiscernible";
	pupil_map[2] = "slit";
	pupil_map[3] = "compound";
	pupil_map[4] = "round";
	
	std::map<int, std::string> color_map;

	color_map[1] = "blood-shot";
	color_map[2] = "azure";
	color_map[3] = "emerald";
	color_map[4] = "golden";

	std::map<int, std::string> number_map;

	number_map[1] = "one";
	number_map[2] = "two";
	number_map[3] = "four";
	number_map[4] = "eight";


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

