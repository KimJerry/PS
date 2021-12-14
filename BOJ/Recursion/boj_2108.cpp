#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input;
vector<int> sorted;

void solve() {
    sort(sorted.begin(), sorted.end());
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        input.push_back(temp);
        sorted.push_back(temp);
    }
    solve();
    return 0;
}