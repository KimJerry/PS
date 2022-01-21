#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> vec;

void solve(int len) {
    if(len == M) {
        for(auto e : vec) cout << e << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++) {
        vec.push_back(i);
        solve(len+1);
        vec.pop_back();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M;
    solve(0);
    return 0;
}