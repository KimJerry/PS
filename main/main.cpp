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

int arr[1000005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int ptr1 = 0, ptr2 = 0;
  int len = 0, odd = 0;
  if (arr[0] % 2 == 0)
    len = 1;
  else
    odd++;
  while (ptr1 <= ptr2) {
    if (k == odd) {
      len = len < ptr2 - ptr1 + 1 - k ? ptr2 - ptr1 + 1 : len;
      if (arr[ptr1] % 2 == 1) {
        odd--;
      }
      ptr1++;
    }
  }
  return 0;
}