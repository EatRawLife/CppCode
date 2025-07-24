#include <iostream>
#include <vector>
#include <deque>
int n;
int iter;
std::vector<int> arr;
std::vector<int> arr2;
std::vector<int> iterarr;

//시작 조건 : n0 = 0, n1 = 1
//recursive step : nn-2 + n n-1 = n
//필요 조건 앞에 2개.(이전것)

int main() {
  arr.push_back(0);
  arr.push_back(1);


  int i = 2;
  while(arr.at(i-2) <= 1000000){
    arr.push_back(arr.at(i-1)+ arr.at(i-2));
    i++;
  }

  arr2.push_back(arr.at(i-2));
  arr2.push_back(arr.at(i-1));

  iterarr.push_back(arr.at(i-2)%1000000);
  //iterarr.push_back(arr.at(i-1)-1000000); 이게 100만 넘음;;
  iterarr.push_back(arr.at(i-1)%1000000);


  for(int i = 0; i< 100; i++) {
    while(iterarr.at(iterarr.size()-2)<=1000000){
      iterarr.push_back(iterarr.at(iterarr.size()-2)+iterarr.at(iterarr.size()-1));
    }
    i+= (iterarr.size() - 2);

    std::cout << iterarr.back() <<'\n';

    //std::cout << iterarr.size() <<' '<< iterarr.at(iterarr.size()-2) << '\n';

    if(iterarr.at(iterarr.size()-2)== arr2.front() &&iterarr.at(iterarr.size()-1)== arr2.back()) 
    break;

    int temp1 = iterarr.at(iterarr.size()-2)%1000000;
    int temp2 = iterarr.at(iterarr.size()-1)%1000000;
    std::vector<int> iterarr({});

    iterarr.push_back(temp1);
    iterarr.push_back(temp2);


    
  }
  std::cout << i;
}
