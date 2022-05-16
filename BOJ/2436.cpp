#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, num;
    cin >> a >> b;
    num = a * b;
    int sqrtN = sqrt(num);
    ll ans;
    for (int i = sqrtN; i > 1; i--)
    {
        if (num % i == 0)
        {
            ans = i;
            if (gcd(ans, num / ans) == a)
                break;
        }
    }
    cout << ans << ' ' << num / ans;
    return 0;
}
