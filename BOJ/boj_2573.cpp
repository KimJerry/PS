#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> pii;

int N, M, cnt = 0, ans = 0;

int board[305][305];
bool visited[305][305];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pii> Q, tempQ;

// 빙산 녹이기.
void melting()
{
    while (!Q.empty())
    {
        pii cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (board[nx][ny] == 0 && board[cur.X][cur.Y] > 0)
                board[cur.X][cur.Y]--;

            if (board[cur.X][cur.Y] == 0)
                board[cur.X][cur.Y] = -1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == -1)
                board[i][j] = 0;
        }
    }
}

void bfs(int x1, int y1)
{
    visited[x1][y1] = true;
    tempQ.push({x1, y1});
    Q.push({x1, y1});
    while (!tempQ.empty())
    {
        pii cur = tempQ.front();
        tempQ.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (board[nx][ny] != 0 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                tempQ.push({nx, ny});
                Q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j])
                Q.push({i, j});
        }
    }

    while (cnt < 2 && !Q.empty())
    {
        melting();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] && !visited[i][j])
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        ans++;
        if (cnt >= 2)
            break;

        cnt = 0;
        memset(visited, false, sizeof(visited));
    }
    if (!Q.empty())
        cout << ans;
    else
        cout << 0;

    return 0;
}