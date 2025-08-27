//두 땅 높이 사이에 임의의 값으로 조정해야함.
//그 경우의 최소 값으로.
//땅의 높이와 그 최소 시간으로. 
//땅넗이는 최대 25만개.
//땅의 높이는 최대 0~256
//브루트로 될 것 같음.

#include <iostream>
#include <vector>

int N,M,B;
int array[500][500];
std::vector<int> cost(257,-1);
int main(){
  std::cin >> N >> M >>B;
  
  for(int i = 0; i< N; i++) {
    for(int j = 0 ;j < M; j++) {
      std::cin >> array[i][j];
    }
  }

  int remainb = B;
  int sum = 0;

  for(int i = 0; i<= 256; i++) {
    for(int r = 0; r < N ; r++) {//실수로 <=
      for(int c = 0; c < M; c++) {
        int xfix = array[r][c];
        if(xfix > i) {
          sum += 2*(xfix-i);
          remainb+= xfix-i;//문제 제대로 안읽음.
        }else {
          sum += (i-xfix);
          remainb -= (i-xfix);
        }
      }
    }
    if(remainb >= 0){
    cost[i] = sum;
    }
    remainb = B;
    sum = 0; //처음에 빼먹음.
  }

  int min = cost[0];
  int pos = 0;

  for(int i = 0; i<= 256; i++) {
    if(cost[i]>=0 && cost[i] <= min){
      min = cost[i];
      pos = i;
      
    }
  }
  std::cout << min <<' '<< pos;



  

}