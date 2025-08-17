#include <sstream>
#include <iostream>
#include <string>
#include <deque>

//각 컨테이너마다 사용가능한 함수 다시보기.
//getline, delimeter 이용 다시보기.

int T;

void notmain() {
    std::string funcs;
    std::cin >> funcs;
    int n;
    std::cin >> n;
    bool reverse = false;
    std::deque<int> nums;

    std::string input;
    std::cin >> input;
    input = input.substr(1, input.size()-2);
    std::stringstream temp(input);

    std::cin.ignore();

    if(n > 0){
        for(int i = 0; i<n; i++) {
            std::string tempstr;
            std::getline(temp,tempstr, ',');// 이부분 다시보고 복습
            nums.push_back(std::stoi(tempstr));
        }
    }


    for(int i = 0; i< funcs.size(); i++) {
        char a = funcs.at(i);
        
        switch(a) {
            case 'R':
                reverse = !reverse;
                break;//이거 안넣음.. + case 현대적 사용 찾아보기.
            case 'D':
                if(nums.empty()){
                    std::cout << "error" << '\n';
                    return;
                }

                if(reverse) {
                    nums.pop_back();
                } else {
                    nums.pop_front();
                }
                break;
        }
    }

    std::cout << '[';

    if(nums.empty()){

    }
    else if(reverse){
        for(int i = nums.size()-1; i>0; i--) {
            std::cout << nums[i] << ',';
        }
        std::cout << nums[0];//처음에는 if 조건이 없어서 여기에서 오류 났네.. 텅비면 오류나지

    } else {
        for(int i = 0; i< nums.size()-1; i++) {
            std::cout << nums[i] << ',';
        }
        std::cout << nums[nums.size()-1];//여기도
    }
    std::cout << "]\n";

}

int main() {
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> T;

    for(int i = 0; i< T; i++) {
        notmain();
    }
}
