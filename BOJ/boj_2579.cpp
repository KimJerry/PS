#include <iostream>
#include <algorithm>
using namespace std;

int dp[301][2];
int score[301];
int N;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> score[i];
    dp[0][0] = dp[0][1] = score[0];
    dp[1][0] = score[1]; dp[1][1] = dp[0][0] + score[1];
    for(int i = 2; i < N; i++) {
        dp[i][0] = max(dp[i-2][0]+score[i], dp[i-2][1]+score[i]);
        dp[i][1] = dp[i-1][0]+score[i];
    }
    cout << max(dp[N-1][0], dp[N-1][1]);
    return 0;
}