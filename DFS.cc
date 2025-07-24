#include <iostream>
#include <vector>


int n, m;
std::vector<int> from;
std::vector<int> to;
std::vector<std::vector<int>> arr(1000, std::vector<int>(10000, 0));//0부터 시작이라
std::vector<int> visited;
int glob = -1;

void explore(int vert){
    //if (visited[vert] == 1)
    //return; //이거 추가하면 안돼지

    visited[vert] = 1;
    glob++;
    for(int i = 1; i <= n; i++) {
        if(arr[vert][i] ==1 && visited[i] == 0){
            explore(i); 
        }
    }
    return;
} 

int main() {
    std::cin >> n >> m;

    for (int i = 0; i < m; i++) {
        std::cin >> from[i] >> to[i];
        arr[from[i]][to[i]] = 1;
        arr[to[i]][from[i]] = 1;
    }
    // 여기까지 입력


    explore(1);


    std::cout << glob;
    //출력
    return 0;
}
