/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Binary.hpp - contains definitions for functions used in printing and
 *     manipulating the binary strings used to store Critter traits.
 *
 * Last Modified November 2, 2015
 *****************************************************************************/

#ifndef HW8_BINARY_H
#define HW8_BINARY_H

//// if we need more than a long, change it here: ////
///                                                ///
             #define BINARY_TYPE long int          ///
///                                                ///
//////////////////////////////////////////////////////

#include <array>
#include <vector>
#include <map>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <random>

class Binary{
  
  public:
 
  /******************************* BASIC STUFF *******************************/
  // Constructor
 Binary (BINARY_TYPE genotype = 0);

  // Destructor
  ~Binary();

   static std::uniform_int_distribution<BINARY_TYPE> uniform_ul;

   static std::uniform_real_distribution<double> double_ul;

  /************************** BIT-FIELD FUNCTIONS ****************************/
  
  //Gets Bit Field
    unsigned getBitField(unsigned offset, unsigned length) const;
 
  //Sets Bit Field   
    void setBitField(unsigned offset, unsigned length, unsigned value);


  /************************* MATE CRITTER FUNCTIONS **************************/
  
  // Wrapper for the cross function
  void cross(Binary parent1, Binary parent2, float jitter);

  // Wrapper for the mutate function
  void mutate(float severity);


  /***************** FUNCTIONS USED BY OTHER FUNCTIONS ***********************/
  
  // function for crossing two binary strings with a given jitter
  BINARY_TYPE cross(const BINARY_TYPE n1, const BINARY_TYPE n2, float jitter);

  // function for mutating a given binary string by a given factor
  static BINARY_TYPE mutate(const BINARY_TYPE number, float severity);

  // function for reading the raw genome
  BINARY_TYPE getGenome();

  // function for setting the raw genome
  void setGenome(BINARY_TYPE genome);
  
  /*TEMPORARY, THIS SHOULD BE PRIVATE!*/
  // The Genome Data itself, in all its glory
  BINARY_TYPE genome;

  static void unitTest();

 /*****************************************************************************/

 private:

  /************************ PRIVATE DATA/VARIABLES ***************************/
    

  /***************************************************************************/

};

  // debugging utility for printing the numbers in binary to the console
  void printBinary(const BINARY_TYPE number);



#endif
