//제로 베이스드,
//더이상 이동해도 먼지를 치울 수 없다면 멈춘다.
//먼지가 있다면 제거하고 제거할 활동(A를 이용)
//없다면 역시 그대로 (B를 이용)
//배열 탈출 시 종료. 이는 쉽다.
//더 이상 진행해도 치울수 없다면 종료.
//답은 가장 최근에 치웠던 턴수.(cleanedturn)
//더 이상 진행해도 의미가 없다 == 사이클이 생겼다. 단, 해당 사이클 진행시 모두 청소한 곳이어야.
//왜냐하면 아직 청소 하지 않았다면, 다음 사이클에서 다른 곳으로 샐수 있다.
//청소여부 알아야함 + 이미 청소한 곳을 밟았다면 이는 기록해야함. (또 같은 곳, 같은 방향시 종료 = 3차원 배열)

//예측 : 쌩 구현 문제
//실제 : 구현, 시뮬레이션(빡구현이란 뜻이라함) 문제
//이를 강화한 hard문제는 1024x1024입력도 허용함. 여러 최적화를 해야하나봄.


/*
다른 사람 풀이와의 차이점 
1. 나는 방향정보 저장을 위해 별도로 visitedturn을 만들었지만, 이 역시 배열의 하나의 차원으로 둔다.(방향 4개 = 4차원) 즉 3차원 visited 배열을 이용한다. => 배열의 방문과 추가적인 정보는 하나의 배열로서 저장하도록하자.
2. 이미 청소한 곳을 또 다시, 같은 방향 방문시 의미 없는 사이클 생성 > 멈춤. 그러나 중간에 청소할 곳이 있다면, 다시 그자리로 간다해도 다른 경로로 갈 가능성이 생김 > 기록이 의미가 없어짐. 나의 경우는 이를 막기 위해서
마지막 청소 기록에 재방문에 또다시 재방문 까지 기록해가며 복잡함. >> 여기서는 의미가 없다면 그냥 방문 기록을 날려버림. 이게 훨씬 편했다. 의미가 없다면 단순히 방문한다고 그를 기록할 필요는 없다.
3. 구현일까? 특수한 방법이 있을까? > 입력의 수가 적은 것이므로 구현임을 판단함. (마치 브루트 포스 판단하듯이)
4. row ,column, direction은 주로 r, c, d의 약어로 쓴다.
5. 빠른 입출력을 위한 코드가 있었다.
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
*/

/*
실수 : 처음에 배열 값 초기화하는 거 조심. 잘못 초기화해서 이상한데서 끝나 버릴수가 있다.
*/



#include <iostream>
#include <string>


/*
int H;
int W;

int arisX;
int arisY;
int arisdirection;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int visitedturn[64][64];
int visiteddirection[64][64];
int ruleone[64][64];
int ruletwo[64][64];
int turn = 0;
int cleanedturn;

void visit(int x, int y, int direction);

void clean(int x,int y,int direction){
  if(visitedturn[x][y] > cleanedturn && direction == visiteddirection[x][y]) {
    return;
  }
  
  visitedturn[x][y] = turn;
  visiteddirection[x][y] = direction;

  int newdirection = (direction + ruletwo[x][y])%4;
  int newx = x + dx[newdirection];
  int newy = y + dy[newdirection];

  if(newx >= 0 && newx < H && newy >=0 && newy < W)
  visit(newx,newy, newdirection);
  */

  /*
  if(newx < 0 || newx >= H || newy <0 || newy>= W)
  return;
  
  visit(newx,newy, newdirection);
  수정전, 같은거 아냐??...
  */ 
/*
}
void dirty(int x, int y, int direction) {
  visitedturn[x][y] = turn;
  cleanedturn = turn;
  int newdirection = (direction + ruleone[x][y])%4;
  int newx = x + dx[newdirection];
  int newy = y + dy[newdirection];

  if(newx >= 0 && newx < H && newy >=0 && newy < W)
  visit(newx,newy, newdirection);
}

void visit(int x, int y, int direction) {
  turn++;

  if(visitedturn[x][y] == 0) {
    dirty(x,y,direction);
  }
  else{
    clean(x,y,direction);
  }
}

int main() {
  std::cin >> H >> W;
  std::cin >> arisX >> arisY >> arisdirection;

  for(int i = 0; i< H; i++){
    std::string temp;
    std::cin >>temp;
    for(int j = 0; j< W; j++){
      char t = temp.at(j) -48; 
      ruleone[i][j] = (int)t;
    }
  }

  for(int i = 0; i< H; i++){
    std::string temp;
    std::cin >>temp;
    for(int j = 0; j< W; j++){
      char t = temp.at(j) -48; 
      ruletwo[i][j] = (int)t;
    }
  }

  visit(arisX, arisY, arisdirection);

  std::cout << cleanedturn;
}
*/

int H;
int W;

int arisX;
int arisY;
int arisdirection;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int visited[64][64][4];//처음에 어쩔수 없이 0초기화 됨.
int dust[64][64];
int ruleone[64][64];
int ruletwo[64][64];
int cleanedturn = -1;//처음에 0으로둠
int turn = 0;

void clean(int x,int y,int direction){
  turn++;
  
  if(visited[x][y][direction] == cleanedturn) {//그래서 첫턴에 오류남. 이런;;
    return;
  }

  int newdirection;


  if(dust[x][y] == 0){
    dust[x][y] =1;
    cleanedturn = turn;

    newdirection = (direction + ruleone[x][y])%4;
  } else {
    visited[x][y][direction] = cleanedturn; // 먼지가 있는경우 저 커다란 배열 초기화 하는걸 막기 위해서 최근에 청소를한 턴 값으로 해당 위치 저장 이러면 구분 가능하다. 

    newdirection = (direction + ruletwo[x][y])%4;
  }


  int newx = x + dx[newdirection];
  int newy = y + dy[newdirection];

  if(newx < 0 || newx >= H || newy <0 || newy >= W)
  return;

  clean(newx,newy, newdirection);
}

int main() {
  for(int i = 0; i< 64; i++){
    for(int j = 0; j< 64; j++) {
      dust[i][j] = 0;
    }
  }
  std::cin >> H >> W;
  std::cin >> arisX >> arisY >> arisdirection;

  for(int i = 0; i< H; i++){
    std::string temp;
    std::cin >>temp;
    for(int j = 0; j< W; j++){
      char t = temp.at(j) -48; 
      ruleone[i][j] = (int)t;
    }
  }

  for(int i = 0; i< H; i++){
    std::string temp;
    std::cin >>temp;
    for(int j = 0; j< W; j++){
      char t = temp.at(j) -48; 
      ruletwo[i][j] = (int)t;
    }
  }

  clean(arisX, arisY, arisdirection);

  std::cout << cleanedturn;
}



