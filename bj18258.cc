#include <deque>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

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
    std::getline(onelinecommandstream, first, ' ');
    std::string second;

    if (first == "push"){
      std::getline(onelinecommandstream,second);
      q.push_front(std::stoi(second));
    } else if (first == "pop") { 
      if(q.size() <= 0){
        alls <<"-1\n";
        continue;
      }
      alls << q.back() << '\n';
      q.pop_back();
    } else if (first == "size") {
      alls << q.size() << '\n';
    } else if (first == "front") {
      if(q.size() == 0)
      alls << "-1\n";
      else
      alls << q.back() << '\n';
    } else if (first == "empty") {
      if(q.size() == 0)
      alls << "1\n";
      else
      alls << "0\n";
    } else if (first == "back") {
      if(q.size() == 0)
      alls << "-1\n";
      else
      alls << q.front() << '\n';
    }
  }
  std::cout << alls.str() << std::flush;

}

//틀린 이유 > 오류 코드를 제대로 안봐서.(백준에서 주는, 복잡도 문제는 없었다.)
//구현시에 이처럼 기능을 제한하는 경우 내가 구현할 자료구조가 애초에 여기 쓰는거 이상의 메소드를 가지는지도 살펴야할것, 없다면 미리 배제
//stringstream을 이용해서 라인을 분절하는 것, 아웃스트림을 모으는 것도 확실히 정리
// 