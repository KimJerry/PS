#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> vec;

void solve(int n, int k) {
    if(n == k) {
        for(int e : vec) cout << e << ' ';
        cout << '\n';
        return;
    }
    int nxt;
    if(vec.empty()) nxt = 1;
    else nxt = vec.back() + 1;
    for(int i = nxt; i <= N; i++) {
        vec.push_back(i);
        solve(n+1, k);
        vec.pop_back();
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M;
    solve(0, M);
    return 0;
}