#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define X first
#define Y second

typedef pair<int, int> pii;

int N, M, K;
int board[51][51];
bool vis[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pii> Q;

void bfs(int i, int j) {
    vis[i][j] = true;
    Q.push({i, j});
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(vis[nx][ny] || board[nx][ny] == 0) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while(TC--) {
        cin >> M >> N >> K;
        for(int i = 0; i < K; i++) {
            int x, y;
            cin >> y >> x;
            board[x][y] = 1;
        }
        int ans = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(!vis[i][j] && board[i][j] == 1) {
                    bfs(i, j);
                    ans++;
                }   
            }
        }
        memset(vis, false, sizeof(vis));
        memset(board, 0, sizeof(board));
        cout << ans << '\n';
    }
    return 0;
}