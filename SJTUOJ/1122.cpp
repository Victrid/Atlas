#include <cstdio>
#include <iostream>
using namespace std;
// #define DEBUG

//最长的左部
//最长的右部
struct storage {
    int maxl;
    int maxr;
    int msum;
    int lazy;
};

storage seq[400005];

struct set {
    int l;
    int r;
    int current;
    storage& mx;
    set left() {
        return set{l, (l + r) >> 1, current << 1, seq[current << 1]};
    }
    set right() {
        return set{((l + r) >> 1) + 1, r, current << 1 | 1, seq[current << 1 | 1]};
    }
    bool isleaf() { return !(r - l); }
    int size() { return r - l + 1; }
    set& operator=(const set& rhs) {
        if (this == &rhs)
            return *this;
        l       = rhs.l;
        r       = rhs.r;
        current = rhs.current;
        mx      = rhs.mx;
        return *this;
    }
};
// //DEBUG
// #ifdef DEBUG
// #include <queue>
// void display_a_segtree(set s) {
//     queue<set> q;
//     q.push(s);
//     q.push(set{0, 0, 0, seq[0]});
//     while (!q.empty()) {
//         set v  = q.front();
//         set vs = q.front();
//         q.pop();
//         if (v.l == 0) {
//             putchar('\n');
//             if (q.empty())
//                 return;
//             v = q.front();
//             q.pop();
//             if (v.l == 0)
//                 return;
//             else
//                 q.push(set{0, 0, 0, seq[0]});
//         }
//         if (v.isleaf()) {
//             printf("l %d %d %d %d %d\t", v.l, v.mx.maxl, v.mx.maxr, v.mx.msum, v.mx.lazy);
//         } else {
//             printf("%d %d %d %d %d %d\t", v.l, v.r, v.mx.maxl, v.mx.maxr, v.mx.msum, v.mx.lazy);
//             q.push(v.left());
//             q.push(v.right());
//         }
//     }
// }
// #endif
void update_up(set s) {
    s.mx.maxl = s.left().mx.maxl;
    if (s.left().mx.maxl == s.left().size())
        s.mx.maxl += s.right().mx.maxl;
    s.mx.maxr = s.right().mx.maxr;
    if (s.right().mx.maxr == s.right().size())
        s.mx.maxr += s.left().mx.maxr;
    //! here should be sum.
    s.mx.msum = max(s.left().mx.msum + s.right().mx.msum, max(s.right().mx.maxr, s.right().mx.maxl));
    return;
}
void buildtree(set s) {
    if (s.isleaf()) {
        s.mx.maxl = 1;
        s.mx.maxr = 1;
        s.mx.msum = 1;
        s.mx.lazy = 0;
        return;
    }
    buildtree(s.left());
    buildtree(s.right());
    update_up(s);
    return;
}
void markoc(set s) {
    if (s.size() <= 0)
        return;
    s.mx.maxl = 0;
    s.mx.maxr = 0;
    s.mx.msum = 0;
    s.mx.lazy = 1;
}
void markcl(set s) {
    if (s.size() <= 0)
        return;
    s.mx.maxl = s.size();
    s.mx.maxr = s.size();
    s.mx.msum = s.size();
    s.mx.lazy = 2;
}
void pushtags(set s) {
    if (s.mx.lazy == 1) {
        s.mx.lazy = 0;
        if (s.isleaf()) {
            return;
        }
        markoc(s.left());
        markoc(s.right());
        return;
    } else {
        s.mx.lazy = 0;
        if (s.isleaf()) {
            return;
        }
        markcl(s.left());
        markcl(s.right());
    }
}
//status 1 occupy 2 release
void update(int l, int r, int status, set s) {
    if (s.mx.lazy) {
        pushtags(s);
    }
    if (s.l >= l && s.r <= r) {
        if (status == 1)
            markoc(s);
        else
            markcl(s);
        return;
    }
    if (s.isleaf())
        return;
    int mid = (s.l + s.r) >> 1;
    if (l <= mid) {
        update(l, r, status, s.left());
    }
    if (r > mid) {
        update(l, r, status, s.right());
    }
    update_up(s);
    return;
}
int find(int size, set s, set s0) {
    if (s.mx.msum < size)
        return 0;
    int ll = find(size, s.left(), s0);
    if (ll)
        return ll;
    if ((s.right().mx.maxl + s.left().mx.maxr) >= size) {
        int i = s.left().r - s.left().mx.maxr + 1;
        update(s.left().r - s.left().mx.maxr + 1, s.left().r - s.left().mx.maxr + size, 1, s0);
        return i;
    }
    int lr = find(size, s.right(), s0);
    if (lr)
        return lr;
    return 0;
}
void release(int start, int size, set s) {
    return update(start, start + size - 1, 2, s);
}
int main() {
    int N, M, op1, op2, op3;
    scanf("%d %d", &N, &M);
    buildtree(set{1, N, 1, seq[1]});
    while (M--) {
        scanf("%d", &op1);
        if (op1 == 1) {
            scanf("%d", &op2);
            printf("%d\n", find(op2, set{1, N, 1, seq[1]}, set{1, N, 1, seq[1]}));
            //display_a_segtree(set{1, N, 1, seq[1]});
        } else {
            scanf("%d %d", &op2, &op3);
            release(op2, op3, set{1, N, 1, seq[1]});
            //display_a_segtree(set{1, N, 1, seq[1]});
        }
    }
    return 0;
}
