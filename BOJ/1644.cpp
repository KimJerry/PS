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

unsigned char decimal[1000001];
bool isPrime(int n) { return decimal[n >> 3] & (1 << (n & 7)); }
void setComposite(int n) {
  decimal[n >> 3] = decimal[n >> 3] & ~(1 << (n & 7));
}
vector<int> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0;
    exit(0);
  }
  memset(decimal, 255, sizeof(decimal));
  setComposite(0);
  setComposite(1);
  int sqt = sqrt(4000000);
  for (int i = 2; i <= sqt; i++) {
    if (isPrime(i)) {
      for (int j = i * i; j <= 4000000; j += i)
        setComposite(j);
    }
  }
  for (int i = 2; i <= n; i++) {
    if (isPrime(i))
      arr.push_back(i);
  }
  int N = arr.size();
  int ptr1 = 0, ptr2 = 0;
  int sum = arr[0];
  int cnt = 0;
  while (ptr1 <= ptr2) {
    if (sum == n)
      cnt++;
    if (ptr2 == N - 1)
      sum -= arr[ptr1++];
    else if (ptr1 == ptr2)
      sum += arr[++ptr2];
    else if (sum < n)
      sum += arr[++ptr2];
    else if (sum >= n)
      sum -= arr[ptr1++];
  }
  cout << cnt;
  return 0;
}