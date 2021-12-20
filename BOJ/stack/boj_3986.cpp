#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    int res = 0;
    while(TC--) {
        string arr;
        cin >> arr;
        stack<char> S;
        for(int i = 0; i < arr.size(); i++) {
            if(S.empty()) S.push(arr[i]);
            else {
                if(S.top() == arr[i]) S.pop();
                else S.push(arr[i]);
            }
        }
        if(S.empty()) res++; 
    }
    cout << res << '\n';
    return 0;
}