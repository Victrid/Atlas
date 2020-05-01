#include <cstring>
#include <iostream>
using namespace std;

inline bool n_strcmp(char* c1, char* c2, int digit) {
    while (digit--) {
        if (c2[digit] != c1[digit])
            return false;
    }
    return true;
}
inline int p_strcmp(char* c1, char* c2, int* partial, int digit) {
    if (c2[0] != c1[0])
        return 1;
    for (int i = 1; i < digit; i++) {
        if (c2[i] != c1[i]) {
            //0...i-1 are valid
            return i - partial[i - 1];
        }
    }
    return 0;
}
inline int partial(char* c1, int digit) {
    int ans = 0;
    for (int i = 1; i < digit; i++) {
        if (n_strcmp(c1, c1 + digit - i, i))
            ans = i;
    }
    return ans;
}
inline int* construct_partial(char* c1, int digit) {
    int* prefix = new int[digit]();
    for (int i = 1; i < digit; i++) {
        if (c1[i] == c1[prefix[i - 1]])
            prefix[i] = prefix[i - 1] + 1;
        else {
            int j = i - 1;
            while (prefix[j] > 0 && c1[prefix[j]] != c1[i])
                j = prefix[j] - 1;
            if (prefix[j] > 0)
                prefix[i] = prefix[j] + 1;
            else {
                prefix[i] = (c1[i] == c1[0]);
            }
        }
    }
    return prefix;
}
int kmp_strstr(char* heystack, char* needle) {
    int needlelen   = strlen(needle);
    int heystacklen = strlen(heystack);
    if (needlelen == 0)
        return 0;
    if (heystacklen == 0)
        return -1;
    int* partial = construct_partial(needle, needlelen);
    int ndigit = 0, hdigit = 0;
    while (hdigit < heystacklen) {
        while (needle[ndigit] == heystack[hdigit] && hdigit < heystacklen && ndigit < needlelen) {
            ++ndigit;
            ++hdigit;
        }
        if (ndigit == needlelen) {
            return hdigit - needlelen;
        }
        if (hdigit == heystacklen) {
            return -1;
        } else {
            if (ndigit == 0) {
                hdigit++;
                continue;
            }
            //Here you should not repeat comparisons you've already done.
            ndigit = partial[ndigit - 1];
        }
    }
    return -1;
}
char heys[1000002];
char nedl[100002];
int main() {
    cin.getline(heys, 1000001);
    cin.getline(nedl, 100001);
    printf("%d", kmp_strstr(heys, nedl));
    return 0;
}