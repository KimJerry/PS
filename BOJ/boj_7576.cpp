#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second

typedef pair<int, int> pii;

int N, M;
int board[1001][1001];
bool vis[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pii> Q;

void solve() {
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(vis[nx][ny] || board[nx][ny] != 0) continue;
            vis[nx][ny] = true;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                vis[i][j] = true;
                Q.push({i, j});
            }
        }
    }
    solve();
    int mx = 0;
    bool zero = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 0) {
                zero = true;
                break;
            }
            mx = mx < board[i][j] ? board[i][j] : mx;
        }
    }
    if(zero) cout << -1;
    else if(mx == 1) cout << 0;
    else cout << mx - 1;
    return 0;
}