#include <iostream>
#include <deque>

int main() {
    int n, w, L; //트럭 수, 다리 길이, 다리 최대 하중

    std::cin >> n >> w >> L;

    int weigh_limit = L;

    
    std::deque<int> bridge(w,0);
    std::deque<int> truckQ;

    for(int i =0; i<n; i++){
        int temp;

        std::cin >> temp;
        truckQ.push_back(temp);
    }

    int turn = 0;
    int weightsum = 0;
   
    while(true) {//조건 만날 햇갈림. 될때는 이게 참일때! 
        //처음 조건은 while(!(truckQ.empty() && weightsum == 0)). 이러면 트럭 큐가 비어도 탈출 못함 + 계속 뽑으려 할것.
        turn++;
        int next_push = 0;

        int bridge_end_truck = bridge.front();
        weightsum -= bridge_end_truck;

        if(!truckQ.empty()) {
            int next_truck = truckQ.front();

            
            if(weightsum + next_truck <= weigh_limit ){
                next_push = next_truck;
                truckQ.pop_front();
                weightsum += next_truck;
            }
        }
        
        bridge.pop_front();

        bridge.push_back(next_push);

        if(truckQ.empty() && weightsum == 0)
        break;
    }
    //약 30분의 문제 발생
    //문제 발생의 원인 > 큐가 빈데도 계속 꺼내는걸 고려안함 + 일부 로직을 변경했음에도 주변 로직을 살피지 않아서
    //틀린값이 계속 됨(if안에 다리에서 나온 차 무게 빼는게 있어 무게가 빠지지 않음)

    std::cout << turn;
}