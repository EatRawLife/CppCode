#include <iostream>

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int N;
int array[999][999];
int main(){
  std::cin >>N;
  int start = N/2;
  int find;
  std::cin >> find;
  int r = start, c = start;
  int tracer, tracec;

  int count = 0;
  int length = 1;
  int status = 0;
  int num = 1;

  while(num <=N*N) {
    

    if(count == 2){
      count = 0;
      length++;
      
    }
    for(int i = 0; i< length ; i++) {
      array[r][c] = num;
      r = r+dx[status];
      c = c+dy[status];
      num++;
      
    }
    status = (status+1)%4;
    count++;
  }


  
  for(int i = 0; i<N ;i++) {
    for(int j = 0; j<N; j++) {
      if(array[i][j] == find)
      tracer = i+1, tracec = j+1;

      std::cout << array[i][j]<<' ';
    }
    std::cout << '\n';
  }
  std::cout << tracer << ' '<< tracec;
}