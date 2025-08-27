//돌리려면 작은 행, 열중에서 딱그 절반만 필요.

#include <iostream>

int N,M,count;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
  std::cin >> N >> M >> count;
  int limit = N>M ? (M/2) : (N/2);
  
  if (limit%2 == 1)
  limit++;

  int array[N][M];

  for(int i = 0; i< N; i++) {
    for(int j = 0; j<M; j++) {
      std::cin >> array[i][j];
    }
  }



  for(int rotate = 0; rotate < count; rotate++){
    int newarray[N][M];
    int status = 0;
    bool visited[N][M];
    for(int i = 0; i< N; i++) {
      for(int j = 0 ; j< M; j++) {
        visited[i][j] = 0;
      }
    }//ㅅㅂ 이거 초기화 해줘야해??? 이거 스펙 알아보기
    for(int i = 0; i< limit; i++){
      int r = i, c = i;
      while(status < 4){//status <=4 실수
        int newr, newc;
        newr = r + dx[status], newc = c + dy[status];
        if(newr>=0 && newr<N && newc<M && newc>=0 && visited[newr][newc] == false){
          visited[newr][newc] = true;
          newarray[newr][newc] = array[r][c];
          r = newr, c = newc;
          
        } else {
          status++;
        }
      }
      status = 0;
    }// 포인터 이용해서 별도 함수로 구현해보기.
    
    for(int i = 0; i< N; i++) {
      for(int j = 0; j<M; j++) {
        array[i][j] = newarray[i][j];
      }
    }
  }

  for(int i = 0; i< N; i++) {
    for(int j = 0; j<M; j++) {
      std::cout<< array[i][j] << ' ';
    }
    std::cout << '\n';
  }
  
}