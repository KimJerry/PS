#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
#define X first
#define Y second

typedef pair<int, int> pii;

int N, M;
int board[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pii> Q;

int solve() {
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            // J.
            if(board[cur.X][cur.Y] > 0) {
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) return board[cur.X][cur.Y];
                if(board[nx][ny] != 0) continue;
                board[nx][ny] = board[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
            // F.
            else if(board[cur.X][cur.Y] < 0) {
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(board[nx][ny] < 0) continue;
                board[nx][ny] = -2;
                Q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < M; j++) {
            if(temp[j] == '#') board[i][j] = -1;
            else if(temp[j] == 'F') {
                board[i][j] = -2;
                Q.push({i, j});
            }
            else if(temp[j] == 'J') {
                board[i][j] = 1;
                Q.push({i, j});
            }
        }
    }
    int res = solve();
    if(res >= 0) cout << res;
    else cout << "IMPOSSIBLE";
    return 0;
}