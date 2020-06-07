#include <cstdio>
#include <iostream>
using namespace std;
long long seq[400005] = {};
bool exist[400005]    = {};
struct set {
    int l;
    int r;
    int current;
    long long& value;
    set left() {
        return set{l, (l + r) >> 1, current << 1, seq[current << 1]};
    }
    set right() {
        return set{((l + r) >> 1) + 1, r, current << 1 | 1, seq[current << 1 | 1]};
    }
    bool isleaf() { return !(r - l); }
};
void buildtree(set s) {
    if (s.isleaf()) {
        s.value = 1;
        return;
    }
    buildtree(s.left());
    buildtree(s.right());
    s.value = s.left().value + s.right().value;
    return;
}
long long query(int l, int r, set s) {
    if (l > r)
        return 0;
    if (l <= s.l && s.r <= r) {
        return s.value;
    }
    int mid      = (s.l + s.r) >> 1;
    long long q1 = 0, q2 = 0;
    if (l <= mid) {
        q1 = query(l, r, s.left());
    }
    if (r > mid) {
        q2 = query(l, r, s.right());
    }
    return q1 + q2;
}
void update(int l, set s) {
    if (l < s.l || s.r < l) {
        return;
    }
    if (s.isleaf()) {
        s.value = 0;
        return;
    }
    int mid = (s.l + s.r) >> 1;
    if (l <= mid) {
        update(l, s.left());
    } else {
        update(l, s.right());
    }
    s.value = s.left().value + s.right().value;
    return;
}

int binarysearch(int l, int r, int num, set ss) {
    int llim = l, mid;
    while (l <= r) {
        mid   = (l + r) / 2;
        int t = query(llim, mid, ss);
        if (t == num) {
            if (exist[mid])
                return mid;
            else
                r = mid - 1;
        } else if (t < num)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return 0;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    buildtree(set{1, N, 1, seq[1]});
    for (int i = 1; i <= N; i++) {
        exist[i] = true;
    }
    int current    = 1;
    bool direction = 0; //pos
    int q          = N;
    while (q != 1) {
        int amounts = M % (2 * (q - 1));
        int rr      = query(current + 1, N, set{1, N, 1, seq[1]});
        int ll      = query(1, current - 1, set{1, N, 1, seq[1]});
        if (amounts == 0) {
            int p = current;
            if ((ll == 0) || (direction && rr != 0)) {
                p        = binarysearch(p + 1, N, 1, set{1, N, 1, seq[1]});
                exist[p] = false;
                update(p, set{1, N, 1, seq[1]});
            } else {
                p        = binarysearch(1, p - 1, ll, set{1, N, 1, seq[1]});
                exist[p] = false;
                update(p, set{1, N, 1, seq[1]});
            }
            q = query(1, N, set{1, N, 1, seq[1]});
            continue;
        }
        if (!direction) {
            if (amounts < rr + 1) {
                current        = binarysearch(current, N, amounts, set{1, N, 1, seq[1]});
                exist[current] = false;
                update(current, set{1, N, 1, seq[1]});
                current = binarysearch(current + 1, N, 1, set{1, N, 1, seq[1]});
                q       = query(1, N, set{1, N, 1, seq[1]});
                continue;
            }
            if (amounts >= rr + 1 && amounts < rr + q) {
                amounts -= rr + 1;
                current   = N;
                direction = 1;
                amounts++;
                current        = binarysearch(1, N, q - amounts + 1, set{1, N, 1, seq[1]});
                exist[current] = false;
                update(current, set{1, N, 1, seq[1]});
                current = binarysearch(1, current - 1, q - amounts, set{1, N, 1, seq[1]});
                q       = query(1, N, set{1, N, 1, seq[1]});
                continue;
            }
            if (amounts >= rr + q) {
                amounts -= rr + q;
                current   = 1;
                direction = 0;
                amounts++;
                current        = binarysearch(1, N, amounts, set{1, N, 1, seq[1]});
                exist[current] = false;
                update(current, set{1, N, 1, seq[1]});
                current = binarysearch(current + 1, N, 1, set{1, N, 1, seq[1]});
                q       = query(1, N, set{1, N, 1, seq[1]});
                continue;
            }
        } else {
            if (amounts < ll + 1) {
                current        = binarysearch(1, current, ll - amounts + 2, set{1, N, 1, seq[1]});
                exist[current] = false;
                update(current, set{1, N, 1, seq[1]});
                current = binarysearch(1, current - 1, ll - amounts + 1, set{1, N, 1, seq[1]});
                q       = query(1, N, set{1, N, 1, seq[1]});
                continue;
            }
            if (amounts >= ll + 1 && amounts < ll + q) {
                amounts -= ll + 1;
                current   = 1;
                direction = 0;
                amounts++;
                current        = binarysearch(1, N, amounts, set{1, N, 1, seq[1]});
                exist[current] = false;
                update(current, set{1, N, 1, seq[1]});
                current = binarysearch(current + 1, N, 1, set{1, N, 1, seq[1]});
                q       = query(1, N, set{1, N, 1, seq[1]});
                continue;
            }
            if (amounts >= ll + q) {
                amounts -= ll + q;
                current   = N;
                direction = -1;
                amounts++;
                current        = binarysearch(1, N, q - amounts + 1, set{1, N, 1, seq[1]});
                exist[current] = false;
                update(current, set{1, N, 1, seq[1]});
                current = binarysearch(1, current - 1, q - amounts, set{1, N, 1, seq[1]});
                q       = query(1, N, set{1, N, 1, seq[1]});
                continue;
            }
        }
    }
    printf("%d", current);
    return 0;
}
