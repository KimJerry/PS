#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int K;
    cin >> K;
    stack<int> S;
    while(K--) {
        int num;
        cin >> num;
        if(num == 0) S.pop();
        else S.push(num);
    }
    int res = 0;
    while(!S.empty()) {
        res += S.top();
        S.pop();
    }
    cout << res << '\n';
    return 0;
}