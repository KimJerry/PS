#include <iostream>
using namespace std;

char board[6666][6666];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void solve(int x1, int y1, int len) {
    if(len == 1) {
        board[x1][y1] = '*';
        return;
    }
    for(int i = 0; i < 8; i++) {
        int nx = dx[i]*len/3 + x1;
        int ny = dy[i]*len/3 + y1;
        solve(nx, ny, len/3);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int N;
    cin >> N;
    solve(N/2, N/2, N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] != '*') cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }
    return 0;
}