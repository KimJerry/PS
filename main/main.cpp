#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  vector<int> arr;

  for (int i = 0; i < 7; i++) {
    int a;
    cin >> a;
    arr.push_back(a);
  }
  for (auto e : arr)
    cout << e << ' ';
  cout << '\n';
  sort(arr.begin(), arr.end(), greater<>());
  for (auto e : arr)
    cout << e << ' ';
  return 0;
}
