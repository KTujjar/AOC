//
// 2015
// Day 2: I Was Told THere Would Be No Math
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <array>



int main(){
  std::fstream file;

  file.open("input.txt", std::ios::in);
  if(!file.is_open())
  {
    std::cout << "could not open file" << std::endl;
    return 0;
  }

  int totalSurfaceArea = 0;
  int totalRibbon = 0;

  std::string line;

  while(std::getline(file, line)){
    if(line.empty()) continue;

    std::istringstream ss(line);
    int l,w,h;
    char x;

    ss >> l >> x >> w >> x >> h;
    std::cout << l << w << h << std::endl;

    int s1 = l*w;
    int s2 = w*h;
    int s3 = h*l;

    int surface = 2 * (s1 + s2 + s3);
    int extra = std::min({s1 ,s2, s3});

    std::array<int, 3> dims = {l, w, h};
    std::sort(dims.begin(), dims.end());

    totalRibbon += dims[0] + dims[0] + dims[1] + dims[1] + (l*w*h);

    totalSurfaceArea += surface + extra;

  }

  std::cout << "\nTotalSurfaceArea: "<< totalSurfaceArea << "  TotalRibbon: " << totalRibbon << std::endl;

  return 0;

}
