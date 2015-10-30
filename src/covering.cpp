#include <covering.hpp>
#include <binary.hpp>
#include <map>
#include <vector> 
#include <string>
#include <bitset>
	
	/*Feature Maps*/
	//Use vectors/arrays, probably is the easiest option.
	Cover::Cover(){
	
	coat_map[1] = "pelt";
	coat_map[2] = "scales";
	coat_map[3] = "leather hide";
	coat_map[4] = "plumes";

	texture_map[1] = "smooth";
	texture_map[2] = "course";
	texture_map[3] = "slimy";
	texture_map[4] = "bristly";
	
	/*Defines how many descriptors each feature class contains*/
	num_descriptors = 2;
	/*Defines the number of bits needed to categorize those features*/
	length = 2;
	
	}
	
	/*Covering Offset Information: */
	//First Segment (4 Bits)
	//Coat Requires 2 bits (1-2)
	//Texture Requires 2 bits (3-4)
	
	/*CRITTER GENOME FUNCTIONS*/

	//Important Note: Genome is encoded from right to left with the
	//assumption that the beginning of the genome is to the far right.

	/*Encodes the integer map values to binary*/
	/*Offset = Segment's first instsance/position in the decoded genome.
	 *Decoded Segment = Entire Copy of Critter's Decoded Genome
	 *Genome Canvas = Basically a long int composed of zeroes.*/
	/*Encode uses OR operator against zero long int to produce 2b-genome*/

	unsigned long int encode(int genome_canvas, int decoded_segment, int offset){
	
		genome_canvas << offset;
	
		int i;
		for (i = 0; i < num_descriptors; i++){
			
			int temp; //Evaluated integer
			long int genome_canvas = 0;

			/*Grabs decoded number defining the feature*/
			temp = (decoded_segment % 10);
			decoded_segment = (decoded_segment/10);
			
			/*Adds the binary interpretation of the 
			 * encoded feature to the genome canvas.*/
			genome_canvas = (temp | genome_canvas);
			
			/*Shifts the genome canvas by the number
			 * of bits previously "used". */
			genome_canvas << length;
		}
	
		return encoded_bits;
	};

	/*Decodes the binary values to their associated integer map keys*/
	/*Offset = Segments first instance/ position in the encoded binary.
	 *Encoded_Genome = Entire Copy of Critter's Encoded Genome*/
	unsigned int decode(int encoded_genome, int offset){
		
		encoded_genome << offset;
	
		int mask = 2; //11 in binary
		int temp = 0; //Keeps track of evaluated decoded digits
	        int decoded_genome = 0;//Keeps track of decoded segment
		
		int i;
		for (i = 0; i < num_descriptors; i++){
			temp = (encoded_genome & mask);
			decoded_genome += temp;
			
			/*Ensures decoded genome has the right # of digits*/
			if (num_descriptors < num_descriptors-1){
				decoded_genome*=10;
			}
			
			/*Shifts the genome canvas by the number
			 * of bits previously "used". */
			encoded_genome << length;

		}
		/*Unlike enode, genome only returns the decoded values
		 * for a feature segment (instead of appending an
		 * entire "genome". Still trying to decide whether
		 * it'd be more usefule to return an entire string
		 * of the decoded genome.)*/

		return decoded_genome;
	};

