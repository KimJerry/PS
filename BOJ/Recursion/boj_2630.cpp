#include <iostream>
using namespace std;

int N;
int board[129][129];
int res[2];

void solve(int x1, int y1, int n) {
    if(n == 1) {
        res[board[x1][y1]]++;
        return;
    }
    // 사각형이 모두 같은 수인지 탐색.
    int temp = board[x1][y1];
    bool differ = false;
    for(int i = x1; i < x1+n; i++) {
        for(int j = y1; j < y1+n; j++) {
            if(board[i][j] != temp) differ = true;
        }
    }
    if(!differ) res[temp]++;
    else {
        solve(x1, y1, n/2);
        solve(x1, y1+n/2, n/2);
        solve(x1+n/2, y1, n/2);
        solve(x1+n/2, y1+n/2, n/2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    solve(0, 0, N);
    cout << res[0] << '\n' << res[1];
    return 0;
}