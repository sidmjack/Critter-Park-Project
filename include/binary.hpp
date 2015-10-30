/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * CS 600.120
 * Homework #6, part 1
 *
 * binary.hpp - contains definitions for functions used in printing and
 *     manipulating the binary strings used to store Critter traits.
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

#include "binary.cpp"

#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <iostream>

// utility for printing long ints in binary to the console
void printBinary(const BINARY_TYPE number);

// function for crossing two binary strings with a given jitter
BINARY_TYPE cross(const BINARY_TYPE n1, const BINARY_TYPE n2, float jitter);

// function for mutating a given binary string by a given factor
BINARY_TYPE mutate(const BINARY_TYPE number, float severity);

/*ENCODE/DECODE FUNCTIONS*/

/*Encode Function: Encodes integer values into binary genome*/
BINARY_TYPE encode(const BINARY_TYPE noncoded_genome); 

/*Decode Function: Decodes single traits from within the encoded genome*/
BINARY_TYPE decode(const BINARY TYPE genome_canvas);

#endif
