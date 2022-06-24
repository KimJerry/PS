#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ALL(v) v.begin(), v.end()

bool visited[100001];
int cycleFind[100001];
int cnt;
vi arr(100001);

void dfs(int n, int start) {
  if (cycleFind[n] == -start) { // base case 1)의 상황.
    return;
  } else if (visited[n] && cycleFind[n] != start) { // base case 2)의 상황.
    return;
    // 3) 의 상황.
  } else if (visited[n] && cycleFind[n] == start) {
    cycleFind[n] = -start;
    cnt++;
    dfs(arr[n], start);
  } else {
    visited[n] = true;
    cycleFind[n] = start;
    dfs(arr[n], start);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> arr[i];
    for (int i = 1; i <= n; i++) {
      if (!visited[i])
        dfs(i, i);
    }
    cout << n - cnt << '\n';

    cnt = 0;
    memset(visited, false, sizeof(visited));
    memset(cycleFind, 0, sizeof(cycleFind));
  }
  return 0;
}
