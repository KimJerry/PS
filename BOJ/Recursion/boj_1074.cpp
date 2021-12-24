#include <iostream>
using namespace std;

int cnt = -1;
int N, r, c;
void solve(int n, int i, int j) {
    if(n == 0) {
        cnt++;
        if(r == i && c == j) cout << cnt;
        return;
    }
    int len = 1 << (n-1); 
    // 2사분면.
    if(r <= i+len-1 && c <= j+len-1) {
        solve(n-1, i, j);
    }
    // 1사분면.
    else if(r <= i+len-1 && c >= j+len) {
        cnt += len*len;
        solve(n-1, i, j + len);
    }
    // 3사분면.
    else if(r >= i+len && c <= j+len-1) {
        cnt += len*len*2;
        solve(n-1, i + len, j);
    }
    // 4사분면.
    else if(r >= i+len-1 && c >= j+len-1) {
        cnt += len*len*3;
        solve(n-1, i + len, j + len);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> r >> c;
    solve(N, 0, 0);
    return 0;
}