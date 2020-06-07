#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//TLE... It's segtree...
struct point {
    int x;
    int y;
    bool operator<=(point& other) {
        return x <= other.x;
    }
};

struct p_y : public point {
    bool operator<=(p_y& other) {
        return y <= other.y;
    }
};

template <typename T>
T* MergeSort(T* list, int listSize) {
    //<=
    if (listSize == 1)
        return list;
    if (listSize == 2) {
        if (list[0] <= list[1]) {
            return list;
        }
        T temp  = list[0];
        list[0] = list[1];
        list[1] = temp;
        return list;
    }
    T* tmplist = new T[listSize];
    T* llst    = MergeSort(list, listSize / 2);
    T* rlst    = MergeSort(list + listSize / 2, listSize - listSize / 2);
    int lct = 0, rct = 0;
    while (lct + rct != listSize) {
        if ((llst[lct] <= rlst[rct] && lct < listSize / 2) || rct >= listSize - listSize / 2) {
            tmplist[lct + rct] = llst[lct];
            lct++;
        } else {
            tmplist[lct + rct] = rlst[rct];
            rct++;
        }
    }
    memcpy(list, tmplist, listSize * sizeof(T));
    delete[] tmplist;
    return list;
}
//......
point lst[50001];
long long dp[50001][11][2]   = {};
long long seq[200005][11][2] = {};

struct set {
    int l;
    int r;
    int current;
    set left() {
        return set{l, (l + r) >> 1, current << 1};
    }
    set right() {
        return set{((l + r) >> 1) + 1, r, current << 1 | 1};
    }
    bool isleaf() { return !(r - l); }
};
long long query(int l, int r, int d, int j, set s) {
    if (l > r)
        return 0;
    if (l <= s.l && s.r <= r) {
        return seq[s.current][j][d];
    }
    int mid      = (s.l + s.r) >> 1;
    long long q1 = 0, q2 = 0;
    if (l <= mid) {
        q1 = query(l, r, d, j, s.left());
    }
    if (r > mid) {
        q2 = query(l, r, d, j, s.right());
    }
    return q1 + q2;
}
void update(int l, int d, int j, long long chg, set s) {
    if (l < s.l || s.r < l) {
        return;
    }
    if (!s.isleaf()) {
        int mid = (s.l + s.r) >> 1;
        if (l <= mid) {
            update(l, d, j, chg, s.left());
        } else {
            update(l, d, j, chg, s.right());
        }
    }
    seq[s.current][j][d] += chg;
    seq[s.current][j][d] %= 100007;
    return;
}

int main() {
    int n, k, x, y;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        lst[i].x = x;
        lst[i].y = y;
    }
    //squeeze to continuous
    MergeSort((p_y*)(lst + 1), n);
    for (int i = 1; i <= n; i++) {
        lst[i].y = i;
    }

    MergeSort((lst + 1), n);
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0][0] = 1;
        dp[i][0][1] = 1;
        update(lst[i].y, 1, 0, 1, set{1, n, 1});
        update(lst[i].y, 0, 0, 1, set{1, n, 1});
        for (int j = 1; j <= k; j++) {
            dp[i][j][0] += query(1, lst[i].y - 1, 0, j, set{1, n, 1}) + query(1, lst[i].y - 1, 1, j - 1, set{1, n, 1});
            // ! direction revert
            dp[i][j][1] += query(lst[i].y + 1, n, 1, j, set{1, n, 1}) + query(lst[i].y + 1, n, 0, j - 1, set{1, n, 1});
            dp[i][j][0] %= 100007;
            dp[i][j][1] %= 100007;
            update(lst[i].y, 0, j, dp[i][j][0], set{1, n, 1});
            update(lst[i].y, 1, j, dp[i][j][1], set{1, n, 1});
            if (j == k) {
                total += dp[i][k][0] + dp[i][k][1];
                total %= 100007;
            }
        }
    }
    printf("%lld", total);
    return 0;
}