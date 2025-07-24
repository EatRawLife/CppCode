#include <string>
#include <iostream>
int main(){
  std::string a;
  std::string b("hello");
  std::string c(5, 'x');
  std::string d(b);
  std::string str("");

  std::getline(std::cin, str);
}