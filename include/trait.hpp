/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * EN.600.120
 * Intermediate Programming
 * Homework #8, part 2
 *
 * trait.hpp - Contains the class and function declarations for the Trait class,
 * which is used in this program to assess the cuteness, scariness, and
 * strangeness of each feature that a Critter has.
 *
 * Last Modified: November 9, 2015
 * ****************************************************************************/

#ifndef HW9_TRAIT_H
#define HW9_TRAIT_H

#include <map>
#include <vector>
#include <string>
#include <iostream>

class Trait{

  public:

  // CONSTRUCTORS & DESTRUCTOR //
  // default constructor
  Trait(){
  };

  // destructor
  ~Trait(){
  };



  // STATIC LOOKUP FUNCTIONS //

  // check if an adjective is in the index
  static bool exists(std::string);

  // get the cute/scary/strange vector for a given adjective
  static std::vector<int> getAll(std::string);

  // get the cute score for an adjective
  static std::vector<int> getCute(std::string);

  // get the scary score for an adjective
  static std::vector<int> getScary(std::string s);

  // get the strange score for an adjective
  static std::vector<int> getStrange(std::string s);



  // INSTANCE LOOKUP FUNCTIONS //

  // returns all values for this Trait
  std::vector<int> getAll();

  // returns cuteness of this Trait
  std::vector<int> getCute();

  // returns scariness of this Trait
  std::vector<int> getScary();

  // returns strangeness of this Trait
  std::vector<int> getStrange();

  // ruins your life
  void getRekt();



  // TRAIT MANIPULATION FUNCTIONS //

  // assigns this Trait the given traits
  bool setTraits(std::vector<std::string>);

  // returns a list of currently stored traits (empty on failure)
  std::vector<std::string> getTraits();

  // assesses the cuteness, scariness, and strangeness of this Trait
  std::vector<int> rate();



  // OVERLOADED OPERATORS //

  // the + operator will sum the cuteness, scariness and strangeness of
  // two instances of the Trait class
  Trait operator+(Trait other);

  // the += operator will add the cute/scary/strange values to the current
  // intance of the Trait class
  void operator+=(Trait other);


  // PUBLIC VARIABLES //

  // this vector holds all the descriptors that this Trait has been assigned.
  // (e.g. if an Eye has a Trait, it would store things like "beady," "slit,"
  // "azure" etc. in its Trait, which stores it in this vector.
  std::vector< std::string > current;

    
  // this function creates the static variable which holds cute/scary/strange
  // scores for all adjectives used in this program.
  static std::map<std::string, std::vector<int>> createList(){
    std::map<std::string, std::vector<int>> index;
    
  // THIS IS THE DICTIONARY
  // EYE DESCRIPTION
    // eye size                  cute, scary, strange
    index["beady"] = std::vector<int> {-1,2,0};
    index["little"] = std::vector<int> {-1,1,0};
    index["large"] = std::vector<int> {3,0,1};
    index["mammoth"] = std::vector<int> {1,0,2};
    // pupils
    index["indiscernible"] = std::vector<int> {-1,3,0};
    index["slit"] = std::vector<int> {0,2,0};
    index["compound"] = std::vector<int> {0,1,3};
    index["round"] = std::vector<int> {3,0,-2};
    // color
    index["blood-shot"] = std::vector<int> {-2,3,1};
    index["azure"] = std::vector<int> {2,0,-1};
    index["emerald"] = std::vector<int> {3,0,1};
    index["golden"] = std::vector<int> {0,-1,3};
    // number
    index["one eye"] = std::vector<int> {0,3,2};
    index["two eyes"] = std::vector<int> {2,0,-3};
    index["four eyes"] = std::vector<int> {0,1,2};
    index["eight eyes"] = std::vector<int> {-2,2,3};

  // COVERING DESCRIPTION
    // coat
    index["pelt"] = std::vector<int> {2,0,-1};
    index["set of scales"] = std::vector<int> {-1,2,0};
    index["layer of plumes"] = std::vector<int> {1,0,3};
    index["leather hide"] = std::vector<int> {0,0,-1};
    // texture
    index["smooth"] = std::vector<int> {3,0,-1};
    index["course"] = std::vector<int> {-1,2,0}; // eventually, change to "coarse"
    index["slimy"] = std::vector<int> {-2,3,3};
    index["bristly"] = std::vector<int> {0,1,1};

  // LIMB DESCRIPTIONS
    // number
    index["two"] =  std::vector<int> {3,0,-1};
    index["four"] =  std::vector<int> {2,0,-1};
    index["six"] =  std::vector<int> {2,2,2};
    index["eight"] =  std::vector<int> {0,3,3};
    // type
    index["spindles"] = std::vector<int> {-2,2,3};
    index["tentacles"] = std::vector<int> {-2,3,3};
    index["forelegs"] = std::vector<int> {2,0,-2};
    index["stubs"] = std::vector<int> {3,-3,1};

  // DIGIT DESCRIPTORS
    // type
    index["toes"] = std::vector<int> {2,-1,-1};
    index["claws"] = std::vector<int> {0,2,0};
    index["fingers"] = std::vector<int> {0,0,2};
    index["talons"] = std::vector<int> {-1,3,2};
    // amount
    //index["two"] = (two is already used by limbs. Maybe use "two legs"?)
    index["three"] = std::vector<int> {2,0,3};
    index["five"] = std::vector<int> {1,0,-1};
    index["seven"] = std::vector<int> {0,3,3};
    
    // return the map
    return index;
  }//end dictionary

  /*Unit Test for TRAIT!*/
  static void unitTest();
  
  //private:

  // this vector will assign three integer values for each trait to every word
  // we've used to describe anything in this program. The array that a word
  // maps to shall have the format {cuteness, scariness, strangeness}
  //
  // I can't figure out how to make this a constant, so just please please
  // please never do anything that would edit it.
  static std::map< std::string, std::vector<int> > index;


}; //end class

#endif

