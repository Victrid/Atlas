#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    if (t > 2 && (t & 1) == 0) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}