//처음시작 상태 > 반드시 소문자가 들어와함
//상태 1 > C++의 경우 소문자, _소문자가 들어올 수 있음
//상태 1 > java의 경우 소문자, 대문자가 들어올 수 있음. 근데 무조건 이거니까 문제 없음
// 처음 시작 -> 상태 1(소문자 입력), 이외 입력은 오류
// 상태 1 c++ -> 소문자 입력시 상태1, 대문자 입력시 상태 1
// 상태 1 java -> 소문자 입력시 상태 1, _입력시 상태 2
// 상태 2 java -> 소문자 입력시 상태 1,
// 종료 조건 둘다 상태 1.
// 두개 모두 구현해서 검사하기.

//만약 특정언어라는 것이 확인된다면
//둘의 차이인 것만 교체하면 됨.
//35분.
#include <vector>
#include <iostream>
#include <string>

int main() {

    std::string name;

    std::cin >> name;

    bool cpp = false;
    bool java = false;

    int statement = 0;

    for(int i = 0; i < name.size() ; i++) { //자바인가
        char temp = name.at(i);

        if(temp>= 97 &&temp <= 122 && statement == 0) {
            statement = 1;
        }
        else if(statement ==1 && statement && temp != '_') {
            statement = 1;
        }
        else {
            break;
        }

        if(i == name.size()-1)
        java = true;
    }

    for(int i = 0; i < name.size() ; i++) { //cpp인가
        char temp = name.at(i);

        if(temp>= 97 &&temp <= 122 && statement == 0) {
            statement = 1;
        }
        else if(statement ==1 && temp>= 97 &&temp <= 122) {
            statement = 1;
        }
        else if(statement ==1 && temp == '_') {
            statement = 2;
        }
        else if(statement ==2 && temp>= 97 &&temp <= 122) {
            statement = 1;
        }
        else {
            break;
        }

        if(i == name.size()-1 && statement == 1)
        cpp = true;
    }

    
    if(cpp || java) {
        std::string out;

        for(int i = 0; i< name.size(); i++) {
            if(name.at(i) == '_'){
                i++;
                out+= name.at(i) - 32;
            } else if (name.at(i) >= 65 && name.at(i) <=90) {
                out+= '_';
                out += name.at(i) + 32;
            } else {
                out+= name.at(i);
            }
        }
        std::cout << out;
    } else {
        std::cout << "Error!";
    }
}