#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cnt = 0;
int board[9][9];
int temp[10];
bool printCheck;
vector< pair<int, int> > coordinates;

void printBoard() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
}

bool check(const pair<int, int>& pos) {
    for(int i = 0; i < 10; i++) temp[i] = 0;
    // row
    for(int i = 0; i < 9; i++) {
        int nx = pos.first;
        if(board[nx][i] != 0) {
            temp[board[nx][i]]++;
            if(temp[board[nx][i]] > 1) return false;
        }
    }
    // col
    for(int i = 0; i < 10; i++) temp[i] = 0;
    for(int i = 0; i < 9; i++) {
        int ny = pos.second;
        if(board[i][ny] != 0) {
            temp[board[i][ny]]++;
            if(temp[board[i][ny]] > 1) {
                return false;
            }
        }
        
    }
    // sqare.
    for(int i = 0; i < 10; i++) temp[i] = 0;
    int nx = (pos.first / 3) * 3 , ny = (pos.second / 3) * 3;
    
    for(int i = nx; i < nx+3; i++) {
        for(int j = ny; j < ny+3; j++) {
            if(board[i][j] != 0) {
                temp[board[i][j]]++;
                if(temp[board[i][j]] > 1) return false;
            }
        }
    }
    return true;
}

void solve(int depth) {
    if(depth == cnt) {
        if(!printCheck) {
            printBoard();
            printCheck = true;
        }
        return;
    }
    for(int i = 1; i <= 9; i++) {
        if(printCheck) break;
        int nx = coordinates[depth].first;
        int ny = coordinates[depth].second;
        board[nx][ny] = i;
        if(check(coordinates[depth])) solve(depth+1);
        board[nx][ny] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) {
                coordinates.push_back({i, j});
                cnt++;
            }
        }
    }
    solve(0);
    return 0;
}