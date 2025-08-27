//큐 구조.
//앞의 중요도 확인, 낮으면 뒤로., 중복존재
//실패
#include <iostream>
#include <deque>
void realmain(){
  int M, posi;
  std::cin >> M >> posi;
  std::deque<int> q;
  int first = q.size();

  for(int i = 0; i< M; i++){
    int temp;
    std::cin >> temp;
    q.push_back(temp);
  }
  while(posi != -1) {
    int max = 0;
    for(int i : q) {
      if(max < i)
      max = i;
    }
    if(q.front() == max){
      q.pop_front();
      posi--;
    } else {
      int temp = q.front();
      q.pop_front();
      q.push_back(temp);
      if(posi == 0){
        posi =q.size() -1; 
      } else {
        posi--;
      }
    }
  }

  std::cout << (first - q.size() )<<'\n';
}

int main() {
  int N;
  std::cin >> N;
  for(int i = 0; i< N; i++) {
    realmain();
  }
}