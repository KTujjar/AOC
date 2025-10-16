#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

int main(){
  std::fstream file;

  file.open("input.txt", std::ios::in);

  std::string input;
  std::ostringstream buffer;
  buffer << file.rdbuf();
  input = buffer.str();

  // std::array<std::array<int, input.size()>, input.size()> grid;
  int startIdx = input.size();

  int x = 0, y = 0;
  int roboX = 0, roboY = 0;
  std::set<std::pair<int,int>> visited;
  std::set<std::pair<int, int>> roboSanta;

  visited.insert({x, y});
  roboSanta.insert({roboX, roboY});
  bool alternate = false;

  for(char i : input){

    int &cx = alternate ? roboX : x;
    int &cy = alternate ? roboY : y;

    switch(i){
      case '^' : cy++; break;
      case 'v' : cy--; break;
      case '>' : cx++; break;
      case '<' : cx--; break;
    }

    if(alternate) roboSanta.insert({cx,cy});
    else visited.insert({cx,cy});

    alternate = !alternate;
  }

  visited.merge(roboSanta);

  std::cout << visited.size() << std::endl;
  return 0;

}
