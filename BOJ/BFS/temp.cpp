#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;
int arr[100001];
bool check[100001];
queue<int> Q;   // idx 저장.

void bfs(int start) {
    memset(arr, 0, sizeof(arr));
    Q.push(start);
    check[start] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        int n1 = cur+1, n2 = cur-1, n3 = cur*2;
        // n1
        if(n1 <= 100000) {
            arr[n1] = arr[cur]+1;
            check[n1] = true;
            // 
        }
        if(n2 >= 0)
        // n2
        // n3        
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    return 0;
}