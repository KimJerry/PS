#include <iostream>
#include <cstdlib>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;


int cnt = 0;
int N;
bool used[16];
bool used2[30];
bool used3[30];

// n번째 행에 퀸을 하나 놓아야 함.
void solve(int n) {
    if(n == N) {
        cnt++;
        return;
    }
    for(int j = 0; j < N; j++) {
        // 세로, 기울기 양수, 기울기 음수 인곳에 퀸이 있으면.
        if(used[j] || used2[n+j] || used3[n-j+N-1]) continue;
        used[j] = used2[n+j] = used3[n-j+N-1] = true;
        solve(n+1);
        used[j] = used2[n+j] = used3[n-j+N-1] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    solve(0);
    cout << cnt;
    return 0;
}