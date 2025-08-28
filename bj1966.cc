//큐 구조.
//앞의 중요도 확인, 낮으면 뒤로., 중복존재
//실패
#include <iostream>
#include <deque>
void realmain(){
  int M, nowposi;
  std::cin >> M >> nowposi;
  std::deque<int> q;

  for(int i = 0; i<M; i++) {
    int temp;
    std::cin >> temp;
    q.push_back(temp);
  }

  int firstsize = q.size();

  while(nowposi != -1) {
    int max = 0;
    for(int i : q) {
      if(i > max)
      max = i;
    }

    if(q.front() < max){
      int temp;
      temp = q.front();
      q.pop_front();
      nowposi--;
      q.push_back(temp);
      if(nowposi == -1){
        nowposi = q.size() -1;
      }

    
    } else {
      q.pop_front();
      nowposi--;
    }
  
  }

  std::cout << firstsize-q.size() << '\n';
  
}

int main() {
  int N;
  std::cin >> N;
  for(int i = 0; i< N; i++) {
    realmain();
  }
}