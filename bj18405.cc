//N*N 시험관에 1~K번째 바이러스.
//BFS를 이용해서 풀자.
//바이러스는 1based
//위치도 1based

//하나의 바이러스가 있는 경우스텝 진행이 안되는 경우를 고려못함.
// 작성중에 꼬이는것 어떻게 개선할까

#include <iostream>
#include <deque>
#include <tuple>

int N,M;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


int main() {
  std::cin >> N >> M;
  int arr[N][N];

  for(int i = 0 ;i < N; i++) {
    for(int j = 0; j< N; j++) {
      std::cin >> arr[i][j];
    }
  }

  std::deque<std::tuple<int,int,int>> q;

  for(int i = 1; i<= M; i++){
    for(int x = 0; x < N; x++) {
      for(int y = 0; y<N; y++) {
        if(arr[x][y] == i) {
          q.push_back(std::make_tuple(i,x,y));
        }
      }
    }
  }
  int limit;
  std::cin >> limit;

  q.push_front(std::make_tuple(0,0,0));
  
  int step = 0;
  while(!q.empty()) {
    int kind, x, y;
    std::tie(kind,x,y) = q.front();

    if(kind == 0){
      step++;
      q.push_back(std::make_tuple(0,0,0));
      q.pop_front();
      
      if(step > limit || q.size() <= 1){
        break;
      }
      continue;//만약 스텝 처리하는건 밑으로 내려가면 안되지, 밑에 내려가게해서 문제 남.
    //이런건 디버깅할때 어떻게 쉽게 알아챌 수 있을까.
    }
    q.pop_front();

    for(int i = 0; i< 4; i++) {
      int newx = dx[i] + x; 
      int newy = dy[i] + y;

      if(newx>= 0 && newx<N && newy>=0 && newy<N && arr[newx][newy] == 0 ){
        arr[newx][newy] = kind;
        q.push_back(std::make_tuple(kind,newx, newy));
      }
    }
  }

  int tx, ty;
  std::cin >> tx >> ty;
  std::cout << arr[tx-1][ty-1];
  return 0;

}