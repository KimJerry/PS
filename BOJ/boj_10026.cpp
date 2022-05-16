#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
#define X first
#define Y second
#define RED -1
#define GREEN 1
#define BLUE 2
typedef pair<int, int> pii;

int board[101][101];
bool vis[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pii> Q;
int N;
int ans1 = 0, ans2 = 0;

void bfs(int i, int j, int color) {
    vis[i][j] = true;
    Q.push({i, j});
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(vis[nx][ny] || board[nx][ny] != color) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
 }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < N; j++) {
            if(temp[j] == 'R') board[i][j] = RED;
            else if(temp[j] == 'G') board[i][j] = GREEN;
            else if(temp[j] == 'B')  board[i][j] = BLUE;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int color : {RED, GREEN, BLUE}) {
                if(!vis[i][j] && board[i][j] == color) {
                    bfs(i, j, color);
                    ans1++;
                }
            }
        }
    }
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == RED) board[i][j] = GREEN;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int color : {GREEN, BLUE}) {
                if(!vis[i][j] && board[i][j] == color) {
                    bfs(i, j, color);
                    ans2++;
                }
            }
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}