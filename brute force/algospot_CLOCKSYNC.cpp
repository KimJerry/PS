#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS + 1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};



// 모든 시계가 12시를 가리키고 있는지 확인한다.
bool areAligned(const vector<int>& clocks) {
    for(int i = 0; i < 16; i++) {
        if(clocks[i] != 12) return false;
    }
    return true;
}

// swtch 번 스위치를 누른다.
void push(vector<int>& clocks, int swtch) {
    for(int clock = 0; clock < CLOCKS; ++clock) {
        if(linked[swtch][clock] == 'x') {
            clocks[clock] += 3;
            if(clocks[clock] == 15) clocks[clock] = 3;
        }
    }
}

int solve(vector<int>& clocks, int swtch) {
    if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

    int ret = INF;
    for(int cnt = 0; cnt < 4; ++cnt) {
        ret = min(ret, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    cin >> C;
    while(C--) {
        vector<int> arr;
        for(int i = 0; i < 16; i++) {
            int a;
            cin >> a;
            arr.push_back(a);
        }
        int res = solve(arr, 0);
        res = res == INF ? -1 : res;
        cout << res << '\n';
    }
    return 0;
}