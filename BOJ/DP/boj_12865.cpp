#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[100005];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V;
        arr[W] = V;
    }
    int res = 0;
    for(int i = 1; i <= K; i++) {
        for(int j = 1; j <= i/2; j++) {
            if((i-j) != j) arr[i] = max(arr[i], arr[i-j] + arr[j]);
            res = max(arr[i], res);
        } 
    }
    for(int i = 1; i <= K; i++) cout << arr[i] << '\n';
    cout << res;
    return 0; 
}// 다시풀어야함./