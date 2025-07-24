//점프게임
//골드 5

//가능성 탐구. dfs, wfs 의 여지가 있지만 확실치 않다.
//그리디랑은 다른가봄. 그리디는 딱하나의 결과만 추측할 수 있나봄
//시작은 왼쪽 줄 1번 칸(0,0)에서 항상 시작한다.
//매칸마다 칸이 하나씩 사라지니 (이를 구현하기 위해서는 dfs로는 불가, wfs로 해야할 것. )
//0으로 가득찬 배열을 만들어서 초가 지날때마다 특정 인덱스 앞부터는 여기로 탐색하는 거로하면
//사라지는 발판을 구현 가능할 듯 하다. 
//가능한 무브는 정면 1, 후방 1, 옆으로 + i+k 칸으로. 
//어짜피 다시 밟은 곳을 다시 밟는 것은 의미가 없다. 그러니 이는 제외한다.
#include <vector>
#include <deque>
#include <iostream>
#include <string>

int N;
int k;
int miro[2][100000];
int visited[2][100000];
bool result = false;



int main() {
    std::cin >> N >> k;

    int dx[4] = {0, 0, 1, -1};//후방 전방 우측줄 좌측줄
    int dy[4] = {-1, 1, k, k};

    for(int i = 0; i< 2; i++){
        std::string str;
        std::cin >> str;
        for(int j = 0; j< N; j++) {
            miro[i][j] = str.at(j) - 48;
        }
    }

    std::deque<int> q;
    q.push_back(0);
    q.push_back(0);
    visited[0][0] = 1;
    int collapsedindex = -1;//시작할때는 무너진거 없음.
    int nowpushed = 0;
    int fastpushed = 1;
     
    while(!q.empty()){
        int px = q.front();
        q.pop_front();
        int py = q.front();
        q.pop_front();
        fastpushed--;

        if(collapsedindex >= py)
        continue;

        for(int i = 0; i< 4; i++) {
            int newpx = px + dx[i];
            int newpy = py + dy[i];

            if(newpy >= N){
                result = true;
                break;
            }

            if(newpx >= 0 && newpx <2 && newpy >=0 && visited[newpx][newpy] == 0 && miro[newpx][newpy] == 1) {
                visited[newpx][newpy] = 1;
                q.push_back(newpx);
                q.push_back(newpy);
                nowpushed++;
            }
        }

        if(fastpushed == 0){
            fastpushed = nowpushed;
            nowpushed = 0;
            collapsedindex++;
        }
    }



    std::cout << (int)result;
}
//실수 한 부분. 한턴을 어떻게 구현할 것인가. 너비 우선탐색의 경우 
//와일문의 반복은 한턴에 해당되는 모든 케이스가 팝될때에 해당한다.
//이를 어떻게 구현할지가 약간 핵심이었던 느낌?

//1시간 6분