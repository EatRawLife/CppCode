//수열에 주어진 수를 통해 다음 수를 찾는 문제.
//주어지는 개수에 의미가 있을꺼야...
//50보다 작거나 같은 수N, 최대50개 입력, -100 ~ 100 범위. *-100~100, +200~-200
//모든 조합을 다 따진다면 200400 80000
//모든 조합을 100개 다통과한다면 100만개.
//이슈 > 수가 -100~100이기만 하면됨. 
// 1에 2가 1억 곱하기 - 1억 -1이면 된다...
// 마지막 나의 궁금증 > 첫번째에 무한대의 조합, 이를 어떻게 걸러내며, 어떻게 2번째랑 조화시킬까.
// 연립방정식을 생각해보자. 윗식을 만족하는건 무한대다. 그러나 두개 식으로 잘 나타낸다. > 무한대로 한다면 방정식, 수학적 풀이를 떠올려보자. 너무 꼬아서 생각했다.

//y = ax + b 형태 (단. a와 b는 정수.)
//방정식을 만들기위해 필요한 식은 두개
//a[0] = a[1] * a + b
//a[1] = a[2] * a + b
//따라서 숫자 3개 > 하나의 조합,
//그이상 > 이때까지 a, b 조합으로도 다 완성이 되어야함. > 그식으로 마지막 출력.
//2개 > 1차원무한대의 조합. 단, '구하는 것이 결론' 이므로 다같다면 그대로,나머지는 A.
//1개 > 2차원 무한대의 조합. A
//방정식 구현은?
//반드시 값이 다음 항으로 가능한게 하나일 보장은?

//문제가 섹시 하지 못한 느낌...
//방정식 형태로 풀때, 다른 사람들은 어떻게 계수가 0인 경우를 처리했을까?(a,b를 구할 수 없으니 문제가 상당히 더러워짐.)
//가능한 a,b 조합이 여러개인데 어째서 반드시 가능한 다음 수가 여러개라 확신할 수 있을까?
//반대로 가능한 a,b 조합이 여러개인데 다 같은 값이라고 확신할 생각의 흐름으 따라가기 힘들다..

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> nums;
for(int i = 0; i< N; i++) {
    int temp;
    std::cin >> temp;
    nums.push_back(temp);
  }
  if(N == 1){
    std::cout << 'A';
    return 0;
  }
  if(N == 2 && nums[0] != nums[1]) {
    std::cout <<'A';
    return 0;
  }
  if(N == 2){
    std::cout << nums[0];
    return 0;
  }

  int a;
  int b;

  if(nums[0]-nums[1] == 0 && nums[1]-nums[2] == 0 ){
    for(int i : nums){
      if(i != nums[0]){
        std::cout << 'B';
        return 0;
      }
    }
    std::cout << nums[0];
    return 0;
  } else if(nums[0]-nums[1] == 0 && nums[1]-nums[2] != 0 ){
    std::cout << 'B';
    return 0;
  }
  
  if(abs(nums[1]-nums[2])%abs(nums[0]-nums[1]) == 0) {
    a = (nums[1]-nums[2]) /(nums[0]-nums[1]);
    b = nums[1]-a* nums[0];
  } else {
    std::cout << 'B';
    return 0;
  }

  bool B = false;

  for(int i = 3; i< nums.size(); i++) {
    if(nums[i-1] * a + b != nums[i]){
      B = true;
      break;
    }
  }

  if(!B) {
    std::cout << nums[nums.size()-1] * a + b;
  } else {
    std::cout << 'B';
  }
}