#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()

int arr[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int ptr1 = 0, ptr2 = 0;
  int sum = arr[0];
  int len = 100001;
  while (ptr1 <= ptr2) {
    if (sum >= s)
      len = ptr2 - ptr1 + 1 < len ? ptr2 - ptr1 + 1 : len;
    if (ptr2 == n - 1)
      sum -= arr[ptr1++];
    else if (ptr1 == ptr2)
      sum += arr[++ptr2];
    else if (sum < s)
      sum += arr[++ptr2];
    else if (sum >= s)
      sum -= arr[ptr1++];
  }
  if (len == 100001)
    len = 0;
  cout << len;
  return 0;
}