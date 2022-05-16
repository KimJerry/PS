#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1001

unsigned char decimal[(MAX + 7) / 8];

bool isPrime(int num)
{
    return decimal[num >> 3] & (1 << (num & 7));
}

void setN(int num)
{
    decimal[num >> 3] = decimal[num >> 3] & ~(1 << (num & 7));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;

    memset(decimal, 255, sizeof(decimal));
    for (int i = 2; i <= N; i++)
    {
        if (isPrime(i))
        {
            for (int j = i; j <= N; j += i)
            {
                if (!isPrime(j))
                    continue;
                setN(j);
                K--;
                if (K == 0)
                {
                    cout << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}