#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> v;
std::vector<int> L(1000,1);

int main() {
  std::cin >> N;

  for(int i = 0; i< N; i++) {
    int temp;
    std::cin >> temp;
    v.push_back(temp);
  }

  for(int i = 1; i< N; i++) {
    for(int j = 0; j<i; j++) {
      if(L[j] + 1 > L[i]  && v[i] > v[j]){
        L[i] = L[j] + 1; 
      }
    }
  }

  sort(L.begin(), L.end());

  std::cout << L.at(L.size()-1);
}