#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string str = "[1,2,3,4]";
    str = str.substr(1, str.length() -2);
    cout << str << '\n';
    int prev = 0;
    int cur = 0;
    vector<string> x;
    x.clear();
    cur = str.find(',');
    while(cur != string::npos) {
        string substring = str.substr(prev, cur-prev);
        cout << substring <<'\n';
        prev = cur + 1;
        cur = str.find(',', prev);
    }
    cout << str.substr(prev, -1-prev);
    return 0;
}