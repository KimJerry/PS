#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
bool used[9];

// n은 앞으로 뽑아야 하는 원소의 개수임.
void solve(vector<int>& arr, int n) {
    if(n == 0) {
        for(int elem : arr) cout << elem << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++) {
        if(!used[i]) {
            arr.push_back(i);
            used[i] = true;
            solve(arr, n-1);
            arr.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    solve(arr, M);
    return 0;
}