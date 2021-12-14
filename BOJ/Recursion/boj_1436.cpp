#include <iostream>
using namespace std;

bool isContinuous(int n) {
    int p = 1e7;
    int cnt = 0;
    while(n != 0) {
        int temp = n / p;
        if(temp == 6) cnt++;
        if(cnt == 3) return true;
        if(temp != 6) cnt = 0;
        n %= p;
        p /= 10;
    }
    return false;
}

void solve(int n) {
    int cnt = 0;
    for(int i = 1; i <= 1e7; i++) {
        if(isContinuous(i)) {
            cnt++;
            if(cnt == n) {
                cout << i << '\n';
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    solve(N);
    return 0;
}