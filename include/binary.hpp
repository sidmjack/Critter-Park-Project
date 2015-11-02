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

   /*FEATURE BYTE OFFSETS)*/
//Covering Offset
#define COVERING_OFFSET 1
//Digits Offset
#define DIGITS_OFFSET 2
//Eyes Offset
#define EYES_OFFSET 3
//Limbs Offset
#define LIMBS_OFFSET 4

//// if we need more than a long, change it here: ////
///                                                ///
             #define BINARY_TYPE long int          ///
///                                                ///
//////////////////////////////////////////////////////

#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Binary{
  public:
  
  // constructor
  Binary();

  // destructor
  ~Binary();


  /***************************************************************************/
  
  /*ENCODE/DECODE FUNCTIONS*/

  /*Encode Function: Encodes integer values into binary genome*/
  BINARY_TYPE encode(const BINARY_TYPE noncoded_genome, BINARY_TYPE* genome_canvas); 

  /*Decode Function: Decodes single traits from within the encoded genome*/
  int decode(const BINARY_TYPE* genome_canvas);

  /*Get Features Functions: stores string features into a vector of critter traits*/
  void get_Features();


  /**************************************************************************/
  
  /*MATE CRITTER FUNCTIONS*/

  // wrapper for the cross function
  void cross(Binary parent1, Binary parent2, float jitter);

  // wrapper for the mutate function
  void mutate(float severity);

  /************** Functions used mostly by other functions *******************/
  
  // function for crossing two binary strings with a given jitter
  BINARY_TYPE cross(const BINARY_TYPE n1, const BINARY_TYPE n2, float jitter);

  // function for mutating a given binary string by a given factor
  static BINARY_TYPE mutate(const BINARY_TYPE number, float severity);

  // function for reading the raw genome
  BINARY_TYPE getGenome();

  // function for setting the raw genome
  void setGenome(BINARY_TYPE genome);

  // debugging utility for printing the numbers in binary to the console
  void printBinary(const BINARY_TYPE number);
  
  // the genome data itself, in all its glory
  BINARY_TYPE genome;

  /***************************************************************************/
  private:
  
  // descriptor vector ... still working on this 
  std::vector<std::string> critter_traits;

};

#include "binary.cpp"


#endif
