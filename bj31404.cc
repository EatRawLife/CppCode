//제로 베이스드,
//단순 구현문제, 더이상 이동해도 먼지를 치울 수 없다면 멈춘다.
//일단 규칙대로 이동한다, 청소를 한 턴을 기록한다.
//이미 방문한 칸에, 같은 상태(같은 방향, 같은 청소표)인경우 종료,
//배열 탈출 시 종료.
//청소후 계획표를 참조한는 것은 아무런 문제가 없다.
//하지만 청소 없는 계획표 참조시는 곤란하다.
//기본 먼지제거 계획표(A)이다. 이는 문제가 없다. 턴 수를 적어두고, 현행 계획표
//해당 부분을 b로 업데이트 한다. 따라서 추가적인 일은 안한다.(청소를 했으므로 더이상 청소를 할게 없네를 걱정할 필요가 없다.)
//빈칸을 밟았을 경우에 위의 활동을 할 필요는 없지만, 혹시 이 이후로 해당칸을 같은 방향으로 밟는 다면 사이클이 생기게 될 것이다.
//계속 반복된다. 단 중간에 있는 블럭이 모두 b 계획표의 것이어야 할 것이다.
//그러면 계속 계획표를 업데이트 하면서
//칸을 밟아나간다.
//먼지가 있다면 visited 배열을 현재 턴수로 만들고 이를 룰 b것의 값으로 교체
//먼지가 없다면 visited 배열을 확인한다.
//핵심은 어떻게 뒤에 더이상 먼지가 있는 곳을 방문할 수 없는가를 확인 하는 것.
//차후에 방문 할 것이 모두 먼지가 없고, 원래 자리에 현재방향 그대로 돌아올 경우.
//처음은 간단하다. 단순히 청소기록이 생기면 앞에 하던것을 다 초기화 하는 것. 
//먼지가 있다면 이를 룰 b것의 값으로 교체, 방문 기록
//먼지 없는칸 방문시 visited1 0이면 visited1 배열을 현재 턴수로 만들고 visit2배열에 들어온 방향 기록. 
//0이 아니면 visit 배열 살펴서 턴수를 살핌. 마지막 청소 턴수 보다 뒤라면 해당 칸을 밟은 뒤에 
//한번도 청소를 한적이 없단뜻. 이상태에서 방문당시의 방향과 같다면..
//예측 : 쌩 구현 문제
//실제 : 구현, 시뮬레이션(빡구현이란 뜻이라함) 문제
//이를 강화한 hard문제는 1024x1024입력도 허용함. 여러 최적화를 해야하나봄.

/*
풀이 후 정리
핵심 > 앞으로 더 방문해도 더 청소할 곳이 없고, 같은 곳만 돈다는것을 확인하기.
이 사이클이 있다는 것을 확인하는 방법은??
이미 방문한 곳을 또 방문,
해당 지역을 방문했을때보다 청소한 시기가 더 과거일때 = 여기 방문후 청소한적 없음 = 이미 방문한곳만 방문
방향도 같음
이러면 전에 이곳을 마지막으로 방문했을때와 같은 대만 돌게 될 것. 
출력할 것은 단순하게 가장 마지막에 방문
*/

/*
다른 사람 풀이와의 차이점 
1. 나는 방향정보 저장을 위해 별도로 visitedturn을 만들었지만, 보통 이역시 배열의 하나의 차원으로 둔다.(방향 4개 = 4차원) 즉 3차원 visited 배열을 이용한다. => 배열의 방문과 추가적인 정보는 하나의 배열로서 저장하도록하자.
2. 의미없는 사이클 발견을 위해서 해야하는 것이 다르다. 방문한 타일을 다시 밟아도, 뒤에 있을 것이 확실히 방문 했음을 보장할 수 없다면 계속 방문해봐야한다. 이를 위해서 나는 cleanedturn과 배열에 저장된 값을 비교해서, 계속 빈곳을 지나왔는지 판단했다.
방문한것을 또 방문했다해도 이 뒤에 청소할 블럭을 밟으면 이 기록의 의미가 없어지므로 visited 기록 자체를 초기화한다. 나는 뭔가 자원을 많이 쓸것 같아 안했지만 이래도 되나보다.
3. 
4. 구현일까? 특수한 방법이 있을까? > 입력의 수가 적은 것이므로 구현임을 판단 가능하다.
5. row ,column, direction은 주로 r, c, d의 약어로 쓴다.
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

int visited[64][64][4];
int ruleone[64][64];
int ruletwo[64][64];
int cleanedturn = 0;
int turn = 0;
int resetcount = 1;

void clean(int x,int y,int direction){
  
  if(visited[x][y][direction] == resetcount) {
    return;
  }
  
  visited[x][y] = turn;
  visiteddirection[x][y] = direction;

  int newdirection = (direction + ruletwo[x][y])%4;
  int newx = x + dx[newdirection];
  int newy = y + dy[newdirection];

  if(newx < 0 || newx >= H || newy <0 || newy >= W)
  return;

  visit(newx,newy, newdirection);
  

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



