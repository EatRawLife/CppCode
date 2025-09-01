//시간 초과...
//처음에 DP로 접근했으나 시간이...
//최단 거리 찾는 BFS 문제였다.

//BFS는 짧은 거리 케이스가 먼저 처리되서 빠를 것.
//DP는 깊이 우선 탐색 처럼 작동해, 말도 안되는 케이스까지 일단 다 계산후 갱신할테니 느릴 것.
#include<iostream>
#include<deque>
#include<tuple>

bool visit[100001];
int s, e;



int main() {
  for(int i = 0; i<=100000; i++){
    visit[i] = false;
  }

  std::cin >> s >> e;

  std::deque<std::tuple<int,int>> q;
  q.push_back(std::make_tuple(s,0));
  visit[s] = true;

  while(true){
    int posi, turn;
    std::tie(posi,turn) = q.front();
    visit[posi] = true;//이걸 안했네.. 처음에 visit 배열 추가할때 부터 이를 어떻게 관리할지 생각하고 처리해 줬어야지...
    q.pop_front();
    if(posi == e){
      std::cout << turn;
      return 0;
    }

    if(posi+1 >=0 && posi+1 <= 100000 && !visit[posi+1]){
      q.push_back(std::make_tuple(posi+1,turn+1));
    }
    if(posi-1 >=0 && posi-1 <= 100000 && !visit[posi-1]){
      q.push_back(std::make_tuple(posi-1,turn+1));
    }
    if(posi*2 >=0 && posi*2 <= 100000 && !visit[posi*2]){
      q.push_back(std::make_tuple(posi*2,turn+1));
    }
  }
}