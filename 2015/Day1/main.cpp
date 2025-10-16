//
// Day 1: Not Quite Lisp
// https://adventofcode.com/2015/day/1
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>




int main(){
  std::fstream file;

  file.open("input.txt" , std::ios::in);

  if(!file.is_open()){
    std::cout << "could not open file" << std::endl;
    return 0;
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string input = buffer.str();

  int floor = 0;
  int k = 1;
  bool first = false;

  for(char i : input)
  {
    if(i == '('){
      floor++;
    }
    else if(i == ')'){
      floor--;
    }

    if(floor == -1 && first == false)
    {
      std::cout << "Position: " << k << std::endl;
      first = true;
    }
    k++;
  }

  std::cout << "floor: " << floor << std::endl;

  return 0;
}
