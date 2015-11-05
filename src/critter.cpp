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

#include "critter.hpp"

using std::cout;

// Constructor
Critter :: Critter(const Binary b)
  : genotype(b)
{

  //Initialize Critter Characteristics 
  name = "New Critter";
  cuteness = 0.0;
  scariness = 0.0;
  strangeness = 0.0;

  //Sets traits of each feature in accordance to the genome.
  unsigned offset = 0;
  covering.decode(genotype, offset);
  digits.decode(genotype, offset);
  eyes.decode(genotype, offset);
  limbs.decode(genotype, offset);

}

// Destructor
Critter::~Critter(){
}

// Returns Critter's Name
  std::string const Critter :: getName(){
  return name;
}

// Changes Critter's Name 
  void Critter::setName(std::string newname) {
  this->name = newname;
}

// Returns the Binary Encoding of Critter
Binary Critter::getBinary(){
  Binary out = this->genotype;
  return out;
}

// Sets the Binary Encoding of Critter
void Critter::setBinary(Binary newBinary){
  this->genotype = newBinary;
}

// Prints Critter Description
void Critter :: printCritter() {
        using std::cout;
	cout << "********************************************";
	cout << "********************************************\n";
	cout << "Meet " << this->name << "!\n";	
	cout << "\tThis particular critter is covererd in a ";
	cout << this->covering.texture << " " << this->covering.coat;
	cout << ", has " << this->eyes.number << "\n" << this->eyes.size;
	cout << " " << this->eyes.color << " eye(s) with " << this->eyes.pupil;
	cout << " pupils, and " << this->limbs.number << " ";
	cout << this->limbs.shape << ", each ending in ";
	cout << this->digits.amount << " " << this->digits.type;
	cout << "." << "\n";
	cout << "********************************************";
	cout << "********************************************\n\n";
}

// Set a Critter's name another Critter's
void Critter::operator= (const Critter &other) {
  name = other.name;
  return;
}

// Checks if 2 Critters have the same name
bool Critter :: operator== (const Critter &other) {
  return name == other.name;
}

// Updates the Critter's genome using two parent Critters and a jitter value
void Critter::parents(Critter mommy, Critter daddy, float jitter){
  this->genotype.cross(mommy.getBinary(), daddy.getBinary(), jitter);
  return;
}

// Mutates this Critter's genome by a specified amount between [0,1]
void Critter::mutate(float severity){
  this->genotype.genome = Binary::mutate(genotype.genome, severity);
}

// Print a name for this critter in an ostream
std::ostream & operator<< (std::ostream & os, const Critter& c) {
	os << c.name;
  //  os << " is a Critter.\n";  <----- for some reason, uncommenting this causes an error
//  along the lines of "<< undefined for types osream_basic<char> and const char[16]
  return os;
}
/***************************CRITTER UNIT TESTING******************************/

void Critter :: unitTest() {
}

/*****************************************************************************/


