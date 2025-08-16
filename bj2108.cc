//풀이시간 약 한시간
//구현, 얼마나 입출력, 라이브러리를 자유자재로 이용하는가
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> v;
  int n;
  std::cin >> n;

  for(int i = 0; i< n; i++) {
    int temp;
    std::cin >> temp;

    v.push_back(temp);
  }

  double mean;
  long long sum;
  int median;
  int freq;
  int bum;

  sum = 0;//첨에 초기화 안함
  std::vector<int> freqv(8002,0);//처음에 사이즈 지정안해 세그폴트, '절대값'4000안읽음.

  for(int i = 0; i<n; i++) {
    sum += v[i];
    freqv[v[i]+4000]++;
  }

  mean = sum/(double)n;

  sort(v.begin(), v.end());

  median = v[n/2];
  bum = v.back()- v.front();

  bool second = false;
  int max = 0;

  for(int i = 1; i< freqv.size(); i++){
    if(freqv[max] <freqv[i]){
      second = false;
      max = i;
    }
    else if(freqv[max] == freqv[i]&& second ==false){
      second = true;
      max = i;
    }
    else{}
  }

  freq = max-4000;

  std::cout <<std::fixed;//몰랐던 부분
  std::cout.precision(0);

  if(-0.5 <= mean && mean <0){
    mean = 0;
  }

  std::cout << mean << '\n'<< median << '\n' << freq << '\n' << bum;
  //mean 그대로 하니 -0으로 뜨더라?..

}