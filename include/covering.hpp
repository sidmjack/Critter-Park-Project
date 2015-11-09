/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Covering.hpp - Contains declaration for covering feature/trait map, 
 * the number of descriptors for the cover feature, and the bit length
 * of the traits defining the covering feature.
 *
 * Last Modified: November 2, 2015
 * *****************************************************************************/

#ifndef HW8_COVERING_H
#define HW8_COVERING_H

#include "binary.hpp"
#include <string>
#include <map>
#include <vector>

class Covering{
	
	/*********************************************************************/

	public:
	
	Covering();

	/*Information Accessible to the User*/
	std::string coat;
	std::string texture;
 	
	 void encode(Binary &genotype, unsigned &offset) const;
         void decode(const Binary &genotype, unsigned &offset);

	 static void unitTest();


	/********************************************************************/
	
	private:

	/*Feature Traits*/
	int COAT_descriptor, TEXTURE_descriptor;

	/*Feature Map*/
	std::map<std::string, std::array<std::string, 4>> covering_map;	

	/*********************************************************************/

};

#endif
