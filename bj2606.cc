//같은 네트워크에 있는 컴퓨터를 감염시킨다.
//연결되어있지 않는 컴퓨터는 영향이 없다.
//바이러스가 걸린 컴퓨터로 부터 reachable한 모든 컴퓨터의 수를 구하는 문제!
#include <iostream>
#include <sstream>
#include <vector>
int n;
int m;
int coms[101];
int visitedcoms[101];
int graph[101][101];
int infected = -1;

void traverse(int vertex){
  visitedcoms[vertex] = 1;
  infected++;

  for(int i = 1; i <= 100; i++ ){
    if(graph[vertex][i] == 1 && visitedcoms[i] == 0){
      traverse(i);
    }
  }
}

int main() {

  std::cin >> n;
  std::cin >> m;

  for(int i = 0; i< m; i++){
    int source;
    int end;
    std::cin >> source;
    std::cin >> end;
    graph[source][end] = 1;
    graph[end][source] = 1;
  }

  traverse(1);

  std::cout<<infected;
}