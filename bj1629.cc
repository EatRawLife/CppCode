//일단 처음에 B를 2로 분해하자.
//반복문이 편할 것 같은데?

#include <iostream>
#include <string>

int plus[32];
int times[32];
long long A,B, C;


int main() {
  std::cin >> A >> B >> C;

  int temp = 0;
  while(B != 1) {
    if(B % 2 == 1){
      plus[temp] = 1;     
      B-=1;
    }
    B/= 2;
    times[temp] = 1;

    temp ++;
  }

  B = 1;
  for(int i = 31; i>=0; i--) {
    if(times[i] != 1) {
    }else{
      B *= 2;
    }

    if(plus[i] == 1) {
      B+= 1;
    }
  }

  long long remain = A % C;
  for(int i = 31; i>= 0; i--) {
    if(times[i] == 1) {
      remain = (remain * remain) % C;
    }
    if(plus[i] == 1) {
      remain = (A * remain) %C;
    }
  }

  std::cout << remain;
}