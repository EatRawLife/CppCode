//일단 11개를 순서대로 나열 > 11! , 브루트 포스로 풀림. 
//안되면 dp? 해야할거 같긴한데, 최소도 구해야하고 최대도 구해야하고, 어디까지 어떤 연산자 썻는지 순서 나타내기도 힘들고...
//이미 더해진 오퍼랜드 인덱스 기준으로.
//각 연산자마다 돌아가면서.(0으로 만들고 +1)

#include <iostream>
#include <vector>
#include <algorithm>

int N;//피연산자 개수
int operators[4];
std::vector<int> operand;
std::vector<int> big;
void oper(int sum, int index){
    for(int i = 0; i< 4; i++) {
        int temp;
        if(operators[i] != 0) {
            switch(i){
                case 0:
                    temp = sum + operand.at(index+1); //역시 index,i 햇갈림, 이게 뭔용도인지 꼭 상기하고 가기
                    
                    break;
                case 1:
                    temp = sum - operand.at(index+1);
                    
                    break;
                case 2:
                    temp = sum * operand.at(index+1);
                    
                    break;
                case 3:
                    temp = sum / operand.at(index+1);
                    
                    break;
                default:
                    break;
            }
            operators[i]--;

            if(index == N-2){
                big.push_back(temp);                
            } else {
                oper(temp, index+1);//index++로 쓰고, temp계산 이 아니라 sum에 합해 그대로 썻다. 이는 안되지, oper의 인수로만 전달되야지, 값자체를 바꿔버리면 그다음 for문 사이클에 영향이 가잖아. 서로 독립적이어야하는데.
            }

            operators[i]++;
        }
    }
}

int main() {
    std::cin >> N;

    for(int i = 0; i< N; i++) {
        int a;
        std::cin >> a;
        operand.push_back(a);
    }

    for(int i = 0; i<4; i++) {
        std::cin >> operators[i];
    }

    oper(operand.at(0), 0);
    sort(big.begin(), big.end());

    std::cout << big.back() << '\n' << big.front();

}