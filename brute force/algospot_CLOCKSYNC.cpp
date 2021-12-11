#include <iostream>
#include <vector>
using namespace std;

int clocks[16];
int buttons[10][5] = {
    {0, 1, 2, -1, -1},
    {3, 7, 9, 11, -1},
    {4, 10, 14, 15, -1},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15, -1},
    {3, 14, 15, -1, -1},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};

bool check[10];
vector<int> res;
vector<int> pickedClocks;
int cnt = 0;

void pushButton(int whichButton, int k) {
    for(int i = 0; i < 5; i++) {
        if(buttons[whichButton][k] == -1) continue;
        clocks[buttons[whichButton][k]] = (clocks[buttons[whichButton][k]] + 3) % 12;
    }
}

void solve(vector<int>& picked) {
    bool finished = true;
    for(int i = 0; i < 16; i++) {
        if(clocks[i] != 0) {
            finished = false;
            break;
        }
    }
    if(finished) {
        res.push_back(cnt);
        cnt = 0;
        return;
    }

    // 고를 수 있는 제일 앞에 있는 시계.
    int smallest = picked.empty() ? 0 : picked.back();
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    cin >> C;
    while(C--) {
        for(int i = 0; i < 16; i++) {
            int a;
            cin >> a;
            clocks[i] = a % 12;
        }
        solve();
        
    }
    return 0;
}