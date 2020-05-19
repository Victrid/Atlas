#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int book[100005]    = {0};
int book_rem[10005] = {0};
bool to_rem[10005]  = {false};
bool exi[10005]     = {false};
unsigned int bhash(char* c) {
    unsigned int pc = 0;
    while (*c != '\0') {
        pc *= 131;
        pc += *c;
        c++;
    }
    pc %= 10000;
    return pc;
}
int main() {
    int m, n;
    int before_groups = 0;
    int step          = 0;
    int length_min;
    scanf("%d", &n);
    char str[10];
    while (n--) {
        scanf("%s", str);
        to_rem[bhash(str)] = 1;
    }
    scanf("%d", &m);
    int exist_torem = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%s", str);
        int p   = bhash(str);
        book[i] = p;
        if (to_rem[p] && !exi[p]) {
            exi[p] = 1;
            exist_torem++;
        }
    }
    length_min = m;
    for (int i = 1; i <= m; i++) {
        int exist_groups = m;
        book_rem[book[i]]++;
        for (int j = 0; j < 10000; j++) {
            if (exi[j] != 0) {
                exist_groups = min(exist_groups, book_rem[j]);
            }
        }
        if (exist_groups > before_groups) {
            length_min    = min(step, length_min);
            before_groups = length_min;
            step          = 0;
        } else {
            step++;
        }
    }
    printf("%d\n%d", exist_torem, length_min);
    return 0;
}