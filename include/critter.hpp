/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Critter.hpp - Contains the functions and variables that allow
 * the user create/ manipulate (to a point) the critter. Also contains
 * the variables that ultimately define the critter.
 *
 * Last Modified: November 2, 2015
 * *****************************************************************************/


#ifndef HW8_CRITTER_UTILS
#define HW8_CRITTER_UTILS

#include <iostream>
#include "binary.hpp"
#include "covering.hpp"
#include "digits.hpp"
#include "eyes.hpp"
#include "limbs.hpp"

class Critter{
 
  public:
  // Returns the Name of the Critter
  std::string const getName();

  // Changes the Name of the Critter
  void setName(std::string name);

  // Returns the Binary Encoding of the Critter
  Binary getBinary();

  // sets the Binary encoding of the Critter
  void setBinary(Binary newBinary);

  // Prints Critter Bio
  void printCritter();

  void set_Binary();

  void get_Features(Binary binary);

  void set_Features();

  // Constructor
  Critter(const Binary genotype = 0);
	
  // Destructor
  ~Critter();

  // Breeding Mechanism
  void parents(Critter mommy, Critter daddy, float jitter);

  // Mutation Mechanism
  void mutate(float severity);

  //Critter Class Unit Test
  static void unitTest();

/****************************OPERATOR OVERLOAD********************************/
  
  // Overload the = Operator
  void operator= (const Critter &other);

  // Overload the == Operator
  bool operator== (const Critter &other);

/*TEMPORARY: SHOULD BE PRIVATE*/
    std::string name;

/*****************************************************************************/

 private:

  // Variables Describing Critter
  float cuteness;
  float scariness;
  float strangeness;

  // Critter's Features
  Covering covering;
  Eyes eyes;
  Limbs limbs;
  Digits digits;

  //Critter's Genome
  Binary genotype;
  
};


  // overload the << operator
  std::ostream & operator<< (std::ostream & os, const Critter &c);

#endif
