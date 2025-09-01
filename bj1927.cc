//log n으로 모두 처리해야함.

//어려웠다... 단순 구현인데 똥을 좀 많이쌌다.
//C++에서 힙을 사용할 방법은??


#include <iostream>
#include <vector>
#include <utility>



int hip[100001];
int size = 0;

void deletemin() {

  if(size == 0){
    std::cout << 0<<'\n';
    return;
  }
  std::cout << hip[1] << '\n';
  hip[1] = hip[size];
  hip[size] = 0;
  size--;//0에서 마이너스되는걸 생각못했네.. 이렇게뭐 넣을땐 음수되면 클나지않ㅇ르까생각해
  //이와 같은 전역 변수(처럼 ㅆ는친구들) 이상한 값으로 빠지거나, 제때 초기화 안하는 것 조심하기.


  int i= 1;

  while(i*2 <= size) {
    int left = i*2;
    int right = i*2 +1;
    int minposition = 0;
    if(size < right){ 
      minposition = left;
    } else if(hip[left]<=hip[right]) {
      minposition = left;
    } else {
      minposition = right;
    }
    //인덱스를 오버하는 경우를 제하면서, 어떻게 left, right 자식 선택하는것을
    //짤 것인가??

    if(hip[minposition] <hip[i]){//다운 힙은 '힙성질이 만족될때까지'
      std::swap(hip[minposition],hip[i]);
    }else {
      break;
    }
    i = minposition;//마지막에 i 갱신 안해줬다.
  }
}

void insert(int num) {
  size++;
  int i= size;
  hip[size] = num;

  while(i != 1) {
    int pos = i/2;

    if(hip[pos]<=hip[i]){
      break;
    }

    std::swap(hip[i],hip[pos]);
    i = pos;
  
  }
}

int main() {
  std::ios_base :: sync_with_stdio(false);
  std::cin.tie(NULL); 
  std::cout.tie(NULL);

  int command;
  std::cin >>command;

  for(int i = 0; i< 100000; i++) {
    hip[i] = 0;
  }
  for(int i = 0; i< command; i++){
    int temp;
    std::cin >> temp;

    if(temp != 0){
      insert(temp);
    } else {
      deletemin();
    }

  }
}