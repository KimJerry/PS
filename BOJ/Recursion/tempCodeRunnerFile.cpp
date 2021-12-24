#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int board[8000][8000];

// 0->-1 / 1->0 / 2->1
int res[3];
int dx[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
int dy[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

void solve(int x1, int y1, int n) {
    if(n == 1) {
        for(int val : {-1, 0, 1}) {
            if(board[x1][y1] == val) res[val+1]++;
        }
        return;
    }
    // 변의 길이 n, 중앙 좌표가 x1, y1 인 조각의 모든 값이 같을까?
    int len = n / 2;
    bool difference = false;
    for(int i = x1-len; i < x1+len; i++) {
        for(int j = y1-len; j < y1+len; j++) {
            if(board[i][j] != board[i+1][j+1]) difference = true; 
        }
    }

    if(!difference) res[board[x1][y1]+1]++;
    else {
        for(int i = 0; i < 9; i++) {
        int nx = dx[i]*(n/3) + x1;
        int ny = dy[i]*(n/3) + y1;
        solve(nx, ny, n/3);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int half = N / 2;
    solve(half, half, N);
    for(int val : res) cout << val << '\n';
    return 0;
}