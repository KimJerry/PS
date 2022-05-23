#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (auto &e : arr)
    cin >> e;
  sort(all(arr));
  int min = 2000000001;
  int ptr1 = 0, ptr2 = 0;

  while (ptr1 <= ptr2) {
    while (ptr1 <= ptr2 && arr[ptr2] - arr[ptr1] >= m) {
      if (arr[ptr2] - arr[ptr1] < min) {
        min = arr[ptr2] - arr[ptr1];
      }
      ptr1++;
    }
    if (ptr2 == n - 1)
      ptr1++;
    else if (ptr1 == ptr2)
      ptr2++;
    else if (arr[ptr2] - arr[ptr1] < m)
      ptr2++;
  }
  cout << min;
  return 0;
}