#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pi;

int N;
vector<pi> people;
int res[50];

void solve() {
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            if(people[j].first > people[i].first && people[j].second > people[i].second) {
                cnt++;
            }
        }
        res[i] = cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        people.push_back(make_pair(a, b));
    }
    solve();
    for(int i = 0; i < N; i++) cout << res[i] << endl;
    return 0;
}