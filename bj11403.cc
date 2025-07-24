//directed 그래프, 인접행렬 주어짐. 0based
//i->j로의 경로가 있다면 하면 1. i i 는 사이클이 있을때만 1.
//일단은 해당 정점을 방문할때는 비짓 카운트를 안해야할듯. 
//모든 정점에서 dfs를 수행하면 될듯. 
#include <iostream>
#include <string>
#include <sstream>

int n;
int graph[100][100];
int reachable[100][100];
std::ostringstream s;

void dfs(int now, int start, bool first){
  //만약 start와 같다면 바꾸지 않는다.
  if(now != start|| first == false) {
    reachable[start][now] = 1;
  }

  for(int i = 0; i< n; i++) {
    if(graph[now][i] == 1 && now != i && reachable[start][i] == 0) {
      if(first == true)
      first = false;
      dfs(i,start, first);
    }
  }
}

int main(){

  std::cin >> n;
  for(int i = 0; i< n; i++){
    for(int j = 0; j<n; j++){
      std::cin >> graph[i][j];
    }
  }

  for(int i = 0; i< n; i++){
    dfs(i, i, true);
  }

  for(int i = 0; i< n; i++){
    for(int j = 0; j< n; j++) {
      s << reachable[i][j] << ' ';
    }
    s << '\n';
  }

  std::cout << s.str() << std::flush;
}
//이슈, 사이클을 찾는 것. 이는 방문한 걸로도 알기 힘들다.