#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];
int cost[1001][3];
int N;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) 
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    dp[0][0] = cost[0][0]; dp[0][1] = cost[0][1]; dp[0][2] = cost[0][2];
    for(int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }
    int res = min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
    cout << res;
    return 0;
}