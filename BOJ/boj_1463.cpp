#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000005];
int N;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for(int i = 2; i <= N; i++) {
        arr[i] = arr[i-1]+1;
        if(i % 3 == 0) arr[i] = min(arr[i], arr[i/3]+1);
        if(i % 2 == 0) arr[i] = min(arr[i], arr[i/2]+1);
    }
    cout << arr[N];
    return 0;
}