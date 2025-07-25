#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

//https://en.cppreference.com/w/cpp/language/operator_arithmetic.html 문서 읽기 해보기

/*
typedef struct {
  int w;
  int v;
  double rv;
} back; 
 */
//스트럭트를 쓸 수 도 있지만, 3개 이상의 인자를 가진, 튜플을 이용할 수도 있다.
//원소 접근 > std::get<인덱스>(튜플);
//튜플 생성 > make_tuple(원소.....);

//typedef 대해서도 알아야.

typedef std::tuple<int, int, double> back;
int N, M;
std::vector<back> v;

bool compare(back b1, back b2){
  return std::get<2>(b1) < std::get<2>(b2);
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int temp1;
        int temp2;
        std::cin >> temp1 >> temp2;
        back temp = std::make_tuple(temp1, temp2, (temp2 /(double)temp1)); // 보통 double 만들기 하려면 뒤에 거에 double 붙이더라
        v.push_back(temp);
    }
    sort(v.begin(),v.end(), compare);//알고리즘의 sort 메소드는 어떻게 사용할 것인가, std:: 왜 안붙여도 되는가, compare 이없다면 어디를 따라가는가


    double sum= 0;
    int limit = M;
    for(int i = v.size()-1; i>= 0; i--) {
      if(limit >= std::get<0>(v[i])){
        sum += std::get<1>(v[i]);
        limit -= std::get<0>(v[i]);
      } else {
        sum += limit * std::get<2>(v[i]);
        break; //알고리즘 풀때 집중! 뭐하나 빼먹지 않게.
      }
      
    }
   

    //printf("%.3f", sum);
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << sum;




    return 0;
}
