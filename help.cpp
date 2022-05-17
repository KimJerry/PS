#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 300
#define MAX_M 300
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int grid[MAX_N + 1][MAX_M + 1];
bool isVisited[MAX_N + 1][MAX_M + 1];
bool isLand[MAX_N + 1][MAX_M + 1];
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
int N, M;

bool isOcean(int y, int x)
{
    if (0 <= y && y < N && 0 <= x && x < M && grid[y][x] == 0)
        return true;
    return false;
}
bool isIceberg(int y, int x)
{
    if (0 <= y && y < N && 0 <= x && x < M && grid[y][x] > 0)
        return true;
    return false;
}
void dfs(int y, int x)
{
    isVisited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isIceberg(ny, nx) && !isVisited[ny][nx])
            dfs(ny, nx);
    }
}
int countIceberg()
{
    memset(isVisited, false, sizeof isVisited);
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (isIceberg(i, j) && !isVisited[i][j])
            {
                ret++;
                dfs(i, j);
            }
        }
    }
    return ret;
}

void bfs()
{
    queue<ii> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] > 0)
                q.push(make_pair(i, j));
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        if (countIceberg() >= 2)
        {
            cout << cnt << endl;
            return;
        }
        while (sz--)
        {
            ii cur = q.front();
            int y = cur.first;
            int x = cur.second;

            q.pop();
            if (isIceberg(y, x))
            {
                int cntOcean = 0;
                for (int i = 0; i < 4; i++)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (isOcean(ny, nx))
                        cntOcean++;
                }
                if (grid[y][x] > cntOcean)
                {
                    grid[y][x] -= cntOcean;
                    q.push(make_pair(y, x));
                }
                else
                    grid[y][x] = -1;
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                if (grid[i][j] == -1)
                    grid[i][j] = 0;
        }
        cnt++;
    }
    cout << 0 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];
    }
    bfs();
}