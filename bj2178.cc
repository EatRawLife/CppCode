//0 based
//지나는 칸수에 시작 지점도 포함이 됨.
//나의 경우는 튜플에 현재 턴을 묶어서 표현했지만, 표준 풀이의 경우 바닥에 현재 턴수를 칠한다.(다음 턴 이동시 여기서 1더한값을칠하면 되니.)
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <deque>

int N;
int M;
int mat[100][100];
int visited[100][100];
int dx[4] = {-1,0,1,0};
int dy[4] = {0, 1, 0, -1};
typedef std::tuple<int,int> tuple;
tuple start = std::make_tuple(0,0);

int main(){
  std::cin >> N >> M;

  for(int i = 0; i< N; i++) {
    std::string st;
    std::cin >> st;
    for(int j = 0; j< M; j++) {
      mat[i][j] = st[j]-'0';
    }
  }

  std::deque<tuple> q;
  visited[0][0] = 1;
  q.push_back(start);
  //턴수라는 것을 어떻게 구현해야하는가?
  while(!q.empty()){
    int r,c,turn;
    std::tie(r,c) = q.front();
    turn = visited[r][c];
    q.pop_front();

    for(int i = 0; i< 4; i++) {
      int newr = r + dx[i];
      int newc = c + dy[i];

      if(newr >= 0 && newr <N && newc >= 0 && newc < M && mat[newr][newc] &&visited[newr][newc]==0) { //조건 틀림 한눌팔다가 하나 빼먹음.
        if(newr == N-1&& newc == M-1)
        {
          std::cout << turn +1;
          return 0;
        }

        visited[newr][newc] = turn+1;
        q.push_back(std::make_tuple(newr, newc));
      } 
    }
  }
}