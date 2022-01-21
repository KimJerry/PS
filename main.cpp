#include <iostream>
#include <string>
#include <queue>
using namespace std;

int L, N, M;
int board[31][31][31];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> L >> N >> M;
    //input
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < N; j++) {
            string arr;
            cin >> arr;
            for(int k = 0; k < M; k++) {
                if(arr[k] == '#') board[i][j][k] = -1;
                else if(arr[k] == 'S') board[i][j][k] = -2;

            }
        }
    }
    return 0;
}