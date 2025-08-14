#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
vector<int> v;
bool visited[8] = { 0, };

// dfs로 순열 구하기
void dfs(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int tmp = 0;
    for (int i = idx; i < v.size(); i++) { //여기서 돌아가는 반복문은, 현재 idx이후 인덱스를 모두 cnt번째 값으로 고려해보는걸 뜻함.
        if (!visited[i] && v[i]!=tmp) { //첫조건은 아래 나와있듯 단순하고, 두번째 조건은, 다른 인덱스라도 해당 원소 차례에 이미 v[i]값을 고려했다면 넌 아니야.
            visited[i] = true;//해당 인덱스를 방문으로 체크했다면
            arr[cnt] = v[i];
            tmp = arr[cnt];
            dfs(i,cnt + 1);//다음호출 부터는 건너 뛰어짐(맨처음 호출때는 아무것도 없으니 다 돌수있게 고려한 것 같음.)
            visited[i] = false;//다 해봤으니 뺀걸로 가정.
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    dfs(0,0);
    return 0;
}
//기존, 이 인덱스의 원소를 선택한 순열, 선택하지 않은 수열을 계산.
//이것, 모든 인덱스의 원소를 이 순서로 선택한 순열을 계산.
// 이렇게 하니 199 에대해서 1 9 와 1 9 의 중복 제거가능. (첫 반복문 > 1선택 > 둘째 반복문 9 선택, 9선택시이미 선택해서 끝., 9선택(바로 끝남))
// 앞까지의 선택은 모두 공유되고, 해당 번재 선택역시 공유됨.
// 이전 버전은 현재 이를 선택할지 말지만.

//이 버전이 거의 다 사용 된다.