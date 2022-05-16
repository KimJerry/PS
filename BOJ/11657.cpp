#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct edge
{
    int a;
    int b;
    int weight;
} edge;

const long long INF = 1e17;

queue<int> Q;
vector<edge> edges;
long long dist[501];
bool visited[501];
int N, M;

int solve(int start)
{
    fill_n(dist, 501, INF);
    dist[start] = 0;

    for (int i = 1; i <= N - 1; i++)
    {
        for (edge e : edges)
        {
            if (dist[e.a] != INF)
                dist[e.b] = min(dist[e.b], dist[e.a] + e.weight);
        }
    }

    // check negative cycle.
    for (edge e : edges)

        if (dist[e.b] > dist[e.a] + e.weight && dist[e.a] != INF)
            return -1;
    return 1;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        edge newEdge = {a, b, weight};
        edges.push_back(newEdge);
    }
    int neg = solve(1);
    if (neg == -1)
        cout << -1;
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (dist[i] == INF)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }
    return 0;
}