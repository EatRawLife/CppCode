#include <iostream>
#include <vector>
#include <string>
int main() {
  std::string str;
  std::cin >> str;
  
  for(int i = 0; i<str.size(); i++) {
    if(str.at(i) <= 'Z') {
      str.at(i) += 32;
    }
  }

  std::vector<int> v(26,0);

  for(int i = 0; i<str.size(); i++) {
    v.at(str.at(i) - 97) += 1;
  }

  int max = 0;
  char maxChar = '?';
  for(int i = 0; i< 26; i++ ) {
    if(v.at(i) == max)
      maxChar = '?';
    else if(v.at(i) > max){
      max = v.at(i);
      maxChar = (char)(i + 65);
    }
    else{}
  }

  std::cout << maxChar;

  return 0;
  
}