#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, num;
    cin >> N;
    stack<pll> S;
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> num;
        ll overlap = 1;
        while(!S.empty() && S.top().first <= num) {
            ans += S.top().second;
            if(S.top().first == num) overlap = S.top().second + 1;
            S.pop();
        }
        if(!S.empty()) ans++;
        S.push({num, overlap});
    }
    cout << ans << '\n';
    return 0;
}