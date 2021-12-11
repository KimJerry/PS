/*
21. 12. 11. 정기은
알고스팟 문제 ID: PICNIC
분류: 완전탐색, 재귀호출
*/

#include <iostream>
#include <cstring>
using namespace std;

bool take[10];
bool areFriends[10][10];
int n, m;

int countPair(bool taken[10]) {
    int firstFree = -1;
    for(int i = 0; i < n; i++) {
        if(!taken[i]) {
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) return 1;
    int ret = 0;
    for(int pairwith = firstFree + 1; pairwith < n; pairwith++) {
        if(!taken[pairwith] && areFriends[firstFree][pairwith]) {
            taken[firstFree] = taken[pairwith] = true;
            ret += countPair(taken);
            taken[firstFree] = taken[pairwith] = false;
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
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }
        cout << countPair(take) << '\n';
        memset(take, false, sizeof(take));
        memset(areFriends, false, sizeof(areFriends));
    }
    return 0;
}