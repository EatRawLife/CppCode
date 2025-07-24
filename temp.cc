#include <iostream>
#include <sstream>
#include <string>
#include <deque>
int main() {
  std::ostringstream alls;
  int command;
  std::cin >> command;
  std::cin.ignore();
  std::deque<int> q(0);




  for(int i = 0; i< command; i++){
    std::string onelinecommand;
    std::getline(std::cin, onelinecommand);
    std::stringstream onelinecommandstream(onelinecommand);
    std::string first;
    std::string second;
    std::getline(onelinecommandstream, first, ' ');

    if (first == "push"){
      std::getline(onelinecommandstream, second);
      alls << std::stoi(second) << '\n';
    }
  }

  std::cout << alls.str() << std::flush;

}