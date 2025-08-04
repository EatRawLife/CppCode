#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>


typedef std::tuple<int, int> stuff;
int N;
int K;
std::vector<stuff> l;
//1based, 물건 인덱스 0번은 아무것도 더하지 않은 케이스 위해, 무게 인덱스 0번은 입력이 1based로 들어와서.
int weigh[101][100001];

int main() {
  std::cin >> N >> K;
  for(int i = 0 ; i< N; i++) {
    int one, two;
    std::cin >> one >> two;
    stuff temp = std::make_tuple(one,two);
    l.push_back(temp);
  }

  for(int i = 1; i<=N; i++ ){
    int w, v;
    std::tie(w, v) = l.at(i-1);//벡터는 어쩔수 없이 0based임을 고려한 i-1.
    for(int limit = 1; limit <= K; limit++) {
      if(w> limit)
      weigh[i][limit] = weigh[i-1][limit];
      else{
        int plus,stay;
        stay = weigh[i-1][limit];
        plus = weigh[i-1][limit-w] + v;

        if(stay >plus){
          weigh[i][limit] = stay;
        }
        else
        weigh[i][limit] = plus;
      }
    }
  }
  
  std::cout << weigh[N][K];
}
