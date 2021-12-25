#include <iostream>
#include <vector>
using namespace std;

int N, S;
int arr[21];
vector<int> pickedIndex;
int cnt = 0;

// n은 이미 뽑은 원소의 개수. k는 총 뽑을 원소의 개수.
void solve(int& sum, int n, int k) {
    if(n == k) {
        if(sum == S) cnt++;
        return;
    }
    int nxt;
    // 뽑은 원소가 없으면 index를 0으로 만들어 준다.
    if(pickedIndex.empty()) nxt = 0;
    // 중복 방지. 이번에 뽑을 것은 이미 뽑은 거 바로 다음 인덱스를 선택함.
    else nxt = pickedIndex.back() + 1;
    // 맨 마지막 원소가 이미 뽑혔을 경우에는 반복문을 돌지 않음.
    for(int i = nxt; i < N; i++) {
        // 원소 선택.
        pickedIndex.push_back(i);
        sum += arr[i];
        solve(sum, n+1, k);
        pickedIndex.pop_back();
        sum -= arr[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++) {
        int sum = 0;
        solve(sum, 0, i);
    }
    cout << cnt;
    return 0;
}