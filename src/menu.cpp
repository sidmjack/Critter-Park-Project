/******************************************************************************
 * Florian Pontani & Sidney Jackson
 * fpontan1 & sjacks85
 * (917) 454-8493 & (386) 956-5577
 * 
 * CS 600.120
 * Homework #8, part 1
 *
 * menu.cpp - implementation of the menu/driver program utilities
 *
 * Last Modified: November 2, 2015
 *****************************************************************************/

using std::cout;
using std::endl;



// print the menu options to the console (cout)
void printMenu(){
  cout << endl << "CritterSim v0.1 \n";
  for(int i = 0; i < 80; i++){
    cout << "=";
  }
  cout << "\nPlease select one of the options listed below to continue:\n";
  cout << "\ta - add a new Critter to the environment" << endl;
  cout << "\tl - list all Critters currently in the zoo" << endl;
  cout << "\tk <ID> - kill a critter" << endl;
  cout << "\tb <ID> <ID> - breed two existing Critters to form a new one" << endl;
  cout << "\tr <ID> <name> - change the name of a Critter to one of your choosing";
  cout << "\n\tq - quit CritterSim v0.1" << endl << endl;
  cout << "CS)> ";
}

// get the user input
void getInput(int* cmd, int* ID1, int* ID2, std::string* name){
  std::string str;
  std::string s1, s2, s3;
  int pos, one, two, command;

  // try to get a string from the user
  while(true){
    if(!(std::cin >> str)){
      invalid:
      cout<<"Please enter valid input.\n";
    }else{
      break;
    }
  }
  // parse the string into more useful things
  // *********************************************
  //find the command they used
  pos = str.find(" ");
  // if there are no spaces, check what we got
  if(pos == std::string::npos){
    // if it's a one-letter command, figure it out and return
    if(!str.compare("a")){
      *cmd = CMD_A;
      return;
    }
    if(!str.compare("l")){
      *cmd = CMD_L;
      return;
    }
    if(!str.compare("q")){
      *cmd = CMD_Q;
      return;
    }
    // if there are no spaces, but it's not a recognized one-letter command,
    // something is wrong, jump back to asking for valid input
    goto invalid;
  }
  // if there is a space, grab the first command in a substring
  s1 = str.substr(0,pos);
  //check if it's just a space on the end with nothing after it
  if(pos + 1 == str.length()){
    goto invalid;
  }

  // otherwise, assume there is more stuff after the initial command
  // trim the original string down and look for more stuff
  str = str.substr(pos + 1, std::string::npos);

  // if there's input after the space, but the command expects none, jump back
  // to asking for proper input
  if(!str.compare("a") || !str.compare("l") || !str.compare("q")){
    goto invalid;
  }
  // otherise, find out which command they used and go from here
  if(!s1.compare("k")){
    // now we expect one number and that's all, so see if the input string
    // ends or keeps going
    if(str.find(" ") != std::string::npos || str.find("\n") != std::string::npos || str.find("EOF") != std::string::npos){
      // ask for valid
      goto invalid;
    }
    // set command pointer
    *cmd = CMD_K;
    // try setting int ptr one TODO: make sure this is actually a number
    *ID1 = std::stoi(str,nullptr,10);

  }

  if(!s1.compare("b")){
  // now we expect two numbers and that's all

  }

  if(!s1.compare("r")){
  // now we expect a number followed by a string
  //
  }
  // if we don't recognize their command, go back to asking for valid input
  goto invalid;
}

  

// print a list of Critters to cout
void printCritterList(std::vector<Critter> vec){
  if(vec.size() == 0){
    cout << "There currently aren't any critters at all!\n";
    return;
  }
  if(vec.size() == 1){
    cout << "There is currently one Critter in captivity:\n";
  }else{
    cout << "There are currently " << vec.size() << " Critters in captivity:\n";
  }
  // loop through the list and print an index of Critters by their ID
  cout << "ID | Name";
  for(int i = 0; i < vec.size(); i++){
    if(i < 10){
      cout << " ";
    }
    cout << i << " - " << vec.at(i).getName() << endl;
  }
}
