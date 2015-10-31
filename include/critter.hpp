#ifndef HW8_CRITTER_UTILS
#define HW8_CRITTER_UTILS

#include <string>

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

  // default constructor
  Critter();

  // destructor
  ~Critter();

  // breeding mechanism
  void parents(Critter mommy, Critter daddy, float jitter);

  // mutation mechanism
  void mutate(float severity);

 private:
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

  // the Critter's genes
  
};

#endif
