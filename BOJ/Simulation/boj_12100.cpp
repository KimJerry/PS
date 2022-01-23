#include <iostream>
#include <cstring>
using namespace std;
#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3

int N;
int board[21][21];
int temp[21][21];
bool check[21][21];
int res = 0;

void printBoard() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void init() {
    memset(temp, 0, sizeof(temp));
    memset(check, false, sizeof(check));
}

void rotate() {
    int temp[21][21];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            temp[j][N-1-i] = board[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

void tiltBoard(int mode) {
    int dir = mode;
    while(dir--) rotate();

    for(int i = 0; i < N; i++) {
        int iter = 0;
        for(int j = 0; j < N; j++) {
            if(board[i][j] != 0) {
                if(temp[i][iter] == 0) temp[i][iter] = board[i][j];
                else {
                    if(temp[i][iter] == board[i][j] && !check[i][iter]) {
                        temp[i][iter] += board[i][j];
                        check[i][iter++] = true;
                    }
                    else temp[i][++iter] = board[i][j];
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            board[i][j] = temp[i][j];
        }
    }
    for(int i = 0; i < 4-mode; i++) rotate();
    init();
}

void solve(int depth) {
    if(depth == 5) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                res = res < board[i][j] ? board[i][j] : res;
            }
        }
        return;
    }
    for(int mode : {LEFT, DOWN, RIGHT, UP}) {
        int tempBoard[21][21];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                tempBoard[i][j] = board[i][j];
            }
        }
        tiltBoard(mode);
        solve(depth+1);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                board[i][j] = tempBoard[i][j];
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    solve(0);
    cout << res;
    return 0;
}