//두가지 방법이 있을것 같다.
//가능한 테트로 미노를 모든 위치마다해보는 방법
//근데 이건 실수도 많을 것 같고. 구현 복잡해보임.
//아 그렇다고 깊이 탐색으로 하는 건 내수준 불가능으로 보임.
//탐색하는 그쪽말고 반대쪽으로도 탐색이 가능해야하니..
//일단 모양대로 해보자.
//탐색위치에서 블록 잡는 곳은 항상 좌측 위쪽이다.
//i블록은 2가지, o블록은 한가지, l이 8가지, z가 네가지 t가 네가지.
//인데 그냥 중복이라도 다 해보면 될듯. 귀찮잖아.
//대칭 이동 > rw를 싹 교체
//90도 돌리기
//차례로 +r -> -c -> -r -> +c
//       +c -> +r -> -c -> -r
//따라서 차례로 (r,c), (c,-r), (-r,-c),(-c,r)
//대칭 뒤집기 (r,-c)
//c만 뒤집기.
//그럼 테트로미노는 어떻게 표기할 것인가?
//원점을 기준으로 플러스 몇인지로 표기하자.
//단 원점은 항상 포함이니 빼자.
//t기준 생각시 (ㅗ 모양)
//(0,-1,0),(1,1,2)
//돌리면 (1,1,2) (0,1,0)
//단 벽 넘는게 하나라도 존재시 제외.
//모든 블럭을 순회한다.
//각 블럭마다 위의 8*5 케이스를 모두 확인
//최대값을 비짓에 저장.

//아이디어가 좋지 못했다. 내가 배열을 사용한다고 했을때 생기는 문제를 전혀 예상치않고 알고리즘만 짰다.
//어떻게 다시 구현을 해볼까.
//시작할 블럭 잡기는 easy > i,j로 위치 잡기.
//블럭 선택은? 자기자신 위치 + 3개 블럭의 상대적 x,y위치의 배열. 튜플로 저장된거 들고오기.
//회전 및 돌리기는 해당 값에 하나씩 곱하기.
//구현 아이디어 구상 44분+ 구현 1시간 + 디버깅 120분 > 3시간

//풀이를 보니 대부분 나처럼 dfs를 떠올렸다. 그러나 ㅗ를 고려 못하는 문제가 발생. >> 그냥 ㅗ는 따로 고려.
//나는 그나마 테트리스를 해봤다보니 대칭 + 돌리기면 다 할 수 있다는걸 알아서 그나마 반복문으로했다.
//근데 이걸 모든 케이스 일일히 살피는 미친놈도 있더라. (어떻게 안햇갈리고 한거냐?...)
//내가 할것은 >  더 간단하고 이해하기 쉽게 구현하기(소수의 반복이 오히려 변수의 설정등을 더 햇갈리게 만듬.) 
//,dfs를 이용해서 풀어보기

//실수는 또 구현한것을 별생각없이 바꾸다 발생. 이미 구현한 것을 바꾼다를 특히 조심 할 것.

#include <iostream>
#include <tuple>

std::tuple<int,int,int> rows[5] = {std::make_tuple(0,0,0), std::make_tuple(0,1,1), std::make_tuple(0,1,1), std::make_tuple(1,2,2), std::make_tuple(0,-1,0)};//i,o,z,l,t
std::tuple<int,int,int> cols[5] = {std::make_tuple(1,2,3), std::make_tuple(1,0,1), std::make_tuple(1,1,2), std::make_tuple(0,0,1), std::make_tuple(1,1,2)};//i,o,z,l,t
int rotater[4] = {-1,-1,-1,-1};
int rotatec[4] = {1,1,1,1};

int main(){
  int N;//행크기
  int M;//열크기
  int matrix[500][500];
  int visit[500][500];

  std::cin >>N >> M;
  for(int i = 0; i<N; i++){
    for(int j = 0; j<M; j++) {
      std::cin >>matrix[i][j];
    }
  }
  for(int i = 0; i<N; i++){
    for(int j = 0; j<M; j++) {
      visit[i][j] = 0;
    }
  }

  for(int i = 0; i< N; i++) {
    for(int j = 0; j<M; j++) {
      for(int z = 0; z<5; z++){
        int b1r,b2r,b3r, b1c,b2c,b3c;
        std::tie(b1r,b2r,b3r) = rows[z];
        std::tie(b1c,b2c,b3c) = cols[z];
          for(int rotate = 0; rotate<8; rotate++){
            if(rotate==4){
              b1c = -b1c;
              b2c = -b2c;
              b3c = -b3c;
            }//대칭된경우
            //주요 변화 > rotate가 8로 늘어남.
            int sum = matrix[i][j];//기존 위치
            int dx = rotater[rotate%4], dy = rotatec[rotate%4];

            int xs[3] = {-b1c, -b2c, -b3c};
            int ys[3] = {b1r, b2r, b3r}; // 기존에 둔 rotaterc를 이걸로 교체하는 과정에서 -를 붙임. 나의 실수. 이처럼 새로 교체는 신경써야할 것.
            b1r = xs[0], b2r = xs[1], b3r = xs[2];
            b1c = ys[0], b2c = ys[1], b3c = ys[2];

            bool out = false;
            for(int k = 0; k< 3; k++){
              if(xs[k]+i<0|| xs[k]+i>=N || ys[k]+j<0 ||ys[k]+j>=M){
                out = true;
                continue;
              }
              sum+= matrix[i+xs[k]][j+ys[k]];
            }
            if(sum > visit[i][j]&& out != true){
              visit[i][j] = sum;
            }
          }
        }
        //추가로 스왑 하거나 안하거나
        //돌리기 4번
      }
    
  }

  int max = 0;
  for(int i = 0; i< N; i++){
    for(int j = 0; j<M; j++){
      if(visit[i][j] > max){
        max = visit[i][j];
        
      }
      std::cout << visit[i][j]<< ' ';
    }
          std::cout << '\n';
  }

  std::cout << max;

}

