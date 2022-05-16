#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define X first
#define Y second

int N, M;
string board[1005];
int dist[1005][1005];
bool check[1005][1005];
queue< pair<int, int> > Q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    Q.push({0, 0});
    dist[0][0] = 1;
    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            else if(board[nx][ny] == '1') {
                if(check[cur.X][cur.Y]) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                check[nx][ny] = true;
                Q.push({nx, ny});
            }
            else if(board[nx][ny] == '0') {
                if(nx == N-1 && ny == M-1 && dist[nx][ny] != 0) continue;
                else if(dist[nx][ny] != 0) {
                    if(check[nx][ny] && !check[cur.X][cur.Y]) {
                        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        check[nx][ny] = false;
                        Q.push({nx, ny});
                    }
                }
                else {
                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    check[nx][ny] = check[cur.X][cur.Y];
                    Q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> board[i];
    solve();
    if(dist[N-1][M-1] == 0) cout << -1 << '\n';
    else cout << dist[N-1][M-1] << '\n';
    return 0;
}