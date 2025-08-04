//가로 세로 100 제한, 가로 세로 10인 색종이 붙이기
//0based.
//도화지 밖으로 나가는 일 없음. -> 이상한 입력 고려 x

#include <iostream>

int mat[100][100];
int N;

int main() {

    std::cin >> N;

    for(int i = 0; i< N; i++) {
        int r,c;
        std::cin >> r >> c;

        for(int j = 0 ;j < 10; j++) {
            for(int z = 0; z <10; z++) {
                if(j >= 0 && j<100 && z >= 0 && z <100) {
                    mat[r+j][c+z] = 1;
                }
            }
        }
        
    }

    int sum = 0;

    for(int i = 0; i< 100 ;i++) {
        for(int j = 0; j < 100; j++) {
            sum += mat[i][j];
        }
    }

    std::cout << sum;
}