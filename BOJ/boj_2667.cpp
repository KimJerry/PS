#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int N;
int board[26][26];
bool vis[26][26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<pii> Q;
vector<int> res;

void bfs(int i, int j) {
    vis[i][j] = true;
    Q.push({i, j});
    int cnt = 0;
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        cnt++;
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(vis[nx][ny] || board[nx][ny] == 0) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    res.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < N; j++) {
            board[i][j] = temp[j] - '0';
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 1 && !vis[i][j]) {
                bfs(i, j);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(int e : res) cout << e << '\n';
    return 0;
}