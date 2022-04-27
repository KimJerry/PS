#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 // 10^9

char str[1000];

int main() {
    bool check = true;
    while(gets(str)) {
        for(char* i = &str[0]; *i != '\0'; i++) {
            if(*i == '\"') {
                if(check) {
                    printf("``");
                    check = false;
                }
                else {
                    printf("''");
                    check = true;
                }
            }
            else cout << *i;
        }
        puts("");
    }
    return 0;
}
