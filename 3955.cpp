#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll arr[1000001][3];
ll K, C;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll solve()
{
    ll check = C, iter = 2, ret;
    arr[0][0] = 0;
    arr[0][1] = 1;
    arr[0][2] = K;
    arr[1][0] = 1;
    arr[1][1] = 0;
    arr[1][2] = C;

    if (C == 1)
    {
        ret = K + 1;
        if (ret > 1000000000)
            return -1;
        return ret;
    }
    if (K == 1)
        return 1;
    while (check != 1)
    {
        check = arr[iter][2] = arr[iter - 2][2] % arr[iter - 1][2];
        int temp = arr[iter - 2][2] / arr[iter - 1][2] * -1;
        arr[iter][0] = arr[iter - 1][0] * temp + arr[iter - 2][0];
        arr[iter][1] = arr[iter - 1][1] * temp + arr[iter - 2][0];
        iter++;
    }
    ret = arr[iter - 1][0];
    if (ret < 0)
        ret += K;
    if (ret > 1000000000)
        ret = -1;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> K >> C;
        if (gcd(K, C) != 1)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        memset(arr, 0, sizeof(arr));
        int ans = solve();
        if (ans == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }
    return 0;
}