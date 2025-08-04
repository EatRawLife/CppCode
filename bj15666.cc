//N개 자연수중에서 M 개 고르기. 같은거 여러번 골라도 오케이. 
//여러개 넣을 수 있지만, 같은 수 입력은 의미가 없음. 이미 중복을 허용하니까.
//비 내림차순? 일단 오름차순으로.
//중복으로 들어오는 수는 어떻게 처리하는가? >> 진짜 들어올수 잇는 숫자 리스트를 마련, 중복이라도 그냥 1로 만드니 문제 없음
//중복으로 들어오는 다른 처리 예시 > 정렬해서 나열해서 추가하면, last라는 인수를 두고 이전 call 요청과 같다면, 그건 날린다.(섹시 하지 않아..) 근데 이거 나름 자주 쓰나봄.. 시간아끼는건 될듯 ;;
//"" > 단순히 셋으로 중복 제거후 정렬.
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int N;
int M;
int nlist[10001];
std::ostringstream str;

std::vector<int> com;

void call(int startvalue){//어거지로 그냥 처음부터 반복해서, 마지막 수열의 값보다 작으면 스킵하도록해서 인수 다 없앤것도 있었음 ㅋㅋㅋ
    //인덱스 밖이면 여기 들오면 안돼
    //벡터 크기 이상이면 들어오면안돼
    if(nlist[startvalue] == 1) { 
        com.push_back(startvalue);//이게 항상 중간

        if(com.size()== M){ //이부분이 항상 맨처음.
            for (int i : com) {
                str << i << ' ';
            }
            str << '\n';
        } else {

            for(int i =startvalue; i<=10000; i++) {
                call(i);
            }

        }
        com.pop_back();
        //배열을 통해 구현했다면 뺄 필요 없이 그냥 덮어씌워버리면 그만이긴함.
    }
}

//이 이름을 보통 dfs로 한다. 생각해보면 dfs랑 비슷하긴 하네

int main(){
    std::cin >> N >> M;

    for(int i = 0; i< N; i++) {
        int temp;
        std::cin >> temp;
        nlist[temp] = 1;
    }

    for(int i = 1; i<=10000; i++) {
        call(i);
    }
    //이렇게 하는 유형도 있긴하네.

    std::cout << str.str() << std::flush;
}

//메소드 시작을 해당 인덱스를 넣는걸로할까? 여기까지 넣은걸로 할까? > 따라 실행하는 방법이 다소 달라지니 고려해야지.
//함수내에서 인덱스 밖의 호출, 꽉차는거 판단을 어디서 막을 것인가? > 신경 써야함.
//보통 속도 땜시 C 배열 쓴다... 우째서.. 그래서 길이까지 저장해.. 우웩
