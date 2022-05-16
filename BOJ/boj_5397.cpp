#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while(TC--) {
        string init;
        cin >> init;
        list<char> L;
        list<char>::iterator cursor = L.begin();
        for(int i = 0; i < init.size(); i++) {
            if(init[i] == '<') {
                if(cursor != L.begin()) cursor--;
            }
            else if(init[i] == '>') {
                if(cursor != L.end()) cursor++;
            }
            else if(init[i] == '-') {
                if(cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            // 비밀번호.
            else {
                L.insert(cursor, init[i]);
            }
        }
        for(list<char>::iterator i = L.begin(); i != L.end(); i++) cout << *i;
        cout << '\n';
    }
    return 0;
}