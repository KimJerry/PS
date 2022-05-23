#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

char board[51][51];
char temp[51];
int N;

int countMax() {
  int len = 1;
  for (int s = 0; s < N; s++) {
    int tmp = 1;
    char color = board[s][0];
    for (int t = 1; t < N; t++) {
      if (board[s][t] == color) {
        tmp++;
        len = len < tmp ? tmp : len;
      } else {
        tmp = 1;
        color = board[s][t];
      }
    }
  }
  for (int s = 0; s < N; s++) {
    int tmp = 1;
    char color = board[0][s];
    for (int t = 1; t < N; t++) {
      if (board[t][s] == color) {
        tmp++;
        len = len < tmp ? tmp : len;
      } else {
        tmp = 1;
        color = board[t][s];
      }
    }
  }
  return len;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    for (int j = 0; j < N; j++)
      board[i][j] = temp[j];
  }
  // row

  int len = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      char temp = board[i][j];
      board[i][j] = board[i][j + 1];
      board[i][j + 1] = temp;
      int tmp = countMax();
      len = len < tmp ? tmp : len;
      temp = board[i][j];
      board[i][j] = board[i][j + 1];
      board[i][j + 1] = temp;
    }
  }

  // column
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N; j++) {
      char temp = board[i][j];
      board[i][j] = board[i + 1][j];
      board[i + 1][j] = temp;
      int tmp = countMax();
      len = len < tmp ? tmp : len;
      temp = board[i][j];
      board[i][j] = board[i + 1][j];
      board[i + 1][j] = temp;
    }
  }
  cout << len;
  return 0;
}