#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 // 10^9

int main() {
    int a, b, c, d;
    while(a || b || c || d) {
        int ans = 1080;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        ans += ((b-a+40) % 40)*9;
        ans += ((b-c+40) %40)*9;
        ans += ((d-c+40)%40)*9;
        printf("%d\n", ans);
    }
    return 0;
}
