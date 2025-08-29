//본점을 포함하는 원 > 탈출 횟수
//도착점을 포함하는 원 > 진입 횟수
//둘다 포함하는 원 > 제외.
//원방정식 이용

#include <iostream>

int n;
int x1,yl, x2,y2;

void traverse(){
    std::cin >> x1 >>yl >> x2 >> y2;
    int k;
    std::cin >> k;

    int count = 0;

    for(int i = 0; i<k; i++) {
        int ix, iy, length; //원
        std::cin >> ix >> iy >> length;

        bool first = ((x1-ix)*(x1-ix) + (yl-iy)*(yl-iy) < length*length) && ((x2-ix)*(x2-ix) + (y2-iy)*(y2-iy) > length*length);
        bool second = ((x1-ix)*(x1-ix) + (yl-iy)*(yl-iy) > length*length) && ((x2-ix)*(x2-ix) + (y2-iy)*(y2-iy) < length*length);
        //(x-a)^2 + (x-b)^2 = r^2

        if(first) count++;     
        if(second) count++;
    }

    std::cout << count <<'\n';
    

}


int main() {

    std::cin >> n;
    for(int i = 0; i< n; i++) {
        traverse();
    }


}