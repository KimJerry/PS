#include <iostream>
using namespace std;

int arr[202];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr[temp+100]++;
    }
    int v;
    cin >> v;
    cout << arr[v+100] << '\n';
    return 0;
}