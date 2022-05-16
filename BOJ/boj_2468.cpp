#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int N;
int board[101][101];
bool vis[101][101];
queue<pii> Q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void solve(int x1, int y1, int height) {
    vis[x1][y1] = true;
    Q.push({x1, y1});
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(vis[nx][ny] || board[nx][ny] <= height) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    int max = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            max = max < board[i][j] ? board[i][j] : max;
        }
    }
    int ans = 0;
    for(int i = 0; i <= max; i++) {
        int temp = 0;
        for(int x1 = 0; x1 < N; x1++) {
            for(int y1 = 0; y1 < N; y1++) {
                if(!vis[x1][y1] && board[x1][y1] > i) {
                    solve(x1, y1, i);
                    temp++;
                }
            }
        }
        ans = ans < temp ? temp : ans;
        memset(vis, false, sizeof(vis));
    }
    cout << ans;
    return 0;
}