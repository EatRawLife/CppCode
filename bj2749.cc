#include <iostream>
#include <vector>

int n;
std::vector<int> pibo; 

int main() {
    pibo.push_back(0);
    pibo.push_back(1);
    while(true){
        int push = (pibo.at(pibo.size()-2) + pibo.at(pibo.size()-1)) % 1000000;
        pibo.push_back(push);

        if(pibo.at(pibo.size()-1) == 1 && pibo.at(pibo.size()-2)== 0)
        break;
        
    }

    int cycle = pibo.size() - 2;

    //std::cout << cycle;
    //솔직히 답이 150만이라는걸 알고 풀어서 그렇지 좀 햇갈렸음. 사이클의 크기 구할때.
    //피보나치 인덱스 0부터 시작. 하지만 사이즈는 1부터 시작.
    //그리고 결과로 나온 150만2는 한 사이클을 돌아서 이전 사이클의 두개 값을 더한 값.
    //따라서 사이즈에서 2를 뺀 값이 맞다.

    unsigned long long i;
    std::cin >> i;

    int samei = (int)((i) % cycle);

    std::cout << pibo.at(samei);

}