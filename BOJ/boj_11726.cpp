#include <iostream>
using namespace std;

int dp[1005];
int N;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= N; i++) 
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    cout << dp[N];
    return 0;
}