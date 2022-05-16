#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int arr[1000002];
int N;
stack<pii> S;
stack<int> res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);    
    cin >> N;
    S.push({-1, N+1});
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = N; i >= 1; i--) {
        while(S.top().first <= arr[i] && S.top().first != -1) S.pop();
        if(S.top().first > arr[i]) res.push(S.top().first);
        if(S.top().first == -1) res.push(-1);
        S.push({arr[i], i});
    }
    while(!res.empty()) {
        cout << res.top() << ' ';
        res.pop();
    }
    return 0;
}