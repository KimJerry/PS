#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<int> picked;

void solve(int depth) {
    if(depth == M) {
        for(int& e : picked) cout << arr[e] << ' ';
        cout << '\n';
        return;
    }
    int next = 0;
    for(int i = next; i < N; i++) {
        if(!picked.empty() && picked.back() == i) i++;
        if(i == N) continue;
        picked.push_back(i);
        solve(depth+1);
        picked.pop_back();    
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    solve(0);
    return 0;
}