#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, K, M;
vector<ll> arrN;
vector<ll> arrK;
ll combArr[2005][2005];

void solve(ll num, ll base, vector<ll> &buf)
{
    while (num >= base)
    {
        buf.push_back(num % base);
        num = num / base;
    }
    buf.push_back(num);
}

ll comb(ll a, ll b)
{
    if (a == b || b == 0)
        return 1;
    if (combArr[a][b] != 0)
        return combArr[a][b];
    combArr[a][b] = (comb(a - 1, b - 1) % M + comb(a - 1, b) % M) % M;
    return combArr[a][b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K >> M;
    solve(N, M, arrN);
    solve(K, M, arrK);

    while (arrN.size() != arrK.size())
        arrK.push_back(0);

    ll res = 1;
    for (int i = 0; i < arrN.size(); i++)
    {
        if (arrN[i] < arrK[i])
        {
            res = 0;
            break;
        }
        res = (comb(arrN[i], arrK[i]) * res) % M;
    }
    cout << res;
    return 0;
}