#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000005];
int arr[1000005];
int N;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i-1]+1;
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3]+1);
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
    }
    int iter = N;
    cout << dp[N] << '\n';
    while(iter != 1) {
        cout << iter << ' ';
        int temp = iter;
        iter--;
        if(temp % 2 == 0 && dp[iter] > dp[temp/2]) iter = temp/2;
        if(temp % 3 == 0 && dp[iter] > dp[temp/3]) iter = temp/3;
    }
    cout << 1;
    return 0;
}