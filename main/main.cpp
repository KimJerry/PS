#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int board[101][101];
int island[101][101];
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<pi> Q;
int N;
queue<pi> Q2;

void bfs(int x, int y, int island_num) {
  Q.push({x, y});
  visited[x][y] = true;
  island[x][y] = island_num;
  while (!Q.empty()) {
    pi cur = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = dx[i] + cur.first;
      int ny = dy[i] + cur.second;
      if (nx < 0 || ny < 0 || nx > N || ny > N)
        continue;
      if (visited[nx][ny])
        continue;
      if (board[nx][ny] == 0) {
        Q2.push({cur.first, cur.second});
        continue;
      }
      island[nx][ny] = island_num;
      visited[nx][ny] = true;
      Q.push({nx, ny});
    }
  }
}

int solve() {
  int ret = 1e9;
  int stage = 0;
  queue<int> tempQ;
  for (int i = 0; i < Q2.size(); i++)
    tempQ.push(1);
  while (!Q2.empty()) {
    pi cur = Q2.front();
    Q2.pop();
    int curStage = tempQ.front();
    tempQ.pop();
    for (int i = 0; i < 4; i++) {
      int nx = dx[i] + cur.first;
      int ny = dy[i] + cur.second;
      if (nx < 0 || ny < 0 || nx > N || ny > N)
        continue;
      if (board[nx][ny] == -1)
        continue;
      if (visited[nx][ny]) {
        if (island[nx][ny] != island[cur.first][cur.second]) {
          if (stage == 0)
            stage = curStage;
          if (board[nx][ny] == board[cur.first][cur.second] &&
              stage == curStage) {
            ret = min(board[nx][ny] * 2, ret);
          } else if (board[nx][ny] != board[cur.first][cur.second] &&
                     stage == curStage) {
            ret = min(board[nx][ny] * 2 - 1, ret);
          }
        }
        continue;
      }
      if (board[nx][ny] == 0) {
        if (board[cur.first][cur.second] == -1) {
          board[nx][ny] = 1;
          island[nx][ny] = island[cur.first][cur.second];
          visited[nx][ny] = true;
          Q2.push({nx, ny});
          tempQ.push(curStage + 1);
        } else {
          board[nx][ny] = board[cur.first][cur.second] + 1;
          island[nx][ny] = island[cur.first][cur.second];
          visited[nx][ny] = true;
          Q2.push({nx, ny});
          tempQ.push(curStage + 1);
        }
      }
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      board[i][j] *= -1;
    }
  }
  int cnt = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j] && board[i][j] != 0) {
        bfs(i, j, cnt);
        cnt++;
      }
    }
  }
  memset(visited, false, sizeof(visited));
  cout << solve();

  return 0;
}
