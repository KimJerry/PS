#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    string str;
    while(TC--) {
        stack<char> S;
        bool isVPS = true;
        cin >> str;
        for(char s : str) {
            if(s == '(') S.push('(');
            else {
                if(!S.empty()) S.pop();
                else isVPS = false;
            }
        }
        if(S.empty() && isVPS) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}