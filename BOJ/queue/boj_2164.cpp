#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<int> Q;
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) Q.push(i);
    while(Q.size() != 1) {
        Q.pop();
        int f = Q.front();
        Q.pop();
        Q.push(f);
    }
    cout << Q.front() << '\n';
    return 0;
}