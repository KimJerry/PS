#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    while(getline(cin, str)) {
        stack<char> S;
        bool balanced = true;
        if(str.compare(".") == 0) break;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '(' || str[i] == '[') S.push(str[i]);
            else if(str[i] == ')') {
                if(S.empty() || S.top() != '(') {
                    balanced = false;
                    break;
                }
                S.pop();
            }
            else if(str[i] == ']') {
                if(S.empty() || S.top() != '[') {
                    balanced = false;
                    break;
                }
                S.pop();
            }
        }
        if(balanced && S.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}