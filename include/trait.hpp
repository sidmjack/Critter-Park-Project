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
 * Last Modified: November 4, 2015
 * ****************************************************************************/

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
  std::vector<int> getALL();

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
    index["beady"] = std::vector<int> {0,0,0};
    index["little"] = std::vector<int> {0,0,0};
    index["large"] = std::vector<int> {0,0,0};
    index["mammoth"] = std::vector<int> {0,0,0};
    // pupils
    index["indiscernible"] = std::vector<int> {0,0,0};
    index["slit"] = std::vector<int> {0,0,0};
    index["compound"] = std::vector<int> {0,0,0};
    index["round"] = std::vector<int> {0,0,0};
    // color
    index["blood-shot"] = std::vector<int> {0,0,0};
    index["azure"] = std::vector<int> {0,0,0};
    index["emerald"] = std::vector<int> {0,0,0};
    index["golden"] = std::vector<int> {0,0,0};
    // number
    index["one eye"] = std::vector<int> {0,0,0};
    index["two eyes"] = std::vector<int> {0,0,0};
    index["four eyes"] = std::vector<int> {0,0,0};
    index["eight eyes"] = std::vector<int> {0,0,0};

  // COVERING DESCRIPTION
    // coat
    index["pelt"] = std::vector<int> {0,0,0};
    index["set of scales"] = std::vector<int> {0,0,0};
    index["layer of plumes"] = std::vector<int> {0,0,0};
    index["leather hide"] = std::vector<int> {0,0,0};
    // texture
    index["smooth"] = std::vector<int> {0,0,0};
    index["course"] = std::vector<int> {0,0,0}; // eventually, change to "coarse"
    index["slimy"] = std::vector<int> {0,0,0};
    index["bristly"] = std::vector<int> {0,0,0};

  // LIMB DESCRIPTIONS
    // number
    index["two"] =  std::vector<int> {0,0,0};
    index["four"] =  std::vector<int> {0,0,0};
    index["six"] =  std::vector<int> {0,0,0};
    index["eight"] =  std::vector<int> {0,0,0};
    // type
    index["spindles"] = std::vector<int> {0,0,0};
    index["tentacles"] = std::vector<int> {0,0,0};
    index["forelegs"] = std::vector<int> {0,0,0};
    index["stubs"] = std::vector<int> {0,0,0};

  // DIGIT DESCRIPTORS
    // type
    index["toes"] = std::vector<int> {0,0,0};
    index["claws"] = std::vector<int> {0,0,0};
    index["fingers"] = std::vector<int> {0,0,0};
    index["talons"] = std::vector<int> {0,0,0};
    // amount
    //index["two"] = (two is already used by limbs. Maybe use "two legs"?)
    index["three"] = std::vector<int> {0,0,0};
    index["five"] = std::vector<int> {0,0,0};
    index["seven"] = std::vector<int> {0,0,0};
    
    // return the map
    return index;
  }//end dictionary



  // this vector will assign three integer values for each trait to evey word
  // we've used to describe anything in this program. The array that a word
  // maps to shall have the format {cuteness, scariness, strangeness}
  //
  // I can't figure out how to make this a constant, so just please please
  // please never do anything that would edit it.
  static std::map< std::string, std::vector<int> > index;


}; //end class

