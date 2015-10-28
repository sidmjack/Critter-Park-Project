/*Modeled from Ben Mitchell's Class Example*/

#include <iostream>
#include "Critter.hpp"

Critter :: Critter (std::string n) : name(n)
{
}

std::string Critter :: getName() const {
  return name;
}

void Critter::setName(std::string name) {
  this->name = name;
}


void Critter :: printCritter() {
  //Critter Descriptor Function Here!
}


Critter & Critter :: operator= (const Critter &other) {
  name = other.name;

}

bool Critter :: operator== (const Critter &other) {
  return name == other.name;
}


void Critter :: unitTest() {
}


std::ostream & operator<< (std::ostream & os, const Critter &c) {
  os << c.name;
  os << " is a Critter.\n";
  return os;
}
