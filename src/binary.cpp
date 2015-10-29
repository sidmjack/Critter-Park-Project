/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * CS 600.120
 * Homework #6, part 1
 *
 * binary.cpp - contains utilities for printing and manipulating the binary
 *      strings used to store Critter traits in this program.
 *****************************************************************************/



// utility for printing bit strings to the console in readable form
void printBinary(const BINARY_TYPE number){
  for(int i = (int)sizeof(number)*8-1; i > -1; i--){
    if((number >> i) % 2 == 0){
      std::cout << "0";
    }else{
      std::cout << "1";
    }
  }
  return;
}

// function for crossing two binary strings with a given jitter
//
// n1, n2 - the binary strings that will be crossed
// jitter - the probability that the next bit will come from the opposite
//          input string, should be in range [0,1]
//
// 
BINARY_TYPE cross(const BINARY_TYPE n1, const BINARY_TYPE n2, float jitter){
  float random;
  char parent = 'a';
  BINARY_TYPE baby = 0;

  // make sure jitter is within the specified bounds
  if(jitter < 0.0 || jitter > 1.0){
    std::cerr << "Jitter must be in range [0,1]!\n";
    return 0;
  }

  // initialize random number generator using the current time
  srand(time(NULL));
  
  // go through each bit in the strings, starting with the most significant
  for(int i = sizeof(n1)*8-1; i > -1; i--){
    // get a random number, scale from zero to one
    random = (float)rand() / (float)RAND_MAX;

    // shift the baby by one binary digit to prepare for (maybe) writing a one
    baby = baby << 1;

    // if our number is less than the jitter, switch parents
    if(random < jitter){
      if(parent == 'a'){
        parent = 'b';
      }else{
        parent = 'a';
      }
    }

    // copy the next bit from the appropriate parent
    if(parent == 'a'){
      // if the next bit is a one, write a one from PARENT A a to the baby
      if(((n1 >> i) % 2) != 0){
        baby++;
      }
    }else{
      // if the next bit is a one, write a one from PARENT B to the baby
      if(((n2 >> i) % 2) != 0){
        baby++;
      }
    }
  }
  // finished
  return baby;
}

// function for mutating a given binary string by a given factor
BINARY_TYPE mutate(const BINARY_TYPE number, float severity){
  float random;
  BINARY_TYPE mask = 0;
  BINARY_TYPE mutant = 0;

  // make sure severity is within the specified bounds
  if(severity < 0.0 || severity > 1.0){
    std::cerr << "Severity must be in range [0,1]!\n";
    return 0;
  }

  // initialize random number generator using the current time
  srand(time(NULL));
  
  // go through each bit in the string, starting with the most significant
  for(int i = 0; i < (BINARY_TYPE)sizeof(number)*8; i++){
    // get a random number, scale from zero to one
    random = (float)rand() / (float)RAND_MAX;
    
    // advance the mask by one binary bit to prepare for (maybe) writing a one
    mask = mask << 1;

    // if our number is less than the jitter, invert the current bit via mask
    if(random < severity){
      mask++;
    }// otherwise, do nothing
  }

  // apply the mask (i.e. flip all bits whose mask bit is one)
  mutant = number ^ mask;

  // finished
  return mutant;
}



