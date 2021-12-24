#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int N, M;
int fire_board[1001][1001];
int human_board[1001][1001];
queue<pii> fireQ, humanQ;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1 ,0};

void fireMap() {
    while(!fireQ.empty()) {
        pii cur = fireQ.front(); fireQ.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            // 불은 빈칸으로만 번진다.
            if(fire_board[nx][ny] != 1e9) continue;
            fire_board[nx][ny] = fire_board[cur.X][cur.Y] + 1;
            fireQ.push({nx, ny});
        }
    }
}

int humanMap() {
    while(!humanQ.empty()) {
        pii cur = humanQ.front(); humanQ.pop();
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            // 탈출할 수 있느 경우.
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) return human_board[cur.X][cur.Y];
            // 벽이 없고, 불지도보다 더 빠르게 갈 수 있을 때.
            if(human_board[nx][ny] == 0 && human_board[cur.X][cur.Y]+1 < fire_board[nx][ny]) {
                human_board[nx][ny] = human_board[cur.X][cur.Y] + 1;
                humanQ.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while(TC--) {
        cin >> M >> N;
        // 보드 생성하기.
        for(int i = 0; i < N; i++) {
            string str;
            cin >> str;
            for(int j = 0; j < M; j++) {
                fire_board[i][j] = 1e9;
                if(str[j] == '#') {
                    human_board[i][j] = -1;
                    fire_board[i][j] = -1;
                }
                else if(str[j] == '*') {
                    fire_board[i][j] = 1;
                    fireQ.push({i, j});
                }
                else if(str[j] == '@') {
                    human_board[i][j] = 1;
                    humanQ.push({i, j});
                }
            }
        }
        // 불지도 생성.
        fireMap();
        // 사람지도 생성. 불지도 보다 값이 작아야만 앞으로 나아갈 수 있음.
        int ans = humanMap();
        // -1이면 탈출할 수 없음.
        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
        // init.
        memset(fire_board, 0, sizeof(fire_board));
        memset(human_board, 0, sizeof(human_board));
        // humanQ가 비어있지 않을 수도 있음.
        while(!humanQ.empty()) humanQ.pop();
    }
    return 0;
}