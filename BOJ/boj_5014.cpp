#include <iostream>
#include <queue>
using namespace std;

const int NUM = 1e6+1;
int F, S, G, U, D;
int res[NUM];
queue<int> Q;

int solve(int i) {
    res[i] = 1;
    Q.push(i);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        // 목적지에 도착하면 값을 바로 리턴해줌. 시작지점을 1로했으니 -1 한 값을 리턴함.
        if(cur == G) return res[G]-1;
        for(int nxt : {U, -D}) {
            int newindex = cur + nxt;
            if(newindex <= 0 || newindex > F) continue;
            if(res[newindex] != 0) continue;
            res[newindex] = res[cur]+1;
            Q.push(newindex);
        }
    }
    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> F >> S >> G >> U >> D;
    int ans = solve(S);
    if(ans == -1) cout << "use the stairs\n";
    else cout << ans << '\n';
    return 0;
}