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

#include "binary.hpp"

// this is so temporary it's not even funny
//#include "binary.cpp"

#include "eyes.hpp"
#include "covering.hpp"
#include "limbs.hpp"
#include "digits.hpp"


class Critter{
 public:
  // returns the name of the Critter
  std::string const getName();

  // changes the name of the Critter
  void setName(std::string name);

  // returns the Binary encoding of the Critter
  Binary getBinary();

  // sets the Binary encoding of the Critter
  void setBinary(Binary newBinary);

  // prints a neatly formatted bio abot this Critter
  void printCritter();

  // default constructor
  Critter();

  // destructor
  ~Critter();

  // breeding mechanism
  void parents(Critter mommy, Critter daddy, float jitter);

  // mutation mechanism
  void mutate(float severity);

  // the Critter class unit test
  void unitTest();

  // overload the = operator
  void operator= (const Critter &other);

  // overload the == operator
  bool operator== (const Critter &other);

  // variables for describing the Critter
  std::string name;
  float cuteness;
  float scariness;
  float strangeness;

  // features that this Critter has
  Covering covering;
  Eyes eyes;
  Limbs limbs;
  Digits digits;

  private:

  // the Critter's genes
  Binary binary;
  
};

  // overload the << operator
  std::ostream & operator<< (std::ostream & os, const Critter &c);

#endif
