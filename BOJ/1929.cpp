#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 1000001

unsigned char decimal[(MAX + 7) / 8];

bool isPrime(int num)
{
    return decimal[num >> 3] & (1 << (num & 7));
}

void setComposite(int num)
{
    decimal[num >> 3] = decimal[num >> 3] & ~(1 << (num & 7));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    cin >> M >> N;
    memset(decimal, 255, sizeof(decimal));
    setComposite(0);
    setComposite(1);
    int sqrtN = sqrt(N);
    for (int i = 2; i <= sqrtN; i++)
    {
        if (isPrime(i))
            for (int j = i * i; j <= N; j += i)
                setComposite(j);
    }
    for (int i = M; i <= N; i++)
    {
        if (isPrime(i))
            cout << i << '\n';
    }
    return 0;
}