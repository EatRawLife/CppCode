<<<<<<< HEAD
//보기엔 쉬워보임. 단순하게 배열을 만들어 놓고 계산을 하게 되면 될 거같다.
//하지만 그대로 합치면 시간 오버. (최악 . 1024*1024개 합을 100000만번 > 100초)
//1based
//중복되는 부분은, 앞의 값들을 더하는 부분들.
//앞을 모두 더하고 나서 해당되지 않는 부분의 합을 빼버리면 될 것 같음.
//sum(n,n) = sum(n-1,n-1) 
=======
//1024 * 1024 개의 최대 합의 경우, 이를 10만번, 그냥은 택도없다.
//부분합을 이용.
//sum 매트릭스의 각 항의 값 = 처음부터 그항까지의 합
//중간시작 -> 끝 = (처음 > 끝) -(처음 > 아래끝) - (처음 > 우끝) +(처음 > 중간시작 )
//채우는건 아래부터 좌측 더하기 아래.
//배열에 접근은 1 based. 입력으로 오는 값들을 모두 -1해서 받자.
//즉 내부적으로는 0based처리.

#include <iostream>
#include <vector>
#include <sstream>
#include <utility>//std::pair

int N;
int M;
int sum[1024][1024];
int matrix[1024][1024]; //뒤늣게 추가
std::ostringstream out;

int main() {
  std::cin >> N >> M;

  for(int i = 0; i< N; i++) {
    for(int j = 0;j< N; j++) {
      std::cin >> matrix[i][j];
    }
  }

  for(int i = 0; i< N; i++) {
    for(int j = 0;j< N; j++) {
      int temp = matrix[i][j];//이것도 뒤늦게 추가.
      if(i > 0) temp += sum[i-1][j];
      if(j > 0) temp += sum[i][j-1];
      if(i > 0 && j > 0) temp -= sum[i-1][j-1];
      sum[i][j] = temp;

    }
  }

  for(int i = 0; i<M; i++) {
    int sx;
    int sy;
    int ex;
    int ey;
    std::cin >> sx >> sy >> ex >> ey;
    sx -= 1;
    sy -= 1;
    ex -= 1;
    ey -= 1;

    int res = sum[ex][ey];
    if(sx > 0) res -= sum[sx -1][ey];//이거
    if(sy > 0) res -= sum[ex][sy -1]; //반대로 해서 시간 많이 잡아먹음 
    if(sx > 0 && sy > 0) res+= sum[sx-1][sy-1];

    out << res << '\n';


  }
  std::cout << out.str() << std::flush;
}

//2번째 출력에 시간 많이 씀.
//59:03
>>>>>>> b833100 (현재까지 모든 추가, 노트북)
