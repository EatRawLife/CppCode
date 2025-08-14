//N개 자연수 중에서 M 개 고르기.
//오름차순으로 나열
//선택한 숫자 N개중에서 M개 고르는 경우의 수.
//각선택지마다 고르거나 안고르는 경우의 수. 
//M개 골랐다면 출력, N개 모두 통과했다면 아웃. > 두개의 인수
//중복이생기는 경우는?
//중복인거 다 쳐넣으면 상관없음.
//셋으로 해도 안되네... 중복인것도 필요해.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

int N; //들어오는 수
int M; // 고르는 개수
std::vector<int> acu(8);
std::ostringstream out;
std::vector<int>com;

void call(int index, int length, bool added) {//탐색할 인덱스, 현재의 길이
    if(length == M) {
        for(int i = 0; i< M ; i++) { //배열의 길이는 정해짐 > for(int i : 배열)형태의 순회는 최대길이라 불가능
            out << acu[i] << ' ';
        }
        out << '\n';
        return;
    }

    if(index < N){
        acu[length] = com[index];
        if(!(index> 0 && com[index -1] == com[index] && added == false))
        call(index + 1, length+1, true);

        call(index + 1, length, false);
    }

    return;
}

int main() {
    std::cin >> N >> M;
    
    for(int i = 0; i< N; i++) {
        int temp;
        std::cin >> temp;
        com.push_back(temp);
    }

    sort(com.begin(), com.end()); //이게 없으면 같은게 함께 있다는조건이 깨지지.

    call(0, 0, false);
    std::cout << out.str() << std::flush;

}
//내가 컴파일 하는 파일이 그파일이 맞는지도 좀 확인해보고하자...
//배열 크기를 resize로 조절하는 양식, 은근히 많다.