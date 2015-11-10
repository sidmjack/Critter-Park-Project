/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Limbs.hpp - Contains declaration for limbs feature/trait map, 
 * the number of descriptors for the limbs feature, and the bit length
 * of the traits defining the limbs feature.
 *
 * Last Modified: November 2, 2015
 * *****************************************************************************/

#ifndef HW8_LIMBS_H
#define HW8_LIMBS_H

#include "trait.hpp"
#include <string>
#include <map>
#include <vector>
#include "binary.hpp"

class Limbs{
			
	public:
	
	Limbs();

	/*Information Accessible to the User*/
	std::string number;
	std::string shape;

	//Vector of Strings 
	std::vector<std::string> string_traits;
	//Feature Trait
	Trait feature_trait;

	 void encode(Binary &genotype, unsigned &offset) const;
         void decode(const Binary &genotype, unsigned &offset);

	 static void unitTest();


	/********************************************************************/
	
	private:

	/*Feature Traits*/
	int NUMBER_descriptor, SHAPE_descriptor;

	/*Feature Map*/
	std::map<std::string, std::array<std::string, 4>> limbs_map;	

	/*********************************************************************/
};

#endif
