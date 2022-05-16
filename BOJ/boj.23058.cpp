#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N;
int board[8][8];

bool areAligned() {
    int check = board[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] != check) return false;
        }
    }
    return true;
}

void toggleStone(int cnt) {
    // row
    if(cnt < N) {
        for(int i = 0; i < N; i++) {
            if(board[cnt][i]) board[cnt][i] = 0;
            else board[cnt][i] = 1;
        }
    }
    // col
    else {
        for(int i = 0; i < N; i++) {
            if(board[i][cnt % N]) board[i][cnt % N] = 0;
            else board[i][cnt % N] = 1;
        }
    }
}

int countRoom() {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cnt += board[i][j];
        }
    }
    if(cnt > (N*N)/2) cnt = (N*N)- cnt;
    return cnt;
}

int solve(int cnt) {
    if(cnt == 2*N) {
        return countRoom();
    }
    int ret = INF;
    for(int i = 0; i < 2; i++) {
        ret = min(ret, i + solve(cnt+1));
        toggleStone(cnt);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> board[i][j];
    }
    int res = solve(0);
    cout << res;
    return 0;
}