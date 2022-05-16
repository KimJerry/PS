#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    stack<char> S;
    int res = 0, temp = 1;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(') {
            S.push('(');
            temp *= 2;
        }
        else if(str[i] == '[') {
            S.push('[');
            temp *= 3;
        }
        else if(str[i] == ')') {
            if(S.empty() || S.top() == '[') {
                res = 0;
                break;
            }
            if(str[i-1] == '(') {
                res += temp;
            }
            S.pop();
            temp /= 2;
        }
        else if(str[i] == ']') {
            if(S.empty() || S.top() == '(') {
                res = 0;
                break;
            }
            if(str[i-1] == '[') {
                res += temp;
            }
            temp /= 3;
            S.pop();
        }
    }
    if(!S.empty()) res = 0;
    cout << res << '\n';
    return 0;
}