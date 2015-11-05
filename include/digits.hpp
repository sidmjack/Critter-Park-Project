/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Digits.hpp - Contains declaration for the digits feature/trait map, 
 * the number of descriptors for the digits feature, and the bit length
 * of the traits defining the digits feature.
 *
 * Last Modified: November 2, 2015
 * *****************************************************************************/

#ifndef HW8_DIGITS_H
#define HW8_DIGITS_H

#include "binary.hpp"
#include <string>
#include <map>
#include <vector>

class Digits{	

	/*********************************************************************/

	public:
	
	Digits();

	/*Information Accessible to the User*/
	std::string type;
	std::string amount;

	 void encode(Binary &genotype, unsigned &offset) const;
         void decode(const Binary &genotype, unsigned &offset);

	/********************************************************************/
	
	private:

	/*Feature Traits*/
	int TYPE_descriptor, AMOUNT_descriptor;

	/*Feature Map*/
	std::map<std::string, std::array<std::string, 4>> digits_map;	

	/*********************************************************************/

};

#endif
