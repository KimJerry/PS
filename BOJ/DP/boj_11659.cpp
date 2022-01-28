#include <iostream>
using namespace std;

int dp[100005];
int num[100005];
int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> num[i];
    dp[1] = num[1];
    for(int i = 2; i <= N; i++) dp[i] += dp[i-1] + num[i];
    while(M--) {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << '\n';
    }
    return 0;
}