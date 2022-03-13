#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
void solve(int depth) {
    if(depth == M) {
        for(auto e : arr) cout << e << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++) {
        if(arr.size() != 0 && arr.back() > i) i = arr.back();
        arr.push_back(i);
        solve(depth+1);
        arr.pop_back();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M;
    solve(0);
    return 0;
}