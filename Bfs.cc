#include <iostream>
#include <sstream>
#include <deque>
int n;
int m;
int start;
int v1[1001];
int v2[1001];
int mat[1001][1001];
int bfsvisit[1001];
int dfsvisit[1001];
std::ostringstream outputstring;

void dfs(int vertex){
  dfsvisit[vertex] = 1;
  outputstring << vertex << ' ';

  for(int i = 1; i <= n; i++){
    if(mat[vertex][i] == 1 && dfsvisit[i] == 0)
    dfs(i); 
  }
}

void bfs(int start) {
  std::deque<int> q;
  q.push_front(start);
  bfsvisit[start] = 1;

  while(!q.empty()){
    int vertex = q.back();
    q.pop_back();
    
    outputstring << vertex << ' ';

    for(int i = 1; i<=n; i++) {
      if(mat[vertex][i] == 1 && bfsvisit[i]==0){
        q.push_front(i);
        bfsvisit[i] = 1;//탐색전에, 미리 큐에 같은 버텍스 삽입 방지
      }
    }
  }
}

int main(){
  std::cin >> n;
  std::cin >> m;
  std::cin >> start;

  for(int i = 0; i< m; i++){
    int st;
    int en;

    std::cin >> st;
    std::cin >> en;

    mat[st][en] = 1;
    mat[en][st] = 1;
  }
  // 표준입력 받아서 그래프 만들기

  dfs(start);
  outputstring << '\n';
  bfs(start);

  std::cout << outputstring.str() << std::flush;
  //출력
}
//문제 생김. 깊이 n에 4로 가는 경로가 두개라면, 4가 다 추가 될 것. 왜냐. 이는 이전
//자식을 큐에 추가할때는 이미 넣은거 인지 확인 안할테니.
