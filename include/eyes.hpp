/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Eyes.hpp - Contains declaration for eyes feature/trait map, 
 * the number of descriptors for the eyes feature, and the bit length
 * of the traits defining the eyes feature.
 *
 * Last Modified: November 2, 2015
 * *****************************************************************************/

#ifndef HW8_EYES_H
#define HW8_EYES_H

#include <string>
#include <map>
#include <vector>
#include "binary.hpp"

class Eyes{
	
	public:
	
	Eyes();

	/*Information Accessible to the User*/
	std::string size;
	std::string pupil;
	std::string color;
	std::string number;

	 void encode(Binary &genotype, unsigned &offset) const;
         void decode(const Binary &genotype, unsigned &offset);

	/********************************************************************/
	
	private:

	/*Feature Traits*/
	int SIZE_descriptor, PUPIL_descriptor, COLOR_descriptor, NUMBER_descriptor;

	/*Feature Map*/
	std::map<std::string, std::array<std::string, 4>> eyes_map;	

	/*********************************************************************/	

};

#endif
