#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int res = 0;
    deque<int> D;
    for(int i = 1; i <= N; i++) D.push_back(i);
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        int center = D.size() / 2;
        int idx = -1;
        for(int j = 0; j < D.size(); j++) idx = D[j] == num ? j : idx; 
        if(idx <= center) {
            while(idx != -1 && D.front() != num) {
                int q = D.front();
                D.pop_front();
                D.push_back(q);
                res++;
            }
        }
        else {
            while(idx != -1 && D.front() != num) {
                int q = D.back();
                D.pop_back();
                D.push_front(q);
                res++;
            }
        }
        if(idx != -1) D.pop_front();
    }
    cout << res << '\n';
    return 0;
}