/*
21. 12. 11. 정기은
1 ~ n 까지 범위에서 k개의 수 고르기.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void printArray(vector<int>& picked) {
    for(auto u : picked) {cout << u << ' ';}
    cout << endl;
}

void pick(int n, vector<int>& picked, int toPick) {
    // 기저 조건.
    if(toPick == 0) printArray(picked);
    // 고를 수 있는 가장 작은 수 찾기.
    int smallest = picked.empty() ? 1 : picked.back() + 1;
    // 원소 하나 고르기.
    for(int next = smallest; next <= n; next++) {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

int main() {
    // 1 ~ 7 까지의 범위에서 원소 4개를 고르는 모든 경우 출력하기.
    pick(7, arr, 4);
    return 0;
}