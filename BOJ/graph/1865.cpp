#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct edge
{
    int a;
    int b;
    int weight;
} edge;
long long const INF = 1e17;

int N, M, W;
vector<edge> edges;
long long dist[501];

int solve()
{
    fill_n(dist, 501, INF);

    for (int i = 1; i <= N - 1; i++)
    {
        for (edge e : edges)
            dist[e.b] = min(dist[e.b], dist[e.a] + e.weight);
    }
    for (edge e : edges)
    {
        if (dist[e.b] > dist[e.a] + e.weight)
            return -1;
    }

    return 1;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> W;
        int a, b, weight;
        for (int i = 0; i < M; i++)
        {
            cin >> a >> b >> weight;
            edge newEdge = {a, b, weight};
            edges.push_back(newEdge);
            edge newEdge2 = {b, a, weight};
            edges.push_back(newEdge2);
        }
        for (int i = 0; i < W; i++)
        {
            cin >> a >> b >> weight;
            edge newEdge = {a, b, -weight};
            edges.push_back(newEdge);
        }
        int neg = solve();
        if (neg == -1)
            cout << "YES\n";
        else
            cout << "NO\n";
        edges.clear();
    }

    return 0;
}