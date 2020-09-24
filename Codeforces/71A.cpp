#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int t, len;
    char str[110];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        len = strlen(str);
        if (len <= 10) {
            printf("%s\n", str);
            continue;
        } else {
            printf("%c%d%c\n", *str, len - 2, *(str + len - 1));
        }
    }
    return 0;
}