#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first;
#define Y second;

int board[501][501];
int vis[501][501];
int n, m;
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};
int mx = 0, num = 0;
queue<pair<int,int> > Q;

void bfs(int i, int j) {
    vis[i][j] = true;
    Q.push({i, j});
    int temp = 0;
    while(!Q.empty()) {
        temp++;
        pair<int, int> cur = Q.front(); Q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = dx[k] + cur.X;
            int ny = dy[k] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] == 0) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    mx = mx < temp ? temp : mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] || board[i][j] == 0) continue;
            bfs(i, j);
            num++;
        }
    }
    cout << num << '\n' << mx;
    return 0;
}