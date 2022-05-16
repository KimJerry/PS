#include <iostream>
#include <string>
using namespace std;

int arr[26];
int comp[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    while(N--) {
        string a, b;
        cin >> a >> b;
        bool check = true;
        for(int i = 0; i < a.size(); i++) { arr[a[i]-'a']++; comp[b[i]-'a']++; }
        for(int i = 0; i < 26; i++) if(arr[i] != comp[i]) check = false;
        if(check) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';
        fill(arr, arr+26, 0);
        fill(comp, comp+26, 0);
    }
    return 0;
}