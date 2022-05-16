#include <iostream>
using namespace std;

int arr[2][6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int S, Y;
        cin >> S >> Y;
        arr[S][Y-1]++;
    }
    int sum = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++) {
            arr[i][j] = (arr[i][j] + K - 1) / K;
            sum += arr[i][j];
        }
    }
    cout << sum << '\n';
    return 0;
}