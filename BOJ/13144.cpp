#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()

int arr[100001];
bool check[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int ptr1 = 0, ptr2 = 0;
  check[arr[ptr1]] = true;
  ll ans = n * (n + 1) / 2;
  bool overlap = false;
  while (ptr1 <= ptr2) {
    if (overlap) {
      while (1) {
        ans -= (n - ptr2);
        // cout << ptr2 << ' ' << n << ' ' << ans << '\n';
        if (arr[ptr1] == arr[ptr2]) {
          ptr1++;
          break;
        } else {
          check[arr[ptr1]] = false;
          ptr1++;
        }
      }
      overlap = false;
    }
    if (ptr2 == n - 1) {
      break;
    } else {
      ptr2++;
      if (check[arr[ptr2]])
        overlap = true;
      else
        check[arr[ptr2]] = true;
    }
  }
  cout << ans;

  return 0;
}
