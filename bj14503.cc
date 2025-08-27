//일단 현재칸 청소 가능 ->청소
//주변 4칸 청소할곳 존재 -> 반시계 90 회전 > 전진 -> 1번
//주변 4칸 청소불가 -> 방향 유지 후진, 후진 불가시 종료.
//DFS로 풀 수 잇다고?

#include<iostream>

int N,M,d;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int posix, posiy, posidirec;
int array[50][50];
int count = 0;

int main() {
  std::cin >> N >> M;
  std::cin >> posix >> posiy >> posidirec;

  for(int i = 0; i< N; i++) {
    for(int j = 0; j< M; j++) {
      std::cin >> array[i][j];
    }
  }

  while(true) {
    bool pass = false;

    if(array[posix][posiy] == 0){
      array[posix][posiy] = -1;
      count++;
    }

    for(int i = 0; i<4; i++ ){
      posidirec = (posidirec+3)%4;//처음에 3 , 6, 9 이렇게 더해서 틀림. 반복에 따라 변수가 변하고 있음을 잊지 말아야했음.ㅅㅂ
      int newr = posix + dr[posidirec];
      int newc = posiy + dc[posidirec];
      if(array[newr][newc]== 0){
        posix = newr;
        posiy = newc;
        pass = true;
        break;
      }
    }

    if(pass == false){
      
      int newr = posix - dr[posidirec];
      int newc = posiy - dc[posidirec];
      if(array[newr][newc]!=1){
        posix = newr;
        posiy = newc;
      }else {
        std::cout << count;
        return 0;
      }
    }

    
  }
  
}