#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int arr1[26];
int arr2[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string temp1, temp2;
    cin >> temp1 >> temp2;
    for(int i = 0; i < temp1.size(); i++) arr1[temp1[i]-'a']++;
    for(int i = 0; i < temp2.size(); i++) arr2[temp2[i]-'a']++;
    int res = 0;
    for(int i = 0; i < 26; i++) res += abs(arr1[i]-arr2[i]);
    cout << res << '\n';
    return 0;
}