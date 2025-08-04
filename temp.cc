#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

int N;
int M;

std::ostringstream str;

std::vector<int> nlist;
std::vector<int> com;

void call(int size){

  if(size == M){//push_back 안씀 > 미리 사이즈는 정해진 상태일것. 따라서 size()가 아닌 size를 따로 저장.
    for (int i : com) {
      str << i << ' ';
    }
    str << '\n';
    return;
  } 

  for(int i = 0; i< N; i++){
    if(i >=1 && nlist.at(i) == nlist.at(i-1)) continue;
    if(size >= 1&& com.at(size-1) > nlist.at(i)) continue; //항상 오름차순 같은 조건이 란 조건이없을 경우도 있어
    //그런 경우와도 통일성을 위해 그냥 시작 인덱스 인수는 날려버렸다.
    
    com[size] = nlist.at(i);//여기서 괄호안에 뭐가 들어갈지 제대로 못떠올리고 집중안해서 계속 틀렸었음.
    call(size+1);
  }
    
}

int main(){
    std::cin >> N >> M;

    for(int i = 0; i< N; i++) {
        int temp;
        std::cin >> temp;
        nlist.push_back(temp);
    }
    nlist.resize(N); //이거 관련도 볼것. GPT 를 참고하니 크기를 0인상태로 배열처럼 [] 사용하면 기존이 가변 길이라서 0인 상태에서 확인없이 다음 접근 > 좆됌.
    com.resize(M);

    sort(nlist.begin(), nlist.end());

    call(0);

    std::cout << str.str() << std::flush;
}