//트리를 어떻게 구현해야할까?

#include <iostream>
#include <array>

std::array<int,26> left;
std::array<int,26> right;
int root = 0;
int N;

void preorder(int i) {

  std::cout << (char)(i+65);
  if(left.at(i) >= 0)
  preorder(left.at(i));

  if(right.at(i) >= 0)
  preorder(right.at(i));
  

}

void inorder(int i) {
  if(left.at(i) >= 0)
  inorder(left.at(i));

  std::cout << (char)(i+65);
  
  if(right.at(i) >= 0)
  inorder(right.at(i));
}

void postorder(int i) {


  if(left.at(i) >= 0)
  postorder(left.at(i));
  
  if(right.at(i) >= 0)
  postorder(right.at(i));

  std::cout << (char)(i+65);

}



int main() {

  for(int i = 0 ; i< 26; i++ ){
    left[i] = -1;
    right[i] = -1;
  }
  std::cin >> N;
  
  for(int i = 0; i< N; i++) {
    char first;
    char second;
    char third;
    int parent;
    int child1;
    int child2;

    std::cin >> first >> second >> third;

    parent = first -65;
    child1 = second -65;
    child2 = third -65;
    /*
    if(child1 >= 0){
      left.at(parent) = child1;
    }
    else{
      left.at(parent) = -1;//없는걸 표시한다고 자식까지 표시되는게아니었음. 우리는 패런트 에 대해서만 초기화하니까.
    }
      수정전
    */ 

    if(child1 >= 0){
      left.at(parent) = child1;
    }

    if(child2 >= 0){
      right.at(parent) = child2;
    }
  }
  preorder(0);
  std::cout <<'\n';
  inorder(0);
  std::cout <<'\n';
  postorder(0);
}


//생겼던 이슈들
//1. int로 cin으로 문자를 받으면 아스키 코드 값으로 안받아진다.
//2. 착각해서 배열에서 초기화 되지 않은 부분에 접근했다.