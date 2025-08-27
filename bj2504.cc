//올바른 괄호열 (렉싱을 통과하는 단어) > 
// E-> (), E -> [], E-> [N], E -> (N), E -> EE
// N -> NN, N-> 0,1,....
// 특정행동이 이전에 되었을지, 지금도 해야할지 햇갈리다.
//[N]라면 ]앞에 다른거나오면 다 안될것.
//문제 잘못 읽음 !!!N은 숫자 아님.
// E-> (), E -> [], E-> [E], E -> (E), E -> EE
//시멘틱스 -> (는 같은 깊이의 )를 찾는다.그 사이 내부에 있는 값 계산 후(없을시 0)에 2를 곱한다.
//식은 (,[ 에 대응되는 같은 깊이의 ), ] 가 나온다면 그를 계산한다. 그리고 그를 더한다.
//[는 같은 깊이의 내부에 있는 값을 계산후(없을시 0)에 3을 곱한다.
//두 식의 연속은 그 두 값을 합한다.
//컨크리트랑 업스트랙 차이가 뭐더라..

//시멘틱스 구현이 어려웠다. 이게 정석이 아닌것 같긴함 ㅋㅋ;;
//이론 개념 다시 보면 좋을것 같긴해.
//3시간

#include <iostream>
#include <deque>
#include <string>

int test(std::deque<char>& q, char i){
  switch(i) {
    case ')':
      while(!q.empty()){
        char temp = q.back();
        q.pop_back();
        if(temp == 'E') {
        } else if(temp == '('){
          test(q, 'E');
          return 0;
        } else {
          return -1;
        }
      }
      return -1;
      break;
    
    case ']':
      while(!q.empty()){
        char temp = q.back();
        q.pop_back();
        if(temp == 'E') {
        } else if(temp == '['){
          test(q, 'E');
          return 0;
        } else {
          return -1;
        }
      }
      return -1;
      break;

    case 'E'://N이 여러 경우 재귀로 생각했다. 그러나 이미 그경우라면 앞에서 처리.
      if(!q.empty() && q.back() == 'E')
      return 0;
      q.push_back('E');
      return 0;
      
    
    default://여기 까먹었음. ( 같은게 처리 안됐음.
      q.push_back(i);
      return 0;
      break;
  }
  return -1;
}


int calc(char type, std::string& s,int start, int end) {
  switch(type){
    case 'E':{
      //무조건 단어일게보장되니 하나만 들어있는 경우 이런거 생각할 필요 없음.
      int deep = 1;
      for(int i = start+1; i<end; i++){
        if(s.at(i) == s.at(start)){
          deep++;
        }else if((s.at(start)+1 == s.at(i) ||s.at(start)+2 == s.at(i)) &&deep == 1){
          int a = calc(s.at(start), s, start, i+1);
          int b;
          if(i+1 == end){
            b = 0;
          }else{
            b = calc('E', s, i+1, end);
          }
          return a+b;
        }else if(s.at(start)+1 == s.at(i) ||s.at(start)+2 == s.at(i)){
          deep--;
        }
      }
      break;
    }
    case '(':{
      return 2*calc('E', s, start+1, end -1);
      break;
    }
    case '[':{
      return 3*calc('E', s, start+1, end -1);
      break;
    }
  }
  return 1;
}

int main() {
  std::string s; 
  std::cin >> s;
  std::deque<char> q;

  for(char i : s) {
    int temp = test(q, i);
    if(temp == -1) {
      std::cout << 0;
      return 0;
    }
  }

  if(!(q.size() == 1 && q.front() == 'E')){
    std::cout << 0;
    return 0;
  }

  std::cout << calc('E',s,0,s.size());
}