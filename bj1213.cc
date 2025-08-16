//팰린드롬 만들어야함, 사전 순 정렬 되어야함. 입력은 무조건 대문자 영어.
//일단 받기, A~Z 까지 각 숫자를 카운팅. 숫자 /2 한만큼 붙이기.
//한번이라도 홀수가 되면 어떤 불 변수를 트루로 하기.
//두번 트루 되면 sorry.
//작성15분 + 디버깅 22분 = 37분

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s;

  std::cin >> s;

  std::string front("");
  int isout = -1;
  for(int i = 65; i<= 90; i++ ){//ㅅㅂ 아스키 90을 안쳤었구나
    int count = 0;
    for(int j = 0; j< s.size(); j++) {
      if(s.at(j) == i)
      count++;
    }
    if(count%2 == 1&& isout != -1){
      std::cout << "I'm Sorry Hansoo";
      return 0;
    }else if (count%2 == 1) {
      isout = i;
    }
    
    for(int k = 0; k<count/2; k++ )//원래 else 조건이라 틀림
      front += (char)i;
    
    

  }


  std::string newstring(front);
    if(isout != -1){
    front += (char)isout;
  }//원래는 이거후 복사. 그러면 안돼징

  for(int i = newstring.size()-1; i>= 0; i--){//처음에 i를 newstring이 아니라 front로 둠.
    front+= newstring[i];
  }

  std::cout << front;
}
//특정의 이름, 혹은 값이 변경될때, 이로 인한 영향 조심 꼭하자...
//건물에 비유해보자. 건물에 기둥을 잘못 설치해서 다른 재질로 바꿨다면 잘못 설치한것에 맞춘 모든 것도 한번 테스트 해봐야지.
//만약 하중을 견딜수 없다면 그대로 무너질거야.