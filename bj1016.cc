//최소의 값의 범위는 1~100만 1000 ^2.
//따라서 나누는 수의 가능한 범위는 최대 10만까지. (맥스 더하면 더 오르긴할듯)
//제곱 수 > 같은게 두개이상 곱해짐. 제곱수에의해서 나누어 떨어진다 = 제곱하기 전것 끼리도 나누어 떨어짐.
//제곱전 나누는 > 나누는 수가 제곱이라면 확인할 필요 없음.(이미 확인한 수)
//나누는 수(제곱 전 )특징 > 제곱했을때 값이 나눠지는 수보다 작거나 같음.
//나누는 수는 2부터 무한대로, max 보다 제곱값이 작다면 
//나누는 수 배열을 체크, true라면 패스, 
//false였을 경우에만 나눠지는 수 배열을 체크, true면 패스, 
//false일때 나누어떨어지면 true 전체의 --.,

#include <iostream>

bool devide[1001001];//인덱스가 아님.
bool deviden[1000001]; //인덱스로 하려함.

int main(){

  for(long long i = 0; i< 1001001; i++) {
    devide[i] = false;
  }
  for(long long j = 0; j< 1000001; j++){
    deviden[j] = false;
  }

  long long min, max;
  std::cin >> min >> max;

  long long sum = max-min+1;

  for(long long i = 2; i<=1001000; i++ ){//나눌수 있는 수.(제곱전)
    if(i*(long long)i > max) break;

    if(devide[i]) continue;

    for(long long j = 2; j*i<= 1001000 ; j++) {
      devide[i*j] = true;
    }
    
    long long dmin = min / (i*i);
    //dmin은 최소값에 대해 나누는 수를 나눈수에 곱한 값이다. 이때에, 어떤 수로 나누어 떨어진다면, 
    //이는 곱했을때 최소값이 된다 포함.
    if(dmin * i*i < min){
      dmin++;
    } 
    long long dmax = max / (i*i);
    //역시 나누어 떨어진다면 포함, 나누어 떨어지지 않는다면 정수부만 남는다. 

    for(long long j = dmin; j <= dmax ; j++) {//곱해지는 수의 배수중 나눠지는 수가 될수있도록 곱하는 수들
      long long index = j*i*i - min;
      if(!deviden[index]){
        deviden[index] = true;
        sum--;
      }
    }
  }

  std::cout << sum;

}
