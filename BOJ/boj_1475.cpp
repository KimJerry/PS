#include <iostream>
#include <string>
using namespace std;

int arr[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string temp;
    cin >> temp;
    for(int i = 0; i < temp.size(); i++) arr[temp[i] - '0']++;
    arr[6] = (arr[6] + arr[9] + 1) / 2;
    arr[9] = 0;
    int max = 0;
    for(int i = 0; i < 10; i++) max = max < arr[i] ? arr[i] : max;
    cout << max << '\n';
    return 0;
}