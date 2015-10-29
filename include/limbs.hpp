#ifndef HW8_LIMBS_H
#define HW8_LIMBS_H

class Limbs{
	
	public:
	/*Information Accessible to the User*/
		
	private:
	
	/*Feature Maps*/
	std::map<int, std::string> limb_num_map;

	std::map<int, std::string> limb_shape_map;
	
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
