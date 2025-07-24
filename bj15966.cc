//10만개 입력, n 제곱은 허락되지 않는다.> 무조건 nlogn으로 만들어야해
//수열의 길이만 알면된다.
//뽑힌 것들의 순서는 유지. a1에 대해서 다음 것은 a1값에다 이전항 +1 로 이어지는 값
//여기서는 식을 ai = a1 + i-1로 하였다.
//구하려는 것 > 부분 수열중 숫자가 차례로 이어지는 가장 긴 수열 뽑아내기.
//처음 한 생각. n제곱, i 위치에서 시작해 차례로 이어지는 수에 해당하는 곳에
//표시해두기, i+1부터 비교해서 큰거를 저장.

//해답의 핵심 > 우리가 구하는 수열에서, 항상 수열의 전항의 값이 현재 항의 값의 -1
//>> 이전 항의 모든 가능성 따질 필요 없이 값 특정 가능. 이를 이용해보자.
//dp[i] = 수열의 값이 i일때, 이를 포함하는 군계일학 수열중 i까지의 길이가 가장 긴것.
//따라서 우리가 구하는 것 > max(dp[i])
//시간 복잡도는 마지막 구하기에서 O(n), 구할때는
//현재 인덱스의 배열 값 확인 > O(1) , 이에 해당하는 dp(i)확인 O(1) , 
//무조건 연속된 값을 가져야 하므로 dp[i-1] + 1. 혹은 이 군계일학 수열 전
//다른 군계일학 수열이 훨씬 더 길었음. > max(dp[i-1] + 1, dp[i])

#include <iostream> 
#include <vector>
#include <cmath>
#include <algorithm>

int N;
std::vector<int> arr(100000);
std::vector<int> dp(1000001,0);

int main() {
  std::cin >> N;

  for(int i = 0; i< N; i++) {
    int temp = 0;
    std::cin >> temp;
    arr.at(i) = temp;
  }

  for(int i = 0; i< N; i++) {
    int thisvalue = arr[i];
    dp.at(thisvalue) = std::max(dp.at(thisvalue), dp.at(thisvalue-1) + 1);
  }
  int max = 0;
  for(int i = 0; i< 1000001; i++){
    if(max < dp[i])
    max = dp[i];
  }

  std::cout << max;
  
}

