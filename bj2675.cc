#include <iostream>
#include <string>
#include <cstdio>

int main(){
  int count;
  
  std::cin >> count;

  for(int i = 0; i < count ; i++){
    int repeat;
    std::string s;
    std::cin >> repeat;
    std::cin >> s;
    std::string result = "";
    for(int i = 0; i < s.length(); i++){
      char nowrepeat = s.at(i);
      for (int i = 0; i< repeat; i++){
        result += nowrepeat;
      }
    }
    std :: cout << result<<std::endl;
    result = "";
  }

}