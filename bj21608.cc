//학생은 1 based, 자리배치는 0based N*N 행렬
//각 번호의 학생마다 좋아하는 번호를 저장한 배열(N+1*4)
//매 타임마다 lovestarray에서 한줄에 해당하는 것으로 N*N을 다 살핀다.(단 빈 곳)
//큐가 안비었다면 맨앞 살펴서 주변에 사람수 가장 많은 경우 큐에 push
//큐에 여러개라면 새 큐를 만들어서 주변 빈칸을 살펴서 새로 push.
//또 여러개라면 행> 열의 번호가 작은 칸으로 자리 정하기.
//특정 기준으로 정렬하는방법 알기 

//최대의 위치를 기억해야하는 경우 -> 그냥 이전처럼 3개변수 쓰자
//최대의 중복 여부를 판단하는 경우 -> 그냥 두번 순회해
//중복에 대한 처리조건이 주어지는 경우 -> 그냥 모든 세부조건도 고려하는 자료구조를 이용해서
//중복 상관없게 바로 정렬 때려 
//튜플 > 주변 좋아하는 학생 수, 주변 빈칸 수, 행번호 ,열번호

//해결 성공.
//의문 > 어떻게 복잡한 포문 구조를 간단히
//자바소트
#include<iostream>
#include<vector>
#include<deque>
#include<tuple>
#include<algorithm>
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int N;
int main(){
  int score = 0;
  std::cin >> N;
  int ski_list[N*N+1][4];
  std::deque<int> priority;
  int reallist[N][N];

  for(int i = 0; i< N; i++) {
    for(int j = 0 ;j<N; j++) {
      reallist[i][j] = 0;
    }
  }
  
  for(int i = 0; i< N*N; i++) {
    int who;
    std::cin >> who;

    std::cin >> ski_list[who][0]>> ski_list[who][1]>> ski_list[who][2]>> ski_list[who][3];
    priority.push_front(who);
  }

  for(int i = 0; i< N*N; i++) {
    int target = priority.back();
    priority.pop_back();

    std::vector<std::tuple<int,int,int,int>> place_info;

    for(int r = 0; r< N; r++) {
      for(int c = 0; c< N; c++ ) {
        if(reallist[r][c] != 0){
          continue;
        }
        int sscore = 0, empty = 0, hhh = 1;
        for(int near = 0; near <4; near++) {
          int newr,newc;
          newr = r+ dr[near];
          newc = c+ dc[near];
          if(newr>=0 && newr<N && newc >=0 &&newc<N) {
            if(reallist[newr][newc]== 0){
              empty++;
            } else {
              for(int k = 0 ; k<4; k++){
                if(ski_list[target][k] == reallist[newr][newc]){
                  sscore+= hhh;
                  hhh*=10;
                }
              }
            }
          }
        }
        place_info.push_back(std::make_tuple(sscore,empty,r,c));
      }
    }
    sort(place_info.begin(),place_info.end(),
    [](std::tuple<int,int,int,int> a,std::tuple<int,int,int,int> b) {
      if(std::get<0>(a) != std::get<0>(b)) return std::get<0>(a) > std::get<0>(b);
      if(std::get<1>(a) != std::get<1>(b)) return std::get<1>(a) > std::get<1>(b);
      if(std::get<2>(a) != std::get<2>(b)) return std::get<2>(a) < std::get<2>(b);
      return std::get<3>(a) < std::get<3>(b);
    });
    reallist[std::get<2>(place_info.front())][std::get<3>(place_info.front())] = target;
  }
  //스코어는 다시 구해야지. 다 배치되고점수가 플러스 될테니.(만약 로직 다시 봤다면 대참사)
  for(int i = 0 ; i< N ; i++) {
    for(int j = 0; j< N; j++) {
      int value = reallist[i][j];
      int hhh = 0;
      for(int near = 0; near <4; near++) {
        int newr,newc;
        newr = i + dr[near];
        newc = j + dc[near];
        for(int wishnum = 0; wishnum < 4; wishnum++){
          if(newr>=0 && newr<N && newc >=0 &&newc<N&& ski_list[value][wishnum] == reallist[newr][newc]) {
            hhh+=1;
            break;
          }
          //문제 제대로 안읽었다.
        }
      }
      if(hhh != 0) {
        int temp = 1;
        for(int wow = 2; wow <= hhh; wow ++){
          temp*= 10;
        }
        score += temp;
      }
    }
  }
  std::cout << score;
}



