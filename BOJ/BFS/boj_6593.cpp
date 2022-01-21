#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

const int INF = 1e9;

int L, N, M;
int board[31][31][31];
queue< tuple<int, int, int> > Q;
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int solve() {
    while(!Q.empty()) {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        int z, x, y;
        tie(z, x, y) = cur;
        for(int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nz < 0 || nx < 0 || ny < 0 || nz >= L || nx >= N || ny >= M) continue;
            if(board[nz][nx][ny] < 0) continue;
            if(board[nz][nx][ny] == INF) {
                return board[z][x][y] + 1;
            }
            if(board[nz][nx][ny] != 0) continue;
            board[nz][nx][ny] = board[z][x][y] + 1;
            Q.push(make_tuple(nz, nx, ny));
        }
    }
    return -1;
}

void init() {
    while(!Q.empty()) Q.pop();
    memset(board, 0, sizeof(board));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    while(1) {
        cin >> L >> N >> M;
        if(L == 0) break;
        // input.
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < N; j++) {
                string arr;
                cin >> arr;
                for(int k = 0; k < M; k++) {
                    if(arr[k] == '#') board[i][j][k] = -1;
                    else if(arr[k] == 'S') Q.push(make_tuple(i, j, k));
                    else if(arr[k] == 'E') board[i][j][k] = INF;
                }
            }
        }
        int ans = solve();
        if(ans < 0) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
        init();
    }
    
    return 0;
}