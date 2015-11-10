#include <iostream>
#include "critter.hpp"
usign std::cout;

int main(){
  int a = 0;
  int b = 405;

  // find long size
  std::cout << sizeof(long int) << std::endl;

  std::cout << "strings a and b are: \n";
  printBinary(a);
  std::cout << std::endl;
  printBinary(b);
  std::cout << std::endl << std::endl;

  //test cross
  printBinary(cross(a,b,0.0));
  std::cout << std::endl;
  printBinary(cross(b,a,0.0));
  std::cout << std::endl;
  printBinary(cross(a,b,1.0));
  std::cout << std::endl;
  printBinary(cross(a,b,0.5));
  std::cout << std::endl;
  //test mutate
  mutate(b,0.5);
  std::cout << std::endl;

  //test critter stuff
  Critter michael;
  Critter james;
  michael.setName("michael");
  james.setName("james");
  cout << "results of test michael < james: \n";
  cout << (michael < james);

  return 0;
}
