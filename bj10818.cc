#include <array>
#include <iostream>

int main(){
  int count;
  std::cin >> count;

  std::array<int, 1000000> array;
  int min;
  int max;
  
  for(int i  = 0; i< count ; i++){
    int temp;
    std::cin >>temp;
    array[i] = temp;
  }

  min = array.at(0);
  max = array.at(0);

  for(int i = 1; i < count; i++ ){
    if(min > array.at(i)){
      min = array.at(i);
    }
    if(max <array.at(i)){
      max = array.at(i);
    }
  }

  std::cout << min << " " << max;
  return 0;
}
