#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int arr[51];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    cout << arr[0] * arr[N - 1];
    return 0;
}