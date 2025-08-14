//자연수 N,M 이 주어짐. 
//1부터 N까지 자연수중 종복 없이 M개 고르기.
//백트래킹 이용하기, 수가 적으며, 모든 결과를 순회해야함.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int N;
int M;
std::vector<bool> visited(8);
std::vector<int> v(8);
std::vector<int> comm(8); //이미 크기는 M으로 고정되어서 size()가아닌 다른 변수 사용해야함을 명심!
std::ostringstream str;

void dfs(int i) {
    if(i == M) {
        for(int i = 0; i < M; i++) {
            str<< comm[i]<< ' ';
        }
        str << '\n';
    }

    for(int j = 0; j< N; j++) {
        if(!visited[j]) {
            visited[j] = true;//이를 방문한 케이스
            comm[i] = v[j];
            dfs(i+1);//더 깊게 들어가 세부 케이스 살피기
            visited[j] = false; //방문 끝
        }
    }

}


int main() {
    std::cin >> N >> M;
    for(int i = 0; i<N; i++){
        v[i] = i+1;
    }

    dfs(0);

    std::cout << str.str() << std::flush;
} 


