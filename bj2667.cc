#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>//이거알아보기

int line;
int matrix[25][25];
int group = 1;
std::vector<int> s;
int sum = 0;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void dfs(int x , int y){
  matrix[x][y] = group;
  sum++;

  for(int i = 0; i < 4; i++){
    int newx = x + dx[i];
    int newy = y + dy[i];

    if(newx >= 0 && newx < line && newy >=0 && newy < line && matrix[newx][newy] == 1)
    dfs(newx,newy);
  }
}

int main(){
  std::cin >> line;

  for(int i = 0; i< line; i++){
    std::string s;
    std::cin >> s;

    for(int j = 0; j<line; j++){
      int c;
      matrix[i][j] = s.at(j)-'0';
      //이형태말고 char -> int 하는 것도 알아야할듯.
    }
  }


  for(int i = 0; i < line; i++){
    for(int j = 0; j< line; j++){
      if(matrix[i][j] == 1){
        group++;//이를 어따 박는게 좋을까?
        dfs(i, j);
        s.push_back(sum);
        sum = 0;
      }
    }
  }
  std::cout << group-1 << '\n';

  sort(s.begin(), s.end());
  for(int i = 0; i< s.size(); i++){
    std::cout << s[i] << '\n';
  }

}
//다차원 배열 찾아보기
