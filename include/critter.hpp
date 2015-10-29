#ifndef HW8_CRITTER_UTILS
#define HW8_CRITTER_UTILS

#include <string>

class Critter{
 public:
  // returns the name of the Critter
  std::string getName() const;

  // changes the name of the Critter
  void setName(std::stsring name);

  // default constructor
  Critter();

  // destructor
  ~Critter();


 private:
  // variables for describing the Critter
  std::string name;
  float cuteness;
  float scariness;
  float strangeness;

  // features that this Critter has
  Cover covering;
  Eye eyes;
  Limb limbs;
  Digit digits;
}

#endif
