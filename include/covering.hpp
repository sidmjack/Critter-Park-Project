#ifndef HW8_COVERING_H
#define HW8_COVERING_H

class Cover{
	
	public:
	/*Information Accessible to the User*/
		
	private:
	
	/*Feature Maps*/
	std::map<int, std::string> coat_map;

	std::map<int, std::string> texture_map;
	
	/*CRITTER GENOME FUNCTIONS*/

	/*Number of descriptors contained in a class*/
	int num_descriptors;

	/*Encodes the integer map values to binary*/
	unsigned int encode(int decoded_segment);

	/*Decodes the binary values to their associated integer map keys*/
	unsigned int decode(int encoded_segment);
}

#endif
