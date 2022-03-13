#include <iostream>
using namespace std;

int arr[51];

int main()
{
    int N;
    cin >> N;
    int num = 1, pos;
    for (int i = 1; i < 51; i++)
    {
        arr[i] = num;
        num += i;
        if (num > N)
        {
            pos = i;
            break;
        }
    }
    cout << pos - (N - arr[pos]) << ' ' << 1 + N - arr[pos];
    return 0;
}