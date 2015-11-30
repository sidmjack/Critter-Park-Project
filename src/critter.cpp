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
 * Last Modified: November 9, 2015
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
Binary const Critter::getBinary() const{
  Binary out = this->genotype;
  return out;
}

// Sets the Binary Encoding of Critter
void Critter::setBinary(Binary genotype){
  this->genotype = genotype;
  // update features
  unsigned offset = 0;
  this->covering.decode(genotype, offset);
  this->digits.decode(genotype, offset);
  this->eyes.decode(genotype, offset);
  this->limbs.decode(genotype, offset);
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
	cout << "." << "\n\n";
	//Assuming we give Critter a Trait and create a critter function that 
	//makes "Critter Trait" by summing the feature traits...Uncomment Below.
	cout << "Characteristic Scores: \n";
	cout << "Cuteness: " << this->getTraitScores().at(0);
	cout << "\nScariness: " << this->getTraitScores().at(1);
	cout << "\nStrangeness: " << this->getTraitScores().at(2);
	cout << "\n********************************************";
	cout << "********************************************\n\n";
}

// sets a critter's trait scores based on the descriptors in its features
std::vector<int> Critter::getTraitScores() {
  std::vector<int> scores = {0,0,0};
  // sum the scores from all four body parts
  covering.updateTrait();
  digits.updateTrait();
  eyes.updateTrait();
  limbs.updateTrait();
  for(int i = 0; i < 3; i++){
    //covering.updateTrait();
    scores.at(i) += covering.feature_trait.rate().at(i);
    scores.at(i) += digits.feature_trait.rate().at(i);
    scores.at(i) += eyes.feature_trait.rate().at(i);
    scores.at(i) += limbs.feature_trait.rate().at(i);
  }
    
  // return the scores
  return scores;
}

// OPERATOR OVERLOADING //

// Set a Critter's name to another Critter's
void Critter::operator= (const Critter &other) {
  name = other.name;
  return;
}

// Checks if 2 Critters have the same name & genome
bool Critter :: operator== (const Critter &other) {
  //test a number of defining qualities of a Critter against another one
  if( !(this->name == other.name)){
    return false;
  }
  if( !(this->getBinary().getGenome() == other.getBinary().getGenome())){
    return false;
  }
  return true;
}

// checks which Critter's name comes first
bool Critter::operator< (const Critter &other){
  return (this->name < other.name);
}

// print a critter's info to stream


// GENETIC STUFF //

// Updates the Critter's genome using two parent Critters and a jitter value
void Critter::parents(Critter mommy, Critter daddy, float jitter){
  this->genotype.cross(mommy.getBinary(), daddy.getBinary(), jitter);
/*Considering turning code below into a function*/
  unsigned offset = 0;
  covering.decode(genotype, offset);
  digits.decode(genotype, offset);
  eyes.decode(genotype, offset);
  limbs.decode(genotype, offset);
  return;
}

// Mutates this Critter's genome by a specified amount between [0,1]
void Critter::mutate(float severity){
  this->genotype.genome = Binary::mutate(genotype.genome, severity);
 /*Considering turning code below into a function*/
  unsigned offset = 0;
  covering.decode(genotype, offset);
  digits.decode(genotype, offset);
  eyes.decode(genotype, offset);
  limbs.decode(genotype, offset);
  return;
}

//More sketcky function adding...
void Critter::engineer(long int magic_number){
    
    this->genotype.genome = magic_number;

    unsigned offset = 0;
    covering.decode(genotype, offset);
    digits.decode(genotype, offset);
    eyes.decode(genotype, offset);
    limbs.decode(genotype, offset);
    return;
}
//

// Print a name for this critter in an ostream
std::ostream & operator<< (std::ostream & os, const Critter& c) {
	os << c.name;
  //  os << " is a Critter.\n";  <----- for some reason, uncommenting this causes an error
//  along the lines of "<< undefined for types osream_basic<char> and const char[16]
  return os;
}

/***************************CRITTER UNIT TESTING******************************/

