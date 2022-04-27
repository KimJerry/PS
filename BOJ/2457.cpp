#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int N;
vector<pi> flower;

int daySum(int month)
{
    int res = 0;
    for (int i = 0; i <= month; i++)
        res += day[i];
    return res;
}

int solve()
{
    int ans = 0;
    int march = daySum(2) + 1;
    int november = daySum(10) + 30;
    int pos = march;

    while (pos <= november)
    {
        vector<pi> lessThanPos;
        for (int i = 0; i < flower.size(); i++)
        {
            if (flower[i].second <= march || flower[i].first > november)
                continue;
            if (flower[i].first <= pos && flower[i].second > pos)
                lessThanPos.push_back(flower[i]);
            else if (flower[i].first > pos)
            {
                if (lessThanPos.size() == 0)
                    return 0;
                break;
            }
        }
        int max = 0;
        for (int i = 0; i < lessThanPos.size(); i++)
        {
            if (lessThanPos[i].second > max)
                max = lessThanPos[i].second;
        }
        pos = max;
        ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pi temp;
        temp.first = daySum(a - 1) + b;
        temp.second = daySum(c - 1) + d;
        flower.push_back(temp);
    }
    sort(flower.begin(), flower.end());
    int ans = solve();
    cout << ans;
    return 0;
}