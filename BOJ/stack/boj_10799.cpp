#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    stack<char> S;
    int res = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(') S.push('(');
        else {
            // laser.
            if(str[i-1] == '(') {
                S.pop();
                res += S.size();
            }
            // end of the pipe.
            else {
                S.pop();
                res++;
            }
        }
    }
    cout << res << '\n';
    return 0;
}