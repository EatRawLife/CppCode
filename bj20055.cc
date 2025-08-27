//1번이 올리는 위치, N이 내리는 위치(도달시 바로내림.)., 1~2N개, 2N=> 1, N=> N+1
//로봇은 올리는 , 내리는 위치에서만 오르내릴 수 있다.(1 오름, N 내림)
//로봇은 벨트위 이동가능, 로봇이 올라가거나 이동한 발판 내구도 1감소
//1.벨트 회전(로봇포함) -> 2.올라간 로봇 순서대로 벨트회전방향 한칸 이동. 이동하려는칸
//이동할 곳 로봇 x, 내구도 1이상. -> 3.올리는 위치에서 내구도0아니면 로봇 올리기.
//->4.내구도 검사, K 이상의 고장발판시 종료.
//몇턴이 아닌 몇번 단계 진행중에 끝났는지.
//컨베길이(벨트 2N), 내구도 0 K개 이상(종료조건), 각칸 내구도
// N,K,A. 고장발판 개수 저장, 배열(내구도 저장), 배열 (로봇 여부 저장)

//정직하게 지시대로 구현하는 문제.

#include<iostream>
#include<deque>

int N,K;
int broken = 0;
int steps = 0;
std::deque<int> duraq1, duraq2;

void stepone(std::deque<bool>& roboq1){
  int step1, step2;
  step1 = duraq1.back();
  duraq1.pop_back();
  step2 = duraq2.back();
  duraq2.pop_back();
  duraq1.push_front(step2);
  duraq2.push_front(step1);

  roboq1.pop_back();
  roboq1.push_front(false);

  roboq1[N-1] = false;//로봇 내림
}
//컨베이너는 1부터, 나는 0부터 N-1 *2다
void steptwo(std::deque<bool>& roboq1){
  for(int i = N-2; i>=0; i--) {
    if(roboq1[i] && !roboq1[i+1] && duraq1[i+1] >= 1){//i+1인것들을 i라해서 첨에 오류좀 많이남.
      roboq1[i+1] = true;
      roboq1[i] = false;
      duraq1[i+1]--;
    }
  }
  roboq1[N-1] = false;
}
void stepthree(std::deque<bool>& roboq1){
  if(duraq1[0]>0){
    duraq1[0]--;
    roboq1[0] = true;
  }
}

int main() {
  std::cin >> N >> K;
  std::deque<bool> roboq1(N, false);//N과 false를 거꾸로해서 런타임 에러가 계속 났다
  //세그 폴트만 뜨는 개 쓰레기 언어

  for(int i = 0; i< N; i++){
    int temp;
    std::cin >> temp;
    duraq1.push_back(temp);
  }
  for(int i = 0; i< N; i++){
    int temp;
    std::cin >> temp;
    duraq2.push_back(temp);
  }

  while(true){
    steps++;
    stepone(roboq1);
    
    steptwo(roboq1);
    
    stepthree(roboq1);
    
    int k = 0;
    for(int i = 0; i<N; i++){
      if(duraq1[i] == 0 )
      k++;
      if(duraq2[i] == 0)
      k++;
    }
    if(k >= K){
      std::cout <<steps;
      return 0;
    }
  }
}