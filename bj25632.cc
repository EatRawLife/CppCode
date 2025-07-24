//그리디로 풀었다.
//소수중에서
//겹치는걸 먼저 말하고, 그뒤에 안겹치는걸 말하면 이긴다.
//구현위해 집합을 이용했다.
//집합 사용법.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::vector<int> arr;

int main() {
  arr.push_back(0);
  arr.push_back(0);
  for(int i = 2; i<=1000; i++ ) {
    bool mini = true;
    for(int j = 2; j<i; j++) {
      if(i%j == 0){
        mini = false;
        break;
      }
    }
    if(mini == true)
    arr.push_back(1);
    else
    arr.push_back(0);
  }

  int a;
  int b;
  std::cin >> a >> b;
  std::set<int> setone;
  for(int i = a; i<= b; i++) {
    if (arr.at(i) == 1)
      setone.insert(i);
  }

  std::cin >> a >> b;
  std::set<int> settwo;
  for(int i = a; i<= b; i++) {
    if (arr.at(i) == 1)
      settwo.insert(i);
  }

  std::vector<int> result_set;
  std::vector<int> v1;
  std::vector<int> v2;
  std::set_intersection(
        setone.begin(), setone.end(),
        settwo.begin(), settwo.end(),
        std::back_inserter(result_set)
    );
  std::set_difference(
        setone.begin(), setone.end(),
        settwo.begin(), settwo.end(),
        std::back_inserter(v1)
    );
  std::set_difference(//메소드 사용법이 틀려서 틀렸었다.
        settwo.begin(), settwo.end(), 
        setone.begin(), setone.end(),    
        std::back_inserter(v2)
    );
  
  int turn = 1;

  while(true) {
    turn = (turn+1)%2;

    if(!result_set.empty()){
      
      result_set.pop_back();
    } else if(turn == 0){
      if(!v1.empty()) {
        
        v1.pop_back();
      } else {
        break;
      }
    } else {
      if(!v2.empty()) {
        v2.pop_back();
      } else {
        break;
      }

    }
  }

  if(turn == 0){
    std::cout << "yj";
  } else{
    std::cout << "yt";
  }

}