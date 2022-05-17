#include <iostream>
using namespace std;
typedef long long ll;

ll N, A;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> A;
    cout << -A + N << ' ';
    if (gcd(N, A) == 1)
    {
        ll check = A;
        ll arr[3][3];
        arr[0][0] = 0, arr[0][1] = -1, arr[0][2] = N;
        arr[1][0] = 1, arr[1][1] = 0, arr[1][2] = A;
        int iter = 2;
        while (check != 1)
        {
            ll temp = arr[(iter + 1) % 3][2] / arr[(iter + 2) % 3][2];
            arr[iter][2] = arr[(iter + 1) % 3][2] % arr[(iter + 2) % 3][2];
            arr[iter][0] = -1 * arr[(iter + 2) % 3][0] * temp + arr[(iter + 1) % 3][0];
            arr[iter][1] = -1 * arr[(iter + 2) % 3][1] * temp + arr[(iter + 1) % 3][1];
            check = arr[iter][2];
            iter = (iter + 1) % 3;
        }
        cout << (arr[(iter + 2) % 3][0] + N) % N;
    }
    else
        cout << -1 << '\n';

    return 0;
}