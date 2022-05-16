#include <iostream>
#include <vector>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int N, M;
int board[9][9];
int check[9][9];
int res;
// CCTV의 좌표를 저장하는 벡터.
vector<pii> coordinates;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// 첫 번째 CCTV가 보는 구역을 delta(true or false)로 바꿈.
void firstCCTV(int x, int y, int direction, int delta) {
    int iter = 0;
    while(++iter) {
        int nx = dx[direction] * iter + x;
        int ny = dy[direction] * iter + y;
        if(nx < 0 || ny < 0 || nx > N || ny > M) break;
        if(board[nx][ny] == 6) break;
        check[nx][ny] += delta;
    }
}

void CCTV(int x, int y, int direction, int delta, int whatCCTV) {
    if(whatCCTV == 1) {
        firstCCTV(x, y, direction, delta);
    }
    if(whatCCTV == 2) {
        firstCCTV(x, y, direction, delta);
        firstCCTV(x, y, (direction+2) % 4, delta);
    }
    if(whatCCTV == 3) {
        firstCCTV(x, y, direction, delta);
        firstCCTV(x, y, (direction+1) % 4, delta);
    }
    if(whatCCTV == 4) {
        firstCCTV(x, y, direction, delta);
        firstCCTV(x, y, (direction+1) % 4, delta);
        firstCCTV(x, y, (direction+3) % 4, delta);
    }
    if(whatCCTV == 5) {
        for(int i = 0; i < 4; i++) {
            firstCCTV(x, y, i, delta);
        }
    }
}

void dfs(int depth) {
    // depth가 CCTV의 개수와 같을 경우 0의 개수 세어주고 리턴.
    if(depth == coordinates.size()) {
        int numberOfZero = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(check[i][j] == 0 && board[i][j] == 0) numberOfZero++;
            }
        }
        // 0의 개수 업데이트.
        if(res > numberOfZero) res = numberOfZero;
        return;
    }
    pii cur = coordinates[depth];
    int curCCTV = board[cur.X][cur.Y];
    // 왼쪽, 아래, 오르쪽, 위쪽 4가지 방향.
    for(int i = 0; i < 4; i++) {
        CCTV(cur.X, cur.Y, i, 1, curCCTV);
        dfs(depth+1);
        CCTV(cur.X, cur.Y, i, -1, curCCTV);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    res = N * M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] != 0) {
                if(board[i][j] != 6) coordinates.push_back({i, j});
            }
        }
    }
    dfs(0);
    cout << res;
    return 0;
}