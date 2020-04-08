#include <cstdio>
#include <iostream>
using namespace std;
//barrel sort
//assume no duplicat.
//NO WA please🙏
bool barrel[4000010]  = {0};
// int barrelblock[4001] = {0};
int main() {
    int n, proc;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &proc);
        barrel[2000005 + proc] = 1;
        /* ++barrelblock[(2000005 + proc) / 1000]; */
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &proc);
        if (proc) {
            scanf("%d", &proc);
            barrel[2000005 + proc] = 1;
            // ++barrelblock[(2000005 + proc) / 1000];
        } else {
            scanf("%d", &proc);
            barrel[2000005 + proc] = 0;
            // --barrelblock[(2000005 + proc) / 1000];
        }
    }
    // for (int blk = 0; blk < 4000; blk++) {
    for (int i = 1 /* blk * 1000 */; /* barrelblock[blk] && */ i < 4000010; i++) {
        if (barrel[i]) {
            printf("%d ", (i - 2000005));
            // barrelblock[blk]--;
        }
    }
    /* } */
    return 0;
}