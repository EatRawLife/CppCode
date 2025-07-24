#include <string>
#include <iostream>
#include <array>

int main(){
  std::array<int,26> alphalist;
  alphalist.fill(-1);

  std::string s;
  std::cin >> s;
  for(int i = 0; i< s.size(); i ++){
    int thisPositionAlphabet = s.at(i) -97;
    if(alphalist.at(thisPositionAlphabet) == -1){
      alphalist.at(thisPositionAlphabet) = i;
    } 
  }

  for(int i = 0 ; i< 26; i++){
    std::cout << alphalist.at(i) << " ";
  }
}