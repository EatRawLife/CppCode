//비는 r0에서내려서 아래로 쌓인다.
//maxr은 항상 막혀 있다.
//H,W는 최대 500, 전체 확인시 25만번.
//물이 고인칸 = 비어있음, 좌우 어딘가에 블럭이 있음.
//물이 없는 칸 = 차있거나, 비었다 하더라도, 좌측, 우측에 빈킨이 있음.
//구현 15분, 디버깅 45분;; = 1시간

#include <iostream>

int main() {
  int r,c;
  int sum = 0;
  std::cin >> r >> c;

  bool array[r][c];

  for(int j = 0; j < c; j++) {
    int soil;
    std::cin >> soil;

    for(int i = 0; i< r-soil; i++){
      array[i][j] = false;
    }
    for(int i = r-soil; i<r; i++) {
      array[i][j] = true;
    }
  }


  for(int i = r-1;i>=0; i--){
    bool wall = false;
    int minisum = 0;
    //벽을 만나면 open이 false 된다(가둬짐.)
    //open false 사태에서는 minisum에 다 들어가는 물후보들
    //다시 벽을 만나면 open = false로 전환 되면서 모두 담겨진 물.
    //단 0이 아닌한 이전 값도 벽이라면 wall값 유지. 아무것도 하지 않음.
    //마지막 까지 갔을때 남아있는 minisum은 유기.
    //생각 못한 것 > 기둥에서 벗어날때 다시 세기 시작해야함.
    //일단 한번은 벽을 만나야 물이 가둬지기 시작함, 벽을 만나면 이때까지 합을 더함.
    //벽만나고 또 만나도 0더할테니 오케이.
    //왜 꼬아서 생각했을가..
    for(int j = 0; j<c; j++ ){
      bool thisblockwall = array[i][j];
      if(thisblockwall == true){
        if(!wall){
          wall = true;
        }
        sum+= minisum;
        minisum = 0;//안씀.
      } else {
        if(wall == true) {
          minisum++;
        }
      }
    }
  }
  std::cout << sum;
}