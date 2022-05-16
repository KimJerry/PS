#include <iostream>
using namespace std;

int N, K;
int coin[11];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> K;
    int res = 0;
    for(int i = 0; i < N; i++) cin >> coin[i];
    for(int i = N-1; i >= 0; i--) {
        res += (K / coin[i]);
        K %= coin[i];
    }
    cout << res;
    return 0;
}