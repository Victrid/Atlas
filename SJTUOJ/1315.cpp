#include <iostream>
using namespace std;
int p[100001]   = {0};
int son[100001] = {0};
int mot[100001] = {0};
int main() {
    //So simple?
    int pl;
    scanf("%d", &pl);
    for (int i = 1; i <= pl; i++) {
        for (int j = 0; j <= i; j++) {
            int phs = j / (double)i * 100000;
            if (p[phs] == 0) {
                p[phs]   = 1;
                son[phs] = j;
                mot[phs] = i;
            }
        }
    }
    for (int i = 0; i <= 100000; i++) {
        if (p[i] != 0) {
            printf("%d/%d\n", son[i], mot[i]);
        }
    }
    return 0;
}