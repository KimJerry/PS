#include <iostream>
using namespace std;

int T, N, dp[20];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i = 4; i <= 11; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    cin >> T;
    while(T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }
    return 0;
}