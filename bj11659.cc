//최대 10만개합 연산을 10만번 > 1억 이상. 그냥은 불가능.
//미리 합해두고, 뺀다.
//숫자들은 1based
#include <iostream>
#include <vector>
#include <sstream>


int N;
int M;
std::vector<int> st;
std::vector<int> en;
std::vector<int> sum;
std::ostringstream out;

int main() {
  std::cin >> N >> M;

  sum.push_back(0);

  for(int i = 0 ; i<N; i++){
    int get;
    std::cin >> get;
    sum.push_back(get+sum.back());
  }


  for(int i = 0; i< M; i++){
    int in1, in2;
    std::cin >> in1>>in2;
    st.push_back(in1);
    en.push_back(in2);
  }

  for(int i = 0; i< M; i++){
    int res =(sum.at(en.at(i)) - sum.at((st.at(i)-1)));//이번엔 운좋게 1부터 시작해문제 없었지만, i에서 -, + 할때 인덱스 오버되지 않을까 생각해봐야할것
    out << res <<'\n';
  }

  std::cout << out.str() << std::flush;
}

