#include <iostream>
using namespace std;
typedef long long ll;

int solve(int a, int b, int c) {
    if(b == 1) return a % c;
    ll val = solve(a, b/2, c);
    val = val * val % c;
    if(b % 2 == 0) return val;
    return val * a % c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, C;
    cin >> A >> B >> C;
    cout << solve(A, B, C);
    return 0;
}