#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int sum = 0;
  for (int i = 0; i< s.size(); i++){
    int alphasnum = (s.at(i) - 65);
    if(alphasnum <= 14){
      sum += alphasnum/3 + 3;
    }
    else{
      if (alphasnum <=18){
        sum += 8;
      }
      else if (alphasnum <=21){
        sum += 9;
      }
      else{
        sum += 10;
      }
    }
  }
  std::cout << sum;
  return 0;
}