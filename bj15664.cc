//N개 자연수 중에서 M 개 고르기.
//오름차순으로 나열
//선택한 숫자 N개중에서 M개 고르는 경우의 수.
//각선택지마다 고르거나 안고르는 경우의 수. 
//M개 골랐다면 출력, N개 모두 통과했다면 아웃. > 두개의 인수
//중복이생기는 경우는?
//중복인거 다 쳐넣으면 상관없음.
//단 

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

int N; //들어오는 수
int M; // 고르는 개수
std::set<int> cm;
std::vector<int> acu(8);
std::ostringstream out;
std::vector<int>com;

void call(int index, int length) {//탐색할 인덱스, 현재의 길이
    if(length == M) {
        for(int i = 0; i< M ; i++) { //배열의 길이는 정해짐 > for(int i : 배열)형태의 순회는 최대길이라 불가능
            out << acu[i] << ' ';
        }
        out << '\n';
        return;
    }

    if(index < N){
        acu[length] = com[index];
        call(index + 1, length+1);
        call(index + 1, length);
    }

    return;
}

int main() {
    std::cin >> N >> M;
    
    for(int i = 0; i< N; i++) {
        int temp;
        std::cin >> temp;
        cm.insert(temp);
    }

    //첨에 N = com.size()를 여기 넣어서 틀렸음.
    std::copy(cm.begin(),cm.end(), std::back_inserter(com));
    N = com.size(); 

    //정렬안하면, 먼저 받은 것을 우선. 크기 순서가 아닌 배열의 원소 순서대로
    //기본 값은 디폴트가 0이니까 정렬하면 0이 맨앞으로 가겠지 ㅠㅠㅠ.... 왜 이런거 생각을 못하는거야.

    call(0, 0);

    //정렬은 sort(배열, 배열 정렬할 끝) 이렇게도 정렬가능 > 길이 정해져있어도 오케이
    std::cout << out.str() << std::flush;

}
//셋 사용을 연습해야할 것 같아.