// 조합을 이용해 브루트 포스로 풀기 > 불가능.
// 아무리봐도 생각이 안나서 보니 dp, 가방 문제

//문제 : n명중 k명 골라서 힘과 스피드 수치 합의 곱이 최대. 
//dp[i,k] -> n명 중 i 번째까지 고려했을때, 선택한 놈은 k명이며 a함*b합의 최대값.
//이러면 답은 dp[n,k] -> n명모두 고려해봤을때 k명이 선택되었고 ()가 최대.
//recurrence relation -> dp[n, k]이 되기위해서는 n번째 고려에서 선택하지 않거나(똑같이 k 명)
//이는 dp[n-1,k]. 혹은 n번째 선택에서 데리고 온다 (dp[j,k-1] + 수치값.)(단 j는 n보다 작다)이다. 이때 더하기 전값이 맥스라고
//그다음도 맥스는 아니다. 따라서 max(dp[m-1,k],(max(dp[j,k-1]+ 수치값.)))
//dependency는 좌상단. 배열 접근을 줄이기 위해서 column first.
//베이스케이스 = dp[0,0] = 0
//각칸마다 저장하는 것은 곱해진 값이되면 안될 거다. 

//곱하기는 기존에는 곱값이 작더라도, 오히려 어떤 값을 더하냐에 따라서는 기존에 작았던거 + 값 이 기존에 큰거 + 값이 될 수도 있겠지!
//따라서 내가하는 방식으로 하면 혹시 정답일 수 있는 후보를 모두 저장하지 못해 별로다.
//특정 위치까지의 최적(subproblem)의 조합으로 실제 최적을 조합해내지 못했다!

//이로서 알게 된 것 >> 답의 후보가 될 수 있는 것은, 모두 저장할 필요가 있다. 

//일단 타인 풀이를 이용해 최적화 가능한 것 > 속도 혹은 힘. 왜냐면 합이 정해져 있기 때문이다. 
//따라서 스탯 하나로 식도 정리 가능하다.
//답의 후보를 모두 저장할 필요가 있다했다. 변수가 하나로 줄면서 답의 후보가 더 명확해졌다. (사실 핵심은 한사람당 스텟 제한이 있다는 것이긴 하지만)
//0 ~ k*스텟제한 이다. 이 등장여부를 모조리 저장, 만들 수있는 경우의 수중 식에 대입시 가장 커지는 놈을 답으로 하면된다.
//dp[i,k,p] = i명 까지 체크 했을때, 특정스텟의 합이 p인 경우가 존재 했는가?
//그러면 답은 dp[N,k,p] == 1 인 것중 대입했을때 가장 값이 큰 것일 것이다.
//recurrence relation > 일단 무조건 N-1에서 (N번째물건 넣을지 말지 고민중) , 인원을 더넣지않아도 일단 스텟 합이 이에 해당하는 경우 = dp[N-1,k,p], 해당 인원을 넣어서 해당 스텟합이 될 수 있는 경우
//dp[N-1, k-1, p- 더하는 사람의 해당 스텟]
//dependency > N-1이 필요하니까 row쪽 상단, k-1인경우도 고려해야하니 col쪽 왼쪽 이들은 z축 모두 완료 되어있어야함. 따라서 row 위한칸, col 왼 한칸, 진행은 z축 우선 > col우선 > row우선.
//베이스 케이스 > 아직 아무도 고려 안한 경우 dp[0, : ,0] = true. 현재는 speed 스텟합이 무조건 0. 0명이니까! dp[:,0,0] = true, 그어떤 인원도 넣지 않은 몰상식한 행위.. 일단 합은 0!
/*
#include <iostream>
#include <vector>
#include <tuple>

typedef std::tuple<int, int> stat;

int n;
int k;
int sum;//어따 쓰는 거야;;
std::vector<stat> v;
stat dp[81][81];

int main() {
  std::cin >> n >> k >> sum;
  for(int i = 0; i<n; i++){
    int temp1,temp2;
    std::cin >>temp1 >> temp2; 
    v.push_back(std::make_tuple(temp1,temp2));
  }

  dp[0][0] = std::make_tuple(0,0);

  for(int i = 1; i<= n; i++) {
    int speed, power;
    std::tie(speed,power) = v.at(i-1);
    for(int j = 1; j<= i; j++) {
      int maxspeed = 0;
      int maxpower = 0;
      int thisspeed,thispower;
      for(int z = 0; z < i; z++) {
        
        std::tie(thisspeed,thispower) = dp[z][j-1];
        if((thisspeed+speed) * (thispower+power) > maxspeed*maxpower)
        {
          maxspeed = thisspeed + speed;
          maxpower = thispower + power;
        }
      }

      std::tie(thisspeed,thispower) = dp[i-1][j];
      if(thisspeed * thispower > maxspeed * maxpower){
        maxspeed = thisspeed;
        maxpower = thispower;
      }

      dp[i][j] = std::make_tuple(maxspeed, maxpower);

    }
  }
  int res1, res2;
  std::tie(res1,res2) = dp[n][k];
  std::cout << res1*res2;
}
*/

#include <iostream>
#include <vector>
#include <tuple>

int n;
int k;
int sum;
std::vector<int> v;
bool dp[81][81][16001];

int main() {

  for(int i = 0; i<= 80; i++) {
    for(int j = 0; j<= 80; j++) {
      for(int z = 0; z<= 16000; z++) {
        dp[i][j][z] = false;
      }
    }
  }

  std::cin >> n >> k >> sum;
  for(int i = 0; i<n; i++){
    int temp1,temp2;
    std::cin >>temp1 >> temp2; 
    v.push_back(temp1);
  }
  int limit = sum * k;

  for(int i = 0; i<= n; i++) {
    dp[i][0][0] = true;
  }
  //내가 처음에 0일때의 케이스는 문제 없도록 베이스케이스를 설정,
  //뒤에 안 그렇게 됨. 그게 문제였었다.
  for(int r = 1; r <= n; r++) { //r: 모든 인원 n 에 대해서 차례로 확인
    int speed = v.at(r-1);
    for(int c = 1; c<=k; c++) { //c: 현재 강도 파티원의 인원이 c인 경우
      //bool isreal  원래 여기있었다. 그러나 이를 후에 갱신 안해줘, 한번 true되면 열 전체가 true되는 불상사 발생.
      for(int z = 0; z <= c* sum ; z++) {//가능한 모든 수치값에 대하여 존재 가능 여부를 확인.
        bool isreal = false;
        if(z-speed >=0&& dp[r-1][c-1][z-speed] == true){
          isreal = true;
        }
        if(dp[r-1][c][z] == true)
        isreal = true;

        dp[r][c][z] = isreal;
      }
    }
  }

  
  int max = 0;

  for(int i = 0; i<= limit ; i++) {
    if(dp[n][k][i] == false)
    continue;

    int speed = i;
    int strength = limit-speed;
    if (max < speed*strength)
    max = speed*strength;
  }
  
  std::cout << max;

}