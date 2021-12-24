#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int N, M, K;
int board[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pii> Q;

int bfs(int i, int j) {
    int mx = 0;
    board[i][j] = 1;
    Q.push({i, j});
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        // 큐에서 pop해줄 때마다 영역의 넓이를 1씩 증가.
        mx++;
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(board[nx][ny] != 0) continue;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 입력.
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j <= y2-1; j++) {
            for(int k = x1; k <= x2-1; k++) {
                board[j][k] = -1;
            }
        }
    }
    // 영역이 개수, 넓이 계산.
    vector<int> areas;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // 사각형은 무조건 -1로 채워져있고, 방문하지 않은 영역은 무조건 0.
            if(board[i][j] == 0) {
                int area = bfs(i, j);
                // 영역의 넓이를 벡터에 보관.
                areas.push_back(area);
                cnt++;
            }
        }
    }
    // 출력.
    sort(areas.begin(), areas.end());
    cout << cnt << '\n';
    for(auto e : areas) cout << e << ' ';
    return 0;
}