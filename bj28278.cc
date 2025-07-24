#include <vector>
#include <iostream>
#include <sstream>

int main(){
  int size;
  std::cin >> size;

  std::vector<int> v(0);
  std::ostringstream oss;

  for (int i = 0; i< size ; i++){
    int command;
    std::cin >> command;
    if(command == 1){
      int insert;
      std::cin >> insert;
      v.push_back(insert);
    } else if(command == 2){
      if(v.size() <= 0){
        oss << -1<< '\n';
      }
      else{
        oss << v.at(v.size()-1)<<'\n';
        v.pop_back();
      }
    } else if(command == 3) {
      oss << v.size()<< '\n';
    } else if (command == 4) {
      if(v.size() == 0)
      oss << 1<< '\n';
      else
      oss << 0<< '\n';
    } else {
      if(v.size() <= 0)
      oss << -1<< '\n';
      else
      oss << v.at(v.size()-1)<<'\n';
    }
  }
  std::cout<< oss.str() << std::flush;
  return 0;

}