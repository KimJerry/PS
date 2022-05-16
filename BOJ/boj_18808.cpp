#include <iostream>
#include <utility>
using namespace std;

int N, M, K, n, m;
int board[41][41];
int sticker[11][11];

void rotate() {
    int temp[11][11];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            temp[j][n-1-i] = sticker[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sticker[i][j] = temp[i][j];
        }
    }
    swap(n, m);
}

bool isPastable(int x, int y) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[x+i][y+j] == 1 && sticker[i][j] == 1) return false;
            else if(x+i >= N || y+j >= M) return false;
        }
    }
    return true;
}

void putSticker(int x, int y) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            board[x+i][y+j] += sticker[i][j];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    while(K--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> sticker[i][j];
            }
        }
        if(N < n || M < m) {
            rotate();
            if(N < n || M < m) continue;
        }
        bool check = false;
        int iter = 0;
        while(!check && iter != 4) {
            for(int i = 0; i < N && !check; i++) {
                for(int j = 0; j < M && !check; j++) {
                    check = isPastable(i, j);
                    if(check) {
                        putSticker(i, j);
                    }
                }
            }
            rotate();
            iter++;
        }
        
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 1) ans++;
        }
    }
    cout << ans;
    return 0; 
}