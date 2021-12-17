#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while(TC--) {
        deque<int> D;
        string op, arr;
        cin >> op;
        int mode = 1, t;
        cin >> t;
        cin >> arr;
        arr = arr.substr(1, arr.length() - 2);
        // , 를 기준으로 나누고 덱에 넣어주기.
        int cur = 0, prev = 0;
        cur = arr.find(',', 0);
        while(cur != string::npos) {
            string substring = arr.substr(prev, cur - prev);
            int temp = stoi(substring);
            D.push_back(temp);
            prev = cur + 1;
            cur = arr.find(',', prev);
        }
        if(arr.size() != 0) {
            string substring = arr.substr(prev, -1 - prev);
            D.push_back(stoi(substring));
        }
        //
        bool error = false;
        for(int i = 0; i < op.size(); i++) {
            if(op[i] == 'R') mode *= -1;
            else {
                if(D.empty()) {
                    error = true;
                    break;
                }
                else if(mode == 1) D.pop_front();
                else D.pop_back();
            }
        }
        if(error) cout << "error\n";
        else {
            cout << '[';
            if(!D.empty()) {
                if(mode == 1) {
                    for(int i = 0; i < D.size(); i++) {
                        cout << D[i];
                        if(i+1 == D.size()) continue;
                        cout << ','; 
                    }
                }
                else {
                    for(int i = D.size() - 1; i >= 0; i--) {
                        cout << D[i];
                        if(i == 0) continue;
                        cout << ',';
                    }
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}