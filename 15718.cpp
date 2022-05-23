#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

vector<ll> arrN;
vector<ll> arrK;
ll combArr[1050][1050];

void init()
{
    arrN.clear();
    arrK.clear();
}

void solve(ll num, ll base, vector<ll> &buf)
{
    while (num >= base)
    {
        buf.push_back(num % base);
        num = num / base;
    }
    buf.push_back(num);
}

void makecomb()
{
    combArr[0][0] = 1;
    for (int i = 1; i < 1050; i++)
    {
        for (int j = 0; j < 1050; j++)
        {
            if (j == 0)
                combArr[i][j] = 1;
            else if (i >= j)
                combArr[i][j] = ((combArr[i - 1][j - 1] + combArr[i - 1][j])) % 100007;
        }
    }
}

ll comb_mod(ll a, ll b, ll mod)
{

    while (arrN.size() > arrK.size())
        arrK.push_back(0);
    ll ret = 1;
    for (int i = 0; i < arrN.size(); i++)
    {
        if (arrN[i] < arrK[i])
            return 0;

        ret = (combArr[arrN[i]][arrK[i]] % mod) * ret % mod;
    }
    return ret;
}

ll getInverse(ll m, ll n)
{
    ll arr[3][3];
    ll check = m;
    arr[0][0] = 0, arr[0][1] = -1, arr[0][2] = n;
    arr[1][0] = 1, arr[1][1] = 0, arr[1][2] = m;
    int iter = 2;
    while (check != 1)
    {
        ll temp = arr[(iter + 1) % 3][2] / arr[(iter + 2) % 3][2];
        arr[iter][0] = -temp * arr[(iter + 2) % 3][0] + arr[(iter + 1) % 3][0];
        arr[iter][1] = -temp * arr[(iter + 2) % 3][1] + arr[(iter + 1) % 3][1];
        arr[iter][2] = arr[(iter + 1) % 3][2] % arr[(iter + 2) % 3][2];
        check = arr[iter][2];
        iter = (iter + 1) % 3;
    }
    return (arr[(iter + 2) % 3][0] + n) % n;
}

ll ans(ll a, ll b)
{
    ll n1 = 1031, n2 = 97;
    ll m1 = getInverse(1031, 97);
    ll m2 = getInverse(97, 1031);
    return (a * n1 * m1 + b * n2 * m2) % 100007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    ll temp1, temp2;
    makecomb();
    while (T--)
    {
        ll N, M;
        cin >> N >> M;
        if (N < M)
        {
            if (M - N == 1)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
            continue;
        }
        init();
        solve(N - 1, 97, arrN);
        solve(N - M + 1, 97, arrK);
        temp1 = comb_mod(N - 1, N - M + 1, 97);
        init();
        solve(N - 1, 1031, arrN);
        solve(N - M + 1, 1031, arrK);
        temp2 = comb_mod(N - 1, N - M + 1, 1031);
        cout << ans(temp1, temp2) << '\n';
    }
    return 0;
}