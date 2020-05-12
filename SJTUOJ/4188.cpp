#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int
    total;

unsigned long long
    len[1000005]   = {0},
    fhash[1000005] = {0},
    bhash[1000005] = {0},
    shash[1000005] = {0};

char
    buffer[1000005];

int main() {
    scanf("%d", &total);
    for (int i = 1; i <= total; i++) {
        scanf("%s", buffer);
        int s             = strlen(buffer);
        len[i]            = s + len[i - 1];
        fhash[len[i - 1]] = buffer[0];
        bhash[len[i] - 1] = buffer[s - 1];
        for (int j = 1; j < s; j++) {
            //...Hash number...
            fhash[len[i - 1] + j] = fhash[len[i - 1] + j - 1] * 1313 + buffer[j];
            bhash[len[i] - 1 - j] = bhash[len[i] - j] * 1313 + buffer[s - 1 - j];
        }
        shash[i] = fhash[len[i] - 1];
    }
    int times;
    scanf("%d", &times);
    for (int f = 0; f < times; f++) {
        int pg, pf, ps;
        scanf("%d", &ps);
        switch (ps) {
        case 1: {
            bool bf = false;
            scanf("%d", &pf);
            for (int i = 1; i < pf; i++) {
                if (shash[i] == shash[pf]) {
                    bf = true;
                    break;
                }
            }
            printf(bf ? "yes\n" : "no\n");
            break;
        }
        case 2: {
            scanf("%d %d", &pg, &pf);
            int szv = min(len[pg] - len[pg - 1], len[pf] - len[pf - 1]), i = 0;
            for (; i < szv; i++) {
                if (fhash[len[pg - 1] + i] != fhash[len[pf - 1] + i])
                    break;
            }
            printf("%d\n", i);
            break;
        }
        case 3: {
            scanf("%d %d", &pg, &pf);
            int szv = min(len[pg] - len[pg - 1], len[pf] - len[pf - 1]), i = 0;
            for (; i < szv; i++) {
                if (bhash[len[pg] - i - 1] != bhash[len[pf] - i - 1])
                    break;
            }
            printf("%d\n", i);
            break;
        }
        }
    }
    return 0;
}