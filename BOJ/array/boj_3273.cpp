#include <iostream>
using namespace std;

int arr[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, x;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    cin >> x;
    int res = 0;
    for(int i = 0; i < 1000001; i++) {
        if(i > x) break;
        if(arr[i] != 0) {
            if(x-i < 1000000 && arr[x - i] != 0 && x - i > i) res++;
        }
    }
    cout << res << '\n';
    return 0;
}