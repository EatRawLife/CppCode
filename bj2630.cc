//전체 종이의 한변은 2의 승수
//종이부분이 같은 색이 아니라면 가로세로를 절반으로 잘르기. 
//이를 종이가 모두 같은색인 작은 종이가 될때까지.
//마지막에는 각색깔의 색종이 수를 출력.
//딱 보니 재귀긴 함.
//글로벌한 종이갯수 블루와 화이트
//함수 > 시작 지점(좌측위) 가로 세로 길이를 받아. 만족하면 종료와 종이 카운트,
//그렇지 않으면 재호출 (4부분)

//20분컷, 개쉬움;;

#include <iostream>
#include <string>

int blue = 0;
int white = 0;

int arr[128][128];
int N;

void call(int r, int c, int len){
  int nd = 1;
  int o = 0;

  for(int i = r; i < r+len; i++) {
    for(int j = c; j<c+len; j++) {
      nd = nd&arr[i][j];
      o = o|arr[i][j];
    }
  }
  if(nd == 1){
    blue++;
    return;
  }
  if(o == 0) {
    white++;
    return;
  }

  call(r,c,len/2);
  call(r+len/2,c,len/2);
  call(r,c+len/2,len/2);
  call(r+len/2,c+len/2,len/2);

}

int main() {
  std::cin >> N;
  for(int i = 0; i< N; i++) {
    for(int j = 0; j< N; j++) {
      std::cin >> arr[i][j];
    }
  }

  call(0,0,N);

  std::cout << white << '\n' << blue;
}