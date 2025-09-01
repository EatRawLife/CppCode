//1~N의 사람의 인출 시간 주어짐.
//특정 순서로 사람을 세웠을때, 각사람의 기다림
//각사 기다리는 시간(인출을 시각하는 시각)의 합의 최소'값만' 구하라
//모든 순열 > 최대 1000!. 말이 안됨.
//N명의 기다리는 시간 최소 > 일단가장 인출시각이 긴녀석을 뒤에 배치.
//뭐라고 설명은 못하나. 인출 오래걸리는 놈이 뒤로가도, 그녀석의 인출시각은 포함이 안되서 굿.

//문제는 그리디 알고리즘 이었다.
//각 항에 대해서 기다림 + 인출은
//일단 변경되지 않는 인출시간 + 앞의 항의 기다림 시간 합이다.
//모든 사람의 기다리는 시간합에서는, 앞에 처리한 사람의 시간이 더 많이 포함,
//따라서 긴놈이 젤뒤로 가야함.

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> v;
  for(int i = 0; i< N; i++) {
    int temp;
    std::cin >> temp;
    v.push_back(temp);
  }

  std::sort(v.begin(), v.end());

  std::vector<int> sizev;
  sizev.push_back(0);
  for(int i = 1; i<v.size();  i++) {
    int sum = v.at(i-1)+ sizev.at(i-1);
    sizev.push_back(sum);
  }

  int sum = 0;

  for(int i = 0; i<sizev.size(); i++) {
    sum += sizev.at(i) + v.at(i);
  }

  std::cout << sum;
}

