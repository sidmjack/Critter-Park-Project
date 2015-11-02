#include "critter.hpp"
#include "menu.hpp"

using std::cout;
using std::endl;

int main(){

  int param1 = 0;
  int param2 = 0;
  int command = 0;
  std::string name;

  Critter wilbur, mary;
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
  printBinary(wilbur.getBinary().getGenome());
  Binary WGENES = wilbur.getBinary();
  cout << "\n mutating....";
  wilbur.mutate(0.5);
  cout << "super wilbur:" << endl;
  printBinary(wilbur.getBinary().getGenome());
  cout << endl;
  
  mary.mutate(0.5);
  Critter baby;
  baby.parents(mary, wilbur, 0.5);
  cout << "baby genes:\n";
  printBinary(baby.getBinary().getGenome());
  baby.setName("sophie");
  cout << "baby's name is "<<baby<<", isn't that sweet?"<<endl;

  cout << "attempting to load the menu" << endl;
  printMenu();
  getInput(&command, &param1, &param2, &name);


  std::cout << "I can't believe it's not butter!\n";
 

  return 0;
}
