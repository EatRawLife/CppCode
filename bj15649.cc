// N과 M이 주어짐. 조건 만족하는 길이 M인 수열 모두 고르기. 
// 1부터 N 까지 중복없이 M개 고른 수열.
// 차례대로, 중복 없이. 현재 인덱스 위치, 총 길이를 들고.

//배열에 가능한 원소 추가
//꽉찼으면 출력, 안꽉찻아면 원소 하나 넣고 거기서 또호출
//다끝나고 빼기

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int N; 
int M;
std::vector<int> v;
bool visited[8];
std::ostringstream s;

void back(int checkindex, std::vector<int>& printlist) {
    //인덱스를 초과하는 입력이 들어와도 for(i에서 걸러짐)
    for(int i = 0; i< N; i++) {
        if(visited[i] == true)
        continue;

        printlist.push_back(v.at(i));
        visited[i] = true;

        if(printlist.size() == M){
            for(int i : printlist){
                s << i << ' ';
            }
            s << '\n';
        }
            
        back(i+1, printlist);// i 가아닌 check index로 했음. 제대로 뜻을 생각치 않아 생긴 문제.

        printlist.pop_back();
        visited[i] = false;
    }
}

int main() {
    std::cin >> N >> M;

    for(int i = 1; i<= N; i++){
        v.push_back(i);
    }

    std::vector<int> printlist;
    back(0, printlist);

    std::cout << s.str() << std::flush;
}