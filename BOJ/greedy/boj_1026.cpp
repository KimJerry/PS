#include <iostream>
#include <algorithm>
using namespace std;

int A[51], B[51], N;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    sort(A, A+N);
    sort(B, B+N, cmp);
    int res = 0;
    for(int i = 0; i < N; i++) res += A[i]*B[i];
    cout << res;
    return 0;
}