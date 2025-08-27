#include <iostream> 

void calc(){
    long long a, b;
    std::cin >> a >> b;
    
    int remain = 1;
    for(int i = 0; i< b; i++) {
        remain *= a;
        remain = remain % 10;
    }
    if(remain == 0){
      std::cout << 10 << '\n';//0번컴퓨터 없음
    } else {
      std::cout << remain << '\n';
    }
  }

int main() {
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
      calc();
    }
}