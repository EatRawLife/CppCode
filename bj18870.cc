//수직선 위에 1based 으로 1~N의 좌표.
//이를 '좌표압축'.
//좌표압축후 xi 보다 작은 좌표 개수 = 변경후xi보다 작은 좌표개수.
//즉 모든 등장하는 숫자에 대해서 대응되는 순위를 매기고, 이에 맞게 바꿔주면될듯?
//1.이를 담은 벡터 만들기,
//2.이를 셋에 담은뒤 중복 없에서 정렬 > 크기 순대로 정렬된 벡터
//3.기존 벡터의 각 원소의 값의 순위를 찾아서, 그 순위를 삽입한 결과를 반환.

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

int myfind(int i , std::vector<int>& v) {
  int start = 0, end = v.size()-1;
  while(true){
    int middle = (start + end)/2;

    if(v.at(middle) > i){
      end = middle -1;
    } else if(v.at(middle) <i) {
      start = middle +1;
    } else {
      return middle;
    }
  }
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> firstv;
  std::set<int> s;

  for(int i = 0; i< n; i++) {
    int temp;
    std::cin >> temp;
    firstv.push_back(temp);
    s.insert(temp);
  }

  std::vector<int> v(s.begin(), s.end());
  std::sort(v.begin(),v.end());

  

  std::vector<int> result;

  for(int i: firstv) {
    result.push_back(myfind(i, v));
  }
  for(int i : result){
    std::cout << i<< ' ';
  }
}
