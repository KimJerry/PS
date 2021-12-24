#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
#define Z get<0>
#define X get<1>
#define Y get<2>

typedef tuple<int, int, int> tiii;

int N, M, H;
int board[101][101][101];
bool vis[101][101][101];
queue<tiii> Q;
int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0,  0, -1, 1};

void solve() {
    while(!Q.empty()) {
        tiii cur = Q.front(); Q.pop();
        for(int i = 0; i < 6; i++) {
            int nz = dz[i] + Z(cur);
            int nx = dx[i] + X(cur);
            int ny = dy[i] + Y(cur);
            if(nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
            if(vis[nz][nx][ny] || board[nz][nx][ny] != 0) continue;
            vis[nz][nx][ny] = true;
            board[nz][nx][ny] = board[Z(cur)][X(cur)][Y(cur)] + 1;
            Q.push(make_tuple(nz, nx, ny));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N >> H;
    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> board[k][i][j];
                if(board[k][i][j] == 1) {
                    vis[k][i][j] = true;
                    Q.push(make_tuple(k, i, j));
                }
            }
        }
    }
    solve();
    int mx = 0;
    bool zero = false;
    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[k][i][j] == 0) zero = true;
                else mx = mx < board[k][i][j] ? board[k][i][j] : mx;
            }
        }
    }
    if(zero) cout << -1;
    else if(mx == 1) cout << 0;
    else cout << mx - 1;
    return 0;
}