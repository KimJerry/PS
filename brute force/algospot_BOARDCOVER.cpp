/*
21. 12. 11. 정기은
알고스팟 문제 ID: BOARDCOVER 게임판 덮기 문제
분류: 탐색
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> board;
int blocks[4][3][2] = {
    { {0, 0}, {1, 0}, {1, 1} }, // ㄱ
    { {0, 0}, {0, 1}, {1, 1} }, // ㄴ
    { {0, 0}, {0, 1}, {-1, 1} },//ㄴ'
    { {0, 0}, {1, 0}, {0, 1} } // ㄱ'
};
int w, h;

int solve(vector<string>& bd) {
    
    bool finished = true;
    // 보드판에 흰칸이 존재하면 그 칸의 좌표를 x, y에 저장함.
    int x, y;
    int bdsize = bd.size();
    int len = bd[0].length();
    for(int i = 0; i < bdsize; i++) {
        for(int j = 0; j < len; j++) {
            if(bd[i][j] == '.') {
                finished = false;
                y = i;
                x = j;
                break;
            }
        }
        if(!finished) break;
    }
    // 모든 보드판이 다 '#' 으로 채워지면 방법 하나 찾은 것.
    if(finished) return 1;

    int ret = 0;
    for(int i = 0; i < 4; i++) {
        int nx1 = x + blocks[i][0][0];
        int ny1 = y + blocks[i][0][1];
        int nx2 = x + blocks[i][1][0];
        int ny2 = y + blocks[i][1][1];
        int nx3 = x + blocks[i][2][0];
        int ny3 = y + blocks[i][2][1];
        if(nx1 < 0 || ny1 < 0 || nx2 < 0 || ny2 < 0 || nx3 < 0 || ny3 < 0) continue;
        if(nx1 >= w || ny1  >= h || nx2 >= w || ny2 >= h || nx3 >= w || ny3 >= h) continue;
        if(bd[ny1][nx1] == '.' && bd[ny2][nx2] == '.' && bd[ny3][nx3] == '.') {
            bd[ny1][nx1] = bd[ny2][nx2] = bd[ny3][nx3] = '#';
            ret += solve(bd);
            bd[ny1][nx1] = bd[ny2][nx2] = bd[ny3][nx3] = '.';
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    cin >> C;
    while(C--) {
        cin >> h >> w;
        for(int i = 0; i < h; i++) {
            string s;
            cin >> s;
            board.push_back(s);
        }
        cout << solve(board) << '\n';
        board.clear();
    }
    return 0;
}