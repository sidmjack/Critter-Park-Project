/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 2
 *
 * trait.hpp - Contains the class and function definitions for the Trait class,
 * which is used in this program to assess the cuteness, scariness, and
 * strangeness of each feature that a Critter has.
 *
 * Last Modified: November 4, 2015
 * ****************************************************************************/
#include "trait.hpp"

// CREATE THE BLOODY DICTIONARY //
std::map<std::string, std::vector<int>> Trait::index = Trait::createList();



// STATIC LOOKUP FUNCTIONS //
  
// checks if a trait is in the dictionary or naw
bool Trait::exists(std::string s){
  // see if the string is a valid trait
  auto it = Trait::index.find(s);
  if( it == Trait::index.end() ){
    std::cerr << "Trait: could not find trait \""<< s <<"\" in index!\n";
    return false;
  }
  return true;
}

// returns the cute/scary/strange scores for the given string.
// returns a zero-length vector on fail
std::vector<int> Trait::getAll(std::string s){
  // see if the string is a valid trait
  if( !Trait::exists(s) ){
    std::cerr << "getAll: could not find trait \""<< s <<"\" in index!\n";
    return std::vector<int> { };
  }
  // if it is, return the scores
  return index.at(s);
}



// returns the cuteness for the given string.
// returns a zero-length vector on fail
std::vector<int> getCute(std::string s){
  // see if the string is a valid trait
  if( !Trait::exists(s) ){
    std::cerr << "getCute: could not find trait \""<< s <<"\" in index!\n";
    return std::vector<int> { };
  }
  // if it is, return the cuteness (first number in the vector)
  return std::vector<int>{ Trait::index.at(s).at(0) };
}


// returns the scariness for the given string
// returns a zero-length vector on fail
std::vector<int> getScary(std::string s){
  // see if the string is a valid trait
  if( !Trait::exists(s) ){
    std::cerr << "getScary: could not find trait \""<< s <<"\" in index!\n";
    return std::vector<int> { };
  }
  // if it is, return the scariness (second number in the vector)
  return std::vector<int>{ Trait::index.at(s).at(1) };
}


// returns the stangeness for the given string
// returns a zero-length vector on fail
std::vector<int> Trait::getStrange(std::string s){
  // see if the string is a valid trait
  if( !Trait::exists(s) ){
    std::cerr << "getStrange: could not find trait \""<< s <<"\" in index!\n";
    return std::vector<int> { };
  }
  // if it is, return the scariness (second number in the vector)
  return std::vector<int>{ index.at(s).at(2) };
}



// TRAIT MANIPULATION FUNCTIONS //

// assigns this Trait the given traits
  bool Trait::setTraits(std::vector<std::string> new_traits){


  // see if each trait is recognized
  for(unsigned int i = 0; i < new_traits.size(); i++){
    if( ! Trait::exists(new_traits[i])){
      std::cout << "error: setTraits: \"" << new_traits.at(i) << "\" not in dictionary!";
      return false;
    }
  }
  // if everything is k, return
  this->current = new_traits;
  return true;
}

// returns a list of currently stored traits (empty on failure)
std::vector<std::string> Trait::getTraits(){
  return current;
}
  


// OVERLOADED OPERATORS  //

// the + operator will sum the cuteness, scariness and strangeness of
// two instances of the Trait class
Trait Trait::operator+(Trait other){
  // create a blank to hold the result
  Trait output;
  std::vector<std::string> contents;
  // find out what the other traits are holding, and grab it
  for(unsigned int i = 0; i < current.size(); i++){
    contents.push_back(this->current[i]);
  }
  // do this for both inputs
  for(unsigned int i = 0; i < other.getTraits().size(); i++){
    contents.push_back(other.getTraits().at(i));
  }
  // spit that back out
  output.setTraits(contents);
  return output;

}
  

// the += operator will add the cute/scary/strange values to the current
// intance of the Trait class
void Trait::operator+=(Trait other){
  // add the other Trait's traits to this one
  for(unsigned int i = 0; i < other.getTraits().size(); i++){
    // make sure nohing sus is stored in the other Trait
    if( !Trait::exists(other.getTraits().at(i)) ){
      std::cout << "copyAssign: could not find \"" << other.getTraits().at(i) << "\" in index!\n";
    }
    this->current.push_back(other.getTraits().at(i));
  }
}


