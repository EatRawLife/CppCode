//1based
#include <iostream>
#include <deque>

int N;
int M;
int count = 0;

int visited[1001];
int graph[1001][1001];
std::deque<int> q;

void dfs(int start) {
  q.push_front(start);
  visited[start] = 1;

  while(!q.empty()) {
    int front = q.front();
    q.pop_front();

    for(int i = 1; i<=N; i++) {
      if(graph[front][i] == 1 && visited[i] == 0) {
        visited[i] = 1;
        //q.push_front(graph[front][i]); 처음에 실수한 값
        q.push_front(i);
      }
    }
  }
  count++;
}

int main(){
  std::cin >> N >> M;

  for(int i = 0; i< M; i++){
    int st;
    int en;
    std::cin >> st >> en;
    graph[st][en] = 1;
    graph[en][st] = 1;
  }

  
  
  
  for(int i = 1; i<= N; i++) {
    if(visited[i] == 0)
    dfs(i);
  }

  std::cout << count;
 
}
