/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 1
 *
 * Covering.hpp - Defines the map key/store values, the number of descriptors
 * and the length of the bits required to define the descriptors.
 * (Modeled from Ben Mitchell's Class Example)
 *
 * Last Modified: November 2, 2015
 * 
 * *****************************************************************************/


#include <iostream>
#include "critter.hpp"

// default constructor
Critter::Critter(){

  // fill in random junk by default
  name = "New Critter";
  cuteness = 0.0;
  scariness = 0.0;
  strangeness = 0.0;

  // initialize features to default feature constructors
  covering = Covering::Covering();
  digits = Digits::Digits();
  eyes = Eyes::Eyes();
  limbs = Limbs::Limbs();


// returns the name of this critter
std::string Critter :: getName() const {
  return name;
}

// changes the name of this critter
void Critter::setName(std::string newname) {
  this->name = newname;
}

// returns the Binary encoding of this Critter
Binary getBinary(){
  return this.Binary;
}

// sets the Binary encoding of this Critter
void setBinary(Binary newBinary){
  this.Binary = newBinary;
}

// prints a description of this critter
void Critter :: printCritter() {
  //TODO Critter Descriptor Function Here!
}

// set a critter's name to another critter's
Critter & Critter :: operator= (const Critter &other) {
  name = other.name;

}

// check if two critters have the same name
bool Critter :: operator== (const Critter &other) {
  return name == other.name;
}

// update the Critter's genome using two parent Critters and a jitter value
void parents(Critter mommy, Critter daddy, float jitter){
  this.Binary = Binary.(mommy.getBinary(), daddy.getBinary(), jitter);
  return;
}

// mutate this Critter's genome by a specified amount between [0,1]
void mutate(float severity){
  this.Binary = Binary.mutate(this.Binary);
}

void Critter :: unitTest() {
}


std::ostream & operator<< (std::ostream & os, const Critter &c) {
  os << c.name;
  os << " is a Critter.\n";
  return os;
}
