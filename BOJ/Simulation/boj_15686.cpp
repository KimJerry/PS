#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
#define X first
#define Y second

int N, M, ans = 1e9;
int board[51][51];
vector< pair<int, int> > chickenStore;
vector<int> pickedIndex;

int getDistance() {
    int distSum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 1) {
                int tempdist = 1e9;
                for(int index : pickedIndex) {
                    int nx = chickenStore[index].X;
                    int ny = chickenStore[index].Y;
                    tempdist = abs(nx-i) + abs(ny-j) < tempdist ? abs(nx-i) + abs(ny-j) : tempdist;
                }
                distSum += tempdist;
            }
        }
    }
    return distSum;
}

void solve(int depth, int n) {
    if(depth == n) {
        int chickenDist = getDistance();
        ans = ans > chickenDist ? chickenDist : ans;
        return;
    }
    int next = 0;
    if(pickedIndex.size() != 0) next = pickedIndex.back() + 1;
    for(int i = next; i < chickenStore.size(); i++) {
        pickedIndex.push_back(i);
        solve(depth+1, n);
        pickedIndex.pop_back();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) chickenStore.push_back({i, j});
        }
    }
    for(int i = 1; i <= M; i++) solve(0, i);
    cout << ans;
    return 0;
}