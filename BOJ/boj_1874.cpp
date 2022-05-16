#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int arr[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int iter = 1;
    stack<int> S;
    queue<char> Q;
    bool NO = false;
    for(int i = 0; i < N; i++) {
        int cur = arr[i];
        while(cur >= iter) {
            S.push(iter++);
            Q.push('+');
        }
        if(S.top() != cur) {
            NO = true;
            break;
        }
        else {
            S.pop();
            Q.push('-');
        }
    }
    while(!Q.empty() && !NO) {
        cout << Q.front() << '\n';
        Q.pop();
    }
    if(NO) cout << "NO\n";
    return 0;
}