//UNIT TEST:
void Critter::unitTest () {

	std::cout << "Beginning unit tests for Critter Class Functions...\n\n";
	
	/*********************************************************************/
	std::cout << "Make Two Critter Objects:\n";
	
	Critter A;
	Critter B;
	
	/* Note: If Critter couldn't be constructed, the compiler wouldn't
	 * let the program get to this point */
	std::cout << "Critter Constructor: PASSED!\n\n";

	/*********************************************************************/
	
	std::cout << "Mutate Critter:\n";
	
	BINARY_TYPE a_before = A.genotype.getGenome();
	std::cout << "Critter Binary BEFORE Mutation: ";
	printBinary(a_before);
	std::cout << "\n";

	A.mutate(.5);

	BINARY_TYPE a_after = A.genotype.getGenome();
	std::cout << "Critter Binary AFTER Mutation:  ";
	printBinary(a_after);
	std::cout << "\n";

	if (a_before != a_after){
		std::cout << "Critter Mutate: PASSED!\n\n";
	} else {
		std::cout << "Critter Mutate: FAILED!\n\n";
	}

	/*********************************************************************/

	std::cout << "Breed Two Critters:\n";
	std::cout << "Breeding Critter A with Critter B to make Critter C\n";
	Critter C;
	C.parents(A,B,.1);

	BINARY_TYPE a = A.genotype.getGenome();
	std::cout << "Critter Binary of Parent 1 (A): ";
	printBinary(a);
	std::cout << "\n";

	BINARY_TYPE b = B.genotype.getGenome();
	std::cout << "Critter Binary of Parent 2 (B): ";
	printBinary(b);
	std::cout << "\n";

	BINARY_TYPE c = C.genotype.getGenome();
	std::cout << "Critter Binary of Baby Critter (C): ";
	printBinary(c);
	std::cout << "\n";

	if (((c != a) & (c != b))){
		std::cout << "Critter Breeding: PASSED!\n\n";
	} else {
		std::cout << "Critter Breeding: FAILED!\n\n";
	}		

	/*********************************************************************/
	std::cout << "Change Name of Critter:\n";
	
	std::string name_1;
	std::string name_2;
	
	C.setName("James");
	name_1 = C.getName();
	std::cout << "Name of Critter is..." << name_1 << ".\n";

	std::cout << "Change Name...\n";

	C.setName("Johnny");
	name_2 = C.getName();
	std::cout << "New Name of Critter is..." << name_2 << ".\n";

	if (name_1 != name_2){
		std::cout << "Name Change: PASSED!\n\n";
	} else {
		std::cout << "Name Change: FAILED!\n\n";
	}

	/*********************************************************************/
	std::cout << "Print Description of Critter:\n";
	std::cout << "Description of Critter B (Binary Set to 0)\n";
	
	B.setName("Lulu");
	B.printCritter();

	if ((
	(B.name == "Lulu") &
	(B.covering.texture == "smooth") &
       	(B.covering.coat == "pelt") &
	(B.eyes.number == "one") &
	(B.eyes.size == "beady") &
	(B.eyes.color == "blood-shot") &
	(B.eyes.pupil == "indiscernible") &
	(B.limbs.number == "two") &
	(B.limbs.shape == "spindles") &
	(B.digits.amount == "two") &
	(B.digits.type == "toes")
	)) {
		std::cout << "Critter Description: PASSED!\n\n";
	} else {
		std::cout << "Critter Description: FAILED!\n\n";
	}

	/*********************************************************************/
	std::cout << "Retrieve Critter Binary Genome:\n";
	
	BINARY_TYPE X;
	BINARY_TYPE Y;

	X = A.getBinary().genome;
	Y = B.getBinary().genome;
	
	if ((X != 0) & (Y == 0)){
		std::cout << "Retrieve Binary Genome: PASSED!\n\n";
	} else {
		std::cout << "Retrieve Binary Genome: FAILED!\n\n";
	}

	/*********************************************************************/
	std::cout << "Print Critter Name:\n";
	
	std::cout << "Print the Names of the Critters (A-C)\n";
	
	std::string name_a;
	std::string name_b;
	std::string name_c;

	A.setName("Alphie");
	B.setName("Brendon");
	C.setName("Caesar");

	name_a = A.getName();
	name_b = B.getName();
	name_c = C.getName();

	std::cout << "Critter A: " << name_a << "\n";
	std::cout << "Critter B: " << name_b << "\n";
	std::cout << "Critter B: " << name_c << "\n";

	if (((name_a == "Alphie") & (name_b == "Brendon") & (name_c == "Caesar"))){
		std::cout << "Print Name: PASSED!\n\n";
	} else {
		std::cout << "Print Name: FAILED!\n\n";
	}
	
	/*********************************************************************/
	std::cout << "Compare Critter Names:\n";
	
	std::string answer;
	int passes = 0;
	
	//Quesiton 1
	std::cout << "Are Alphie and Caesar the same???\n";
	if (A.name != C.name){
		answer = "Of course not!";
		passes++;
	} else {
		answer = "Obvs...";
	}
	std::cout << "Answer: " << answer << "\n";

	//Question 2
	std::cout << "Is Brendon, umm...Brendon???\n";
		if (B.name != B.name){
		answer = "Of course not!";
	} else {
		answer = "Obvs...";
		passes++;
	}
	std::cout << "Answer: " << answer << "\n";

	if (passes == 2) {
		std::cout << "Compare Names: PASSED!\n\n";
	} else {
		std::cout << "Compare Names: FAILED!\n\n";
	}

	/*********************************************************************/

	std::cout << "Finished unit tests for Critter Class Functions.\n";
	
	return;
}


/*****************************************************************************/


