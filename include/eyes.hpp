#ifndef HW8_EYES_H
#define HW8_EYES_H

class Eyes{
	
	public:
	/*Information Accessible to the User*/
		
	private:
	
	/*Feature Maps*/
	std::map<int, std::string> size_map;

	std::map<int, std::string> pupil_map;

	std::map<int, std::string> color_map;

	std::map<int, std::string> number_map;
	
	/*CRITTER GENOME FUNCTIONS*/

	/*Number of descriptors contained in a class*/
	int num_descriptors;
	/*Defines the number of bits needed to categorize those features*/
	int length;

	/*Encodes the integer map values to binary*/
	unsigned int encode(int decoded_segment);

	/*Decodes the binary values to their associated integer map keys*/
	unsigned int decode(int encoded_segment);
}

#endif
