#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
typedef pair<int, int> pi;

int cnt;
int V, E;
vector<int> adj[10001];
vector<int> trans[10001];
vector<int> scc[10001];
stack<int> S;

bool visited[10001];

void dfsFirst(int cur)
{
    visited[cur] = true;

    for (int next : adj[cur])
        if (!visited[next])
            dfsFirst(next);

    S.push(cur);
}

void dfsSecond(int cur, int idx)
{
    visited[cur] = true;

    for (int next : trans[cur])
        if (!visited[next])
            dfsSecond(next, idx);

    scc[idx].push_back(cur);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E;

    int a, b;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        trans[b].push_back(a);
    }

    for (int i = 1; i <= V; i++)
        if (!visited[i])
            dfsFirst(i);

    memset(visited, false, sizeof(visited));

    while (!S.empty())
    {
        int leader;
        do
        {
            leader = S.top();
            S.pop();
        } while (visited[leader] && !S.empty());
        if (visited[leader])
            continue;
        dfsSecond(leader, cnt);
        sort(scc[cnt].begin(), scc[cnt].end(), less<>());
        cnt++;
    }

    cout << cnt << '\n';

    sort(scc, scc + cnt);
    for (int i = 0; i < cnt; i++)
    {
        for (int e : scc[i])
            cout << e << ' ';
        cout << -1 << '\n';
    }
    return 0;
}