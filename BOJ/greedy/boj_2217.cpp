#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005], N;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N);
    int res = arr[N-1];
    for(int i = N-2; i >= 0; i--) {
        if(arr[i]*(N-i) > res) res = arr[i] * (N-i);
    }
    cout << res;
    return 0;
}