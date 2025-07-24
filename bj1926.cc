//0based
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
int N;
int M;
int count = 0;

int graph[500][500];
std::deque<int> st;
std::vector<int> compo;


int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int dfs(int x, int y) {
  int length = 0;
  st.push_front(x);
  st.push_front(y);
  graph[x][y] = 0;
  length++;

  while(!st.empty()) {
    int y = st.front();
    st.pop_front();
    int x = st.front();
    st.pop_front();


    for(int i = 0; i<4; i++) {
      int newx = x+ dx[i];
      int newy = y+ dy[i];
      if(graph[newx][newy] == 1 && newx >= 0 && newx < N && newy>=0 && newy <M) {//x, y 조건 검사 안걸어서 오류남. c++은 [] 검사 안하니 조심. 이를 막을 방법도 빨리좀 알아보자.
        graph[newx][newy] = 0;
        length++;
        st.push_front(newx);
        st.push_front(newy);
      }
    }
  }
  count++;
  return length;
}

int main(){
  compo.push_back(0);//그림이 없어도 길이는 0. 조건을 제대로 안읽어서 생겼다.
  std::cin >> N >> M;

  for(int i = 0; i< N; i++){
    for(int j = 0; j< M; j++) {
      std::cin >> graph[i][j];
    }
  }
  
  /*
  for(int i = 0; i< N; i++) {
    for(int j = 0; j<M; j++) {
      if(graph[i][j] == 1)
      compo.push_back(dfs(i,j));
    }
  } 수정전, 이전 코드 재활용해서 이런 일이 일어남
    */

  for(int i = 0; i< N; i++) {
    for(int j = 0; j<M; j++) {
      if(graph[i][j] == 1)
      compo.push_back(dfs(i,j));
    }
  }

  sort(compo.begin(), compo.end());

  std::cout << count << '\n'<<compo.back();

 
}
