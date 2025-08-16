//최대50*50의 도시.(2500)
//최대 13개까지 남기기. 
//일단 생조합으로 계산은 절대 불가능.
//집은 최대 2N개, 치킨집은 최대 13개.
//13C6은 1500정도.(모든 치킨집 조합마다)
//특정 치킨집만 남겼을때 거리를 측정하는 방식으로
//각 집마다 각 치킨집과의 거리를 측정하여 최소를 더함 -> 13N
//1500* 13N제곱
//0based.
//0-> 빔, 1 -> 집, 2-> 치킨집
//치킨 거리가 최소가 되도록 치킨집 M개만 남겨라. 그때 치킨 거리를 구하라.
//치킨 거리는 집에서 임의의 치킨집과의 거리.
//입력을 받으면서 모든 치킨집의 좌표를 카운트.
//백트래킹을 통해 모든 가능한 조합을 특정 큐에 뒤부터 삽입.(이때 좌표를 하나하나 말고, 인덱스로 치킨집 배열에 접근)
//하나씩 빼가지고 해당 치킨집들과의 거리를 측정, 작다면 이걸로.
//마지막 된거 출력.
//구상 : 45분
//중복 케이스가 없어야 -> 어디까지 햇는가 기억해야
//특정 개수가 되면 그만해야 
//종료조건 -> 가게가 필요수만큼 모이거나, 이 이상 가게가 없다.
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>

std::vector<std::tuple<int,int>> chickenlist;
std::vector<int> li(13);  
int max = 100 * 2500;
bool houses[50][50];
  int N, M;

void dfs(int start, int count) {
  int sumlength = 0;
  if(count == M){
    for(int i = 0; i< N; i++) {
      for(int j = 0; j<N; j++) {
        if(houses[i][j] == 1){
          int length = 100;
          for(int z = 0; z<M; z++) {
            int x, y;
            std::tie(x,y) = chickenlist[li[z]];
            int templength = abs(i-x) + abs(j-y);
            if(templength < length)
            length = templength;
          }
          sumlength+= length;
        }
      }
    }
    if(sumlength < max){
      max = sumlength;
    }
  }

  for(int i = start; i< chickenlist.size(); i++) {
    li[count] = i;
    dfs(i+1,count+1); //구현시에 실수좀 했음.
  }

}

int main() {

  std::cin >> N >> M;

  for(int i = 0; i< N; i++) {
    for(int j = 0; j< N; j++) {
      int temp;
      std::cin >> temp;

      if(temp == 1){
        houses[i][j] = true; 
      } else if (temp == 2) {
        chickenlist.push_back(std::make_tuple(i,j));
      } else{ }
    }
  }

  dfs(0,0);

  std::cout << max;

}


