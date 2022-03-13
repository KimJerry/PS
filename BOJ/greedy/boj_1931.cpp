#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> arr[100005];
int N;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) 
        cin >> arr[i].second >> arr[i].first;
    sort(arr, arr+N);
    int res = 0, t = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i].second >= t) {
            t = arr[i].first;
            res++;
        }
    }
    cout << res;
    return 0;
}