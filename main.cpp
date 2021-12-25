#include <iostream>
using namespace std;

int N, S;
int arr[20];
int dfs(int i, int sum) {
    if(i == N) return sum == S;
    return dfs(i+1, sum) + dfs(i+1, sum+arr[i]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cout << dfs(0, 0) - !S;
    cout << !5;
    return 0;
}