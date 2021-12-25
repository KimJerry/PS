#include <iostream>
#include <string>
using namespace std;

int N;
int board[65][65];

void solve(int x1, int y1, int len) {
    if(len == 1) {
        cout << board[x1][y1];
        return;
    }
    bool differ = false;
    int temp = board[x1][y1];
    for(int i = x1; i < x1+len; i++) {
        for(int j = y1; j <y1+len; j++) {
            if(board[i][j] != temp) differ = true;
        }
    }
    if(!differ) cout << temp;
    else {
        cout << '(';
        solve(x1, y1, len/2);
        solve(x1, y1+len/2, len/2);
        solve(x1+len/2, y1, len/2);
        solve(x1+len/2, y1+len/2, len/2);
        cout << ')';
    }
    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < N; j++) {
            board[i][j] = str[j] - '0';
        }
    }
    solve(0, 0, N);
}