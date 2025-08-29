//첫시도 실패. dfs부분에서 계속 세그 폴트남.
//조금 차례로 구현해보자.
//dfs > 진행하되, 만약, connected component 가 4이상이면 표시 (물론 비짓배열은 있어야.)
//4가 되는 순간, 해당 블록은 표시. (특정배열에)
//비짓배열을 초기화한 후, 표시된 블록은 다시 dfs하면서 .으로 교체.

//아직 dfs를 제대로 구현하지 못하는 느낌....
//너무...너무 어려웠다...
//각각의 dfs 로직 구현에서 실수좀 많이했고(비짓배열 안들르기, 방문해야할 조건 (값이 같음) 안살피기)
//중력 적용에서도 많이 어려워했음. 이쪽 로직 자세히 보기.

#include<iostream>
#include<string>
#include<utility>

bool visit[12][6];
int arr[12][6];
bool over4[12][6];
int sum = 0;
bool pop = false;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int r, int c){
    visit[r][c] = true;
    sum++;
    if(sum == 4) {
        over4[r][c] = true;
        pop = true;
    }

    for(int i = 0; i< 4; i++) {
        int newx, newy;
        newx = r+dx[i];
        newy = c+dy[i];

        if(newx >=0 && newx <12 && newy >=0 && newy < 6 && arr[newx][newy]== arr[r][c] && !visit[newx][newy]){
            dfs(newx,newy);
        }
    }
}
void dfs2(int r, int c){
    visit[r][c] = true;

    for(int i = 0; i< 4; i++) {
        int newx, newy;
        newx = r+dx[i];
        newy = c+dy[i];

        if(newx >=0 && newx <12 && newy >=0 && newy < 6 && arr[newx][newy]== arr[r][c] && !visit[newx][newy]){
            dfs2(newx,newy);
        }
        
    }
    arr[r][c] = '.';
}

int puyopuyo(int rensai){

    pop = false;

    for(int i = 0; i< 12; i++) {
        for(int j = 0; j<6; j++) {
            visit[i][j] = false;
            over4[i][j] = false;
        }
    }


    for(int i = 0; i< 12; i++) {
        for(int j = 0; j< 6; j++) {
            if(!visit[i][j] && arr[i][j]!= '.'){
                sum = 0;
                dfs(i,j);
            }
        }
    }

    for(int i = 0; i< 12; i++) {
        for(int j = 0; j<6; j++) {
            visit[i][j] = false;
        }
    }

    
    if(pop){
        for(int i = 0; i< 12; i++) {
            for(int j = 0; j<6; j++) {
                if(over4[i][j])
                dfs2(i,j);
            }
        }

        for(int j = 0; j< 6; j++) {
            for(int i = 10; i>=0; i--) {
                for(int index = i; index < 11; index++) {
                    if(arr[index+1][j] == '.'&& arr[index][j] != '.')
                    std::swap(arr[index+1][j], arr[index][j]);
                }
            }
        }

        return puyopuyo(rensai+1);
    }else{
        return rensai;
    }
    
    
}

int main() {
    for(int i = 0; i< 12; i++) {
        std::string s;
        std::cin >> s;
        for(int j = 0; j<6; j++) {
            arr[i][j] = s.at(j);
        }
    }

    std::cout << puyopuyo(0);

}