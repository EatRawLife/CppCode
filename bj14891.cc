//톱니 네개.
//각 톱니는 4*8 배열에 각기 저장.
//문제 완전 잘못 읽음 극이 다름 X 극이 같음 o. + 바뀐후x 처음 상태로 움직임.
//top은 현재 제일 위가 array 배열의 몇번인덱스 원소인지.
//1이 S극, 시계 1 반시계 -1.
//반복문으로 값을 받아서, 해당 톱니의 회전 방향을 확인, 또 좌 우 로 반복문써서
//톱니의 회전 여부 확인.

#include <iostream>
#include <string>
int N;
std::string s;

int array[4][8];
int top[4] = {0,0,0,0};
int rotate[4] = {0,0,0,0};

int main() {
  for(int i = 0; i< 4; i++){
    std::cin >> s;
    for(int j = 0; j< 8; j++) {
      array[i][j] = s.at(j) - 48;
    }
  }

  std::cin >> N;


  for(int i = 0; i< N; i++) {
    int whattool, whatdirec; //바퀴는 +1해야
    std::cin >> whattool >> whatdirec;
    whattool--;
    rotate[whattool] = whatdirec;

    for(int left = whattool-1; left>=0; left--){
      if(array[left+1][(top[left+1] + 6)%8] != array[left][(top[left]+2)%8]){//잘못 읽어서 ==
        rotate[left] = -rotate[left+1];
      }
    }
    for(int right = whattool+1; right <=3; right++){
      if(array[right][(top[right] + 6)%8] != array[right-1][(top[right-1]+2)%8]){
        rotate[right] = -rotate[right-1];
      }
    }

    for(int j = 0; j< 4; j++) {
      if(rotate[j] == 1){
        top[j] = (top[j] + 7)%8; // 오버플로우 고려한 설계
      } else if(rotate[j] == -1) {
        top[j] = (top[j] + 1)%8;
      } else {}
      rotate[j] =0;//처음에 없었음. 무엇을 초기화하는지 잘 생각해봐야할 것 같음
    }
  }

  int sum = 0;
  int kkk = 1;
  for(int i = 0; i< 4; i++) {
    
    sum+= array[i][(top[i])%8] * kkk;
    kkk*=2;
  }

  std::cout << sum<<'\n';
}