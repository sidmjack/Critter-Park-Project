#include "critter.hpp"
using std::cout;
using std::endl;

int main(){

  Critter wilbur;
  Binary jenkins;
  
  cout << "jenkins: \n";
  printBinary(jenkins.getGenome());
  cout << endl;
  
  // try it out
  jenkins.mutate(0.5);
  cout << "mutant jenkins: \n";
  printBinary(jenkins.getGenome());
  cout << endl << endl;

  // try with a Critter
  cout << "wilbur: " << endl;
  Binary WGENES = wilbur.getBinary();
  cout << "mutating....";
  wilbur.mutate(0.5);
  cout << "super wilbur:" << endl;
  printBinary(wilbur.getBinary().getGenome());
  cout << endl;

  


  std::cout << "\n\nI can't believe it's not butter!\n";
 

  return 0;
}
