#include <iostream>
using namespace std;

int res[500001];
int arr[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    arr[0] = -1;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        int index = i-1;
        while(index != 0) {
            if(arr[index] > arr[i]) {
                res[i] = index;
                break;
            }
            index = res[index];
        }
        if(index == 0) res[i] = 0;
    }
    for(int i = 1; i <= N; i++) cout << res[i] << ' ';
    return 0;
}