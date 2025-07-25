#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

/*
typedef std::tuple<int, int> stuff;
int N;
int K;
std::vector<stuff> l;
int weigh[100001];

int main() {
  std::cin >> N >> K;
  for(int i = 0 ; i< N; i++) {
    int one, two;
    std::cin >> one >> two;
    stuff temp = std::make_tuple(one,two);
    l.push_back(temp);
  }

  sort(l.begin(), l.end()); // ㅅㅂ 맞다 들어올때 정렬해서 안들어왔지

  //자기 하나만 들어가야함. = 진행하는 방향에 자기가 들어간건 없어야함.

  for(int i = 0; i<N; i++) {
    int w,v;
    std::tie(w,v) = l.at(i);

    if(w <= K && weigh[w] < v)
    weigh[w] = v;
  }

  for(int i = N-1; i>= 0; i--) { // 큰거부터 하면 그다음 녀석들은 걱정없이 자기 다음 더함. i 는 물건의 인덱스

    int w,v;
    std::tie(w,v) = l.at(i);

    for(int j = K; j >= w+1; j--) {// 더해진거에 또 더할 수 있으니 역방향으로
      if(weigh[j] != 0 && j+ w <= K){
        int one = weigh[j] + v;
        int two = weigh[j + w];
        if(one> two)
        weigh[j + w] = one;
      }
    }

  }

  int max = 0;
  for(int i = 0; i<=K; i++) {
    if(max < weigh[i])
    max = weigh[i];
  }
  std::cout << max;
}
  */

//이슈 > 물건은 단하나, dp할때 자신을 더한 것에 또 연산하면 안됨.
//인덱스 다룸에 햇갈림(weigh의 인덱스인가, 아니면 벡터의 인덱스인가.)

//첫물건은 아무거나더하고, 거기다가 옆의 것은 아무것도 추가하지 않는 것 하나. 추가한 것 하나.
//이렇게 하면 모든 경우를 살필 수 있다.


typedef std::tuple<int, int> stuff;
int N;
int K;
std::vector<stuff> l;
int weigh[101][100001];

int main() {
  std::cin >> N >> K;
  for(int i = 0 ; i< N; i++) {
    int one, two;
    std::cin >> one >> two;
    stuff temp = std::make_tuple(one,two);
    l.push_back(temp);
  }



  for(int i = 0; i< N; i++) {
    int w, v;
    std::tie(w,v) = l.at(i);

    for(int j = 1; j<= K ; j++) {
      if(weigh[i][j] != 0 && weigh[i+1][j] < weigh[i][j]){
        weigh[i+1][j] =weigh[i][j]; 
      }

      if(j + w <= K && weigh[i][j] + v > weigh[i][j+ w]) {
          weigh[i+1][j+ w] = weigh[i][j] + v;  
      }
    }

    if(weigh[i+1][w] < v)
    weigh[i+1][w] = v;
  }



  int max = 0;
  for(int i = 0; i<=K; i++) {
    if(max < weigh[N][i]){
      max = weigh[N][i];
    }
  }
  std::cout << max;
}

//이 예시 역시도 역순이 맞다. 특정 크기의 물건을 모든 것에 더한다. 계산 결과에 해당할 위치에는 처음엔 값이없다.
//바로옆, 하단 대각선이 채워질 것인데, 만약 작은 것에서 큰것으로 하게 되면 옆에 옮길때 덧씌워질 수 있다.
// 행렬 기준으로 정방향(위 > 아래) 로 간다면 여기서 추가 되는 것은 바로 옆, 그리고 우측 대각선 위이다.
// 이곳이 텅텅 비어있다면 상관없지만, 이전 값에 의해서 채워져 있다면 이는 조심해야한다. 덮어 씌워질 수 있다.
// i에 대해서 무조건 같은 값이 더해지므로, 나중에 하는게 더 큰 값이 될 것이다. 따라서 대각선 아래 값은 항상 0일 것이다.
//그러나 바로 옆으로 옮기는건 겹쳐질 수도 있다.
//역방향의 경우라면 반대겠지.
//>> DP 문제 풀때, 덮어씌워지면 안되는거를 덮어씌우는 경우를 특히 조심하자.