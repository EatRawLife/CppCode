//일단 처음에 B를 2로 분해하자.
//만약 승수가 1이라면 A%C 가 나머지.
//승수가 2N이라면 N 까지의 나머지의 제곱한 값. (나는 위에서 아래로 하면 안될것 같았는데 결국 ㅇ아래에서 위로 올라오네)
//2N+1이라면 나머지에 N을 곱한값.
#include <iostream>
#include <string>

int plus[32];
int times[32];
long long A,B, C;

int calcremain(long long A, long long B, long long C) {
  if(B == 1) {
    return A%C;
  }

  long long remain = calcremain(A,B/2,C);
  remain = remain*remain %C;

  if(B%2 == 1) {
    remain = remain*A %C;
  }

  return remain;
}

int main() {
  std::cin >> A >> B >> C;

  std::cout << calcremain(A,B,C);

  
}