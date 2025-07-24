//11660에서 진짜 일부만 수정.
//단 합이가장 큰 x 길이가 가장 긴 감소 수열 길이를 출력.
#include <iostream>
#include <vector>

int N;
std::vector<int> arr; //실제 배열
std::vector<int> sum; //구할 배열


int main() {
  std::cin >> N;
  for(int i = 0; i< N; i++) {
    int a;
    std::cin >> a;
    arr.push_back(a);
  }
  
  sum.push_back(1);//초기 조건 세팅

  for(int i = 1; i< N; i++) {
    int length = 1;
    int valueofarri = arr[i];
    for(int j = 0; j<i; j++) {
      if(valueofarri < arr[j] && length < sum[j] + 1){
        length = sum[j]+1;
      }
    }
    sum.push_back(length);
  }

  int max = 0;
  for(int i = 0; i< N; i++) {
    if(sum[i] > max){
      max = sum[i];
    }
  }

  std::cout << max;
}
