#include "critter.hpp"
int main(){

  Critter wilbur;

  std::cout << "Wilbur's current genetic makeup: \n";
  printBinary(wilbur.getBinary().getGenome());
  std::cout << "\nWilbur after mutation: \n";
  
  // send wilbur to chernobyl
  wilbur.mutate(0.5);

  // see what happened to him
  printBinary(wilbur.getBinary().getGenome());

  std::cout << "\n\nI can't believe it's not butter!\n";
 

  return 0;
}
