#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int N;
int board[301][301];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1 ,-2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int solve(int i, int j, int k, int l) {
    queue<pii> Q;
    board[i][j] = 1;
    Q.push({i, j});
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        if(cur.X == k && cur.Y == l) return board[cur.X][cur.Y] -1;
        for(int i = 0; i < 8; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(board[nx][ny] != 0) continue;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC, i, j, k ,l;
    cin >> TC;
    while(TC--) {
        cin >> N;
        cin >> i >> j >> k >> l;
        int res = solve(i, j, k, l);
        cout << res << '\n';
        memset(board, 0, sizeof(board));
    }
    return 0;
}