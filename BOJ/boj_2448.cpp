#include <iostream>
using namespace std;

int N;
char board[4000][8000];

void solve(int height, int x1, int y1) {
    if(height == 3) {
        board[x1][y1] = '*';
        board[x1+1][y1-1] = board[x1+1][y1+1] = '*';
        board[x1+2][y1-2] = board[x1+2][y1-1] = board[x1+2][y1]
        = board[x1+2][y1+1] = board[x1+2][y1+2] = '*';
        return;
    }
    solve(height/2, x1, y1);
    solve(height/2, x1+(height/2), y1-(height/2));
    solve(height/2, x1+(height/2), y1+(height/2));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    solve(N, 0, N-1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2*N-1; j++) {
            if(board[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}