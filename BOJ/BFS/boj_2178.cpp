#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second

typedef pair<int, int> pii;

int N, M;
int board[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pii> Q;

void solve() {
    vis[1][1] = true;
    Q.push({1, 1});
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx > N || ny > M) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = true;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        string temp;
        cin >> temp;
        for(int j = 1; j <= M; j++) board[i][j] = temp[j-1] - '0';
    }
    solve();
    cout << board[N][M];
    return 0;
}