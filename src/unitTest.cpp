#include "binary.hpp"
#include "critter.hpp"
#include "trait.hpp"
#include "eyes.hpp"
#include "covering.hpp"
#include "limbs.hpp"
#include "digits.hpp"

#include <iostream>

int main(){
  std::cout << "\nRunning all unitTest() functions::\n";
  
  Binary::unitTest();
  Critter::unitTest();
  Trait::unitTest();
  Eyes::unitTest();
  Covering::unitTest();
  Limbs::unitTest();
  Digits::unitTest();
  
  return 0;
  
}