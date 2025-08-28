//NxN 크기. 각칸 마다 바구니 물을저장. 
//1based
//행의 시작끝, 열의 시작끝은 연결되어잇다. 
//구름의 중심은 좌측 끝으로 하자.
//모든 입력은 1based

//쌩구현 문제.
//여러 배열, 이름 선언할일많고, 집중안해서 좀 오래걸림.

#include<iostream>
#include<tuple>

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};


int copyx[4] = {-1,-1,1,1};
int copyy[4] = {-1,1,1,-1};

int getindex(int N, int base, int plus) {
    return((base+plus)%N + N) % N;
}


int N,M;

int main() {
  std::cin >> N >> M;
  int arr[N][N];
  bool cloud[N][N];



  for(int i = 0; i< N; i++) {
    for(int j = 0; j< N; j++) {
      std::cin >> arr[i][j];
      cloud[i][j] = false;
    }
  }

  cloud[N-1][0] = true;
  cloud[N-2][1] = true;
  cloud[N-2][0] = true;
  cloud[N-1][1] = true;


  for(int times = 0; times< M; times++) {

    int direc, len;
    std::cin >> direc >> len;
    direc -= 1;

    bool newarray[N][N];//이동한 구름 위치

    for(int i = 0; i< N; i++) {
      for(int j = 0; j< N; j++) {
        newarray[i][j] = false;
      }
    }

    for(int i = 0; i< N; i++) {
      for(int j = 0; j< N; j++) {
        if(cloud[i][j]){
          newarray[getindex(N,i,dx[direc]*len)][getindex(N,j,dy[direc]*len)] = true;
        }
      }
    }
    
    for(int i = 0; i< N; i++) {
      for(int j = 0; j< N; j++) {
        if(newarray[i][j]){
          arr[i][j]++;
        }
      }
    }//물채우기

    for(int i = 0; i< N; i++) {
      for(int j = 0; j< N; j++) {
        if(!newarray[i][j])
        continue;

        int sum = 0;
        int newx, newy;


        for(int t = 0; t<4; t ++) {
          newx = i+ copyx[t];
          newy = j+ copyy[t];
          if(newx >= 0 && newx < N && newy >=0 && newy <N && arr[newx][newy] >0 )
          sum++;
        }
        arr[i][j]+= sum;
      }
    }//물복사 버그

    for(int i = 0; i< N; i++) {
      for(int j = 0; j< N; j++) {
        if(!newarray[i][j] && arr[i][j]>=2){
          arr[i][j] -=2;
          cloud[i][j] = true;
        } else{
          cloud[i][j] = false;
        }
      }
    }

  }


  int sum = 0;
  for(int i = 0; i<N; i++) {
    for(int j = 0; j< N; j++) {
      sum += arr[i][j];
    }
  }

  std::cout <<sum;
}

