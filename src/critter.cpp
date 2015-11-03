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

// default constructor
Critter::Critter(){

  // fill in random junk by default
  name = "New Critter";
  cuteness = 0.0;
  scariness = 0.0;
  strangeness = 0.0;

  // initialize features to default feature constructors
  covering;
  digits;
  eyes;
  limbs;
  binary;
}

// destructor
Critter::~Critter(){
  //std::cout << "Critter is kill.\n";
}

// returns the name of this critter
std::string const Critter :: getName(){
  return name;
}

// changes the name of this critter
void Critter::setName(std::string newname) {
  this->name = newname;
}

// returns the Binary encoding of this Critter
Binary Critter::getBinary(){
  Binary out = this->binary;
  return out;
}

// sets the Binary encoding of this Critter
void Critter::setBinary(Binary newBinary){
  this->binary = newBinary;
}

// prints a description of this critter
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
	cout << "********************************************\n";
}

//Sets all genome values to that of the Critter's
void Critter :: set_Binary() {

	long int c_genome = this->binary.getGenome();

	this->covering.genome = c_genome;
	this->digits.genome = c_genome;
	this->eyes.genome = c_genome;
	this->limbs.genome = c_genome;

	return;
}

//Sets all traits of the critter in accorance to critter's genome.

void set_Features() {
	
	//This, in theory, sets the phenotype vectors of all features.
	this->covering.get_Feature(this->covering.phenotype);
	this->digits.get_Feature(this->digits.phenotype);
	this->eyes.get_Feature(this->eyes.phenotype);
	this->limbs.get_Feature(this->limbs.phenotype);
	
	//Covering Feature:
	this->covering.coat = this->covering.phenotype.at(0);
	this->covering.texture = this->covering.phenotype.at(1);
	//Digits Feature:
	this->digits.type = this->digits.phenotype.at(0);
	this->digits.amount = this->digits.phenotype.at(1);
	//Eyes Feature:
	this->eyes.size = this->eyes.phenotype.at(0);
	this->eyes.pupil = this->eyes.phenotype.at(1);
	this->eyes.color = this->eyes.phenotype.at(2);
	this->eyes.number = this->eyes.phenotype.at(3);
	//Limbs Feature:
	this->limbs.number = this->limbs.phenotype.at(0);
	this->limbs.shape = this->limbs.phenotype.at(1);
	return;

}

// set a critter's name to another critter's
void Critter::operator= (const Critter &other) {
  name = other.name;
  return;
}

// check if two critters have the same name
bool Critter :: operator== (const Critter &other) {
  return name == other.name;
}

// update the Critter's genome using two parent Critters and a jitter value
void Critter::parents(Critter mommy, Critter daddy, float jitter){
  this->binary.cross(mommy.getBinary(), daddy.getBinary(), jitter);
  return;
}

// mutate this Critter's genome by a specified amount between [0,1]
void Critter::mutate(float severity){
  this->binary.genome = Binary::mutate(binary.genome, severity);
}

void Critter :: unitTest() {
}

// print a name for this critter in an ostream
std::ostream & operator<< (std::ostream & os, const Critter& c) {
  os << c.name;
//  os << " is a Critter.\n";  <----- for some reason, uncommenting this causes an error
//  along the lines of "<< undefined for types osream_basic<char> and const char[16]
  return os;
}
