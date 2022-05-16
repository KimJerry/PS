/**
 * 학번: 12181679
 * 이름: 정기은
 * 학과: 컴퓨터공학과
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef pair<int, int> pi;

int V, E;
vector<pi> adj[50001];    // 정방향 그래프
vector<pi> trans[50001];  // 역방향 그래프
stack<int> S;             // 스택
bool visited[50001];      // 방문 체크용
pi follower[50001];       // 팔로워를 저장하는 배열
int followerTrans[50001]; // 역방향 그래프 팔로워 계산용
int leaderArr[50001];     // leader 저장하는 배열

// 첫 번째 dfs.
void dfsFirst(int cur)
{
    visited[cur] = true; // 방문 처리.

    // 이미 그래프를 정렬해서 순서대로 dfs 하면 됨.
    for (pi next : adj[cur])
        if (!visited[next.second])
            dfsFirst(next.second);

    // finish 되었으므로 stack에 저장하고 출력.
    S.push(cur);
    cout << cur << ' ';
}

// 두 번째 dfs.
void dfsSecond(int cur, int leader)
{
    visited[cur] = true; // 방문 처리.

    // 이미 그래프를 정렬해서 순서대로 dfs 하면 됨.
    for (pi next : trans[cur])
        if (!visited[next.second])
            dfsSecond(next.second, leader);

    // finish-> SCC를 완성해나가는 과정. leader를 기록한다.
    leaderArr[cur] = leader;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력.
    cin >> V >> E;
    int a, b;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        adj[a].push_back({0, b});   // 정방향 그래프 생성.  {팔로워 수, 사용자 번호}인 pair 저장.
        trans[b].push_back({0, a}); // 역방향 그래프 생성.  {팔로워 수, 사용자 번호}인 pair 저장.
        follower[b].first--;        // 정렬을 편하게 하기 위해 팔로워 수를 음수로 센다.
        follower[b].second = b;     // 사용자 번호를 저장.
        followerTrans[a]++;         // 역방향 그래프는 팔로워 수만 저장.
    }

    // 팔로워가 없는 사용자는 {0, 사용자 번호}로 추가해준다. 나중을 위해.
    for (int i = 1; i <= V; i++)
    {
        if (follower[i].second == 0)
            follower[i].second = i;
    }

    // 각 노드에 달린 간선들을 정렬한다.
    for (int i = 1; i <= V; i++)
    {
        // 정방향 그래프에 팔로워 수를 추가한다.
        for (pi &e : adj[i])
            e.first = follower[e.second].first;

        // 역방향 그래프에 팔로워 수를 추가한다.
        for (pi &e : trans[i])
            e.first = -followerTrans[e.second];

        // 간선들을 정렬한다.
        // 팔로워 수가 많은 순서대로, 팔로워가 같으면 사용자 번호가 낮은 순서대로 정렬된다.
        sort(adj[i].begin(), adj[i].end(), less<>());
        sort(trans[i].begin(), trans[i].end(), less<>());
    }

    // 팔로워 수를 저장한 pair들을 정렬한다.
    sort(follower + 1, follower + V + 1, less<>());

    // 첫 번째 dfs.
    for (int i = 1; i <= V; i++)
    {
        if (!visited[follower[i].second])
            dfsFirst(follower[i].second);
    }

    // 방문기록 초기화.
    for (int i = 0; i < 50001; i++)
        visited[i] = false;

    // 두 번째 dfs.
    while (!S.empty())
    {
        int leader;
        // 한번은 무조건 뽑는다.
        // 만약 이미 탐색한 정점이면 버리고 다음 정점을 뽑아서 체크한다.
        do
        {
            leader = S.top();
            S.pop();
        } while (visited[leader] && !S.empty());

        // 스택에 마지막으로 남아 있던 것이 이미 탐색한 정점인 경우 체크.
        if (visited[leader])
            continue;
        dfsSecond(leader, leader);
    }

    // 사용자 별 leader 출력.
    cout << '\n';
    for (int i = 1; i <= V; i++)
        cout << leaderArr[i] << ' ';

    return 0;
}