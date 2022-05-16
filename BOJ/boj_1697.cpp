#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[100001];
queue<int> Q;   //index가 저장될거밍.
int N, K;

int solve() {
    board[N] = 1;
    Q.push(N);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == K) return board[K] - 1;
        for(int nxt : {cur-1, cur+1, cur*2}) {
            if(nxt >= 0 && nxt <= 100000) {
                if(board[nxt] == 0) {
                    board[nxt] = board[cur] + 1;
                    Q.push(nxt);
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    cout << solve();
    return 0;
}