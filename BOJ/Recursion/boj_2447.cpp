#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int digit = 999999;

void solve(int n) {
    for(int i = 1; i <= 54; i++) {
        int temp = n - i;
        if(temp <= 0) return;
        
        int p = 1000000;
        int res = temp;
        while(temp != 0) {
            res += temp / p;
            temp %= p;
            p /= 10;
        }
        if(res == n) {
            digit = min(digit, res - i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    solve(N);
    if(digit == 999999) digit = 0;
    cout << digit << endl;
    return 0;
}