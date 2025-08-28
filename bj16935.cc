//쌩구현 문제.
//모양이 변하는 경우 어떻게하면 효과적으로 처리할까?
//저장을 위한 변수 타입을 int[N][M]처럼 고정해야하는데 변경되면 곤란해..
//배열 선언 조심. 사이즈 이상하게해도 [] 사용시 정상은 실행은되며 이상하게 실행되는 경우 존재.

#include <iostream>

int N, M, R;

int main() {



  std::cin >> N >> M >> R;

  int arr[N*M];

  for(int i = 0; i< N; i++) {
    for(int j = 0; j< M; j++) {
      std::cin >> arr[i * M + j];
    }
  }

  for(int i = 0; i< R; i++) {
    int type;
    std::cin >> type;
    int temparr[N*M];//N+M인데 처 오류가 안나네;;

    switch(type) {
      case(1):
        for(int i = 0; i< N; i++){
          for(int j = 0; j< M; j++) {
            temparr[i*M + j] = arr[M*(N-i-1) + j];
          }
        }
        break;
      case(2):
        for(int i = 0; i< N; i++){
          for(int j = 0; j< M; j++) {
            temparr[i* M + M-j - 1] = arr[i*M + j];
          }
        }
      break;
      case(3):{//행 > 열이 됨 + 작은쪽이 크게, 열 >> 행.
        for(int i = 0; i< N; i++){
          for(int j = 0; j< M; j++) {// 기존 배열 모양에서 바꾸기.
            temparr[j*N + (N-i-1) ] = arr[i*M + j];
          }
        }
        int temp= N;
        N = M;
        M = temp;
        break;
      }
      case(4):{//열 >> 행이됨 + 작은쪽이 크게 , 행 >> 열.
        for(int i = 0; i< N; i++){
          for(int j = 0; j< M; j++) {// 기존 배열 모양에서 바꾸기.
            temparr[(M-1-j)*N + i ] = arr[i*M + j];
          }
        }
        int temp= N;
        N = M;
        M = temp;
        break;
      }
      case(5):{
        for(int i = 0; i<N/2; i++){
          for(int j = 0; j< M/2; j++) {
            temparr[i*M + j+M/2] = arr[i*M+j];
          }
        }
        for(int i = 0; i<N/2; i++){
          for(int j = M/2; j< M; j++) {
            temparr[(i+N/2)*M + j] = arr[i*M+j];
          }
        }
        for(int i = N/2; i<N; i++){
          for(int j = M/2; j< M; j++) {
            temparr[i*M + j-M/2] = arr[i*M+j];
          }
        }
        for(int i = N/2; i<N; i++){
          for(int j = 0; j< M/2; j++) {
            temparr[(i-N/2)*M + j] = arr[i*M+j];
          }
        }
        break;
      }
      case(6):
      {
        for(int i = 0; i<N/2; i++){
          for(int j = 0; j< M/2; j++) {
            temparr[(i+N/2)*M + j] = arr[i*M+j];
          }
        }
        for(int i = 0; i<N/2; i++){
          for(int j = M/2; j< M; j++) {
            temparr[i*M + j-M/2] = arr[i*M+j];
          }
        }
        for(int i = N/2; i<N; i++){
          for(int j = M/2; j< M; j++) {
            temparr[(i-N/2)*M + j] = arr[i*M+j];
          }
        }
        for(int i = N/2; i<N; i++){
          for(int j = 0; j< M/2; j++) {
            temparr[i*M + j+M/2] = arr[i*M+j];
          }
        }
        break;
      }
      break;
    }
    for(int i = 0; i< N; i++) {
      for(int j = 0; j< M; j++) {
        arr[i*M+j] = temparr[i*M+j];
      }
    }

  }
  for(int i = 0; i< N; i++) {
    for(int j = 0 ;j<M; j++) {
      std::cout << arr[i*M+j]<< ' ';
    }
    std::cout << '\n';
  }


  
  
}