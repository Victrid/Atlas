#include <iostream>
using namespace std;
int ll[1000050];
int* MergeSort(int* list, int listSize, long long& cmp) {
    if (listSize == 1)
        return list;
    if (listSize == 2) {
        cmp++;
        [&](int& a, int& b) { if (a>b){a^=b;b^=a;a^=b;} }(list[0], list[1]);
        return list;
    }
    int* tmplist = new int[listSize];
    int* llst    = MergeSort(list, listSize / 2, cmp);
    int* rlst    = MergeSort(list + listSize / 2, listSize - listSize / 2, cmp);
    int lct = 0, rct = 0;
    while (lct + rct != listSize) {
        if (rct < listSize - listSize / 2 && lct < listSize / 2) {
            cmp++;
        }
        if ((llst[lct] <= rlst[rct] && lct < listSize / 2) || rct >= listSize - listSize / 2) {
            tmplist[lct + rct] = llst[lct];
            lct++;
        } else {
            tmplist[lct + rct] = rlst[rct];
            rct++;
        }
    }
    for (int i = 0; i < listSize; i++)
        list[i] = tmplist[i];
    delete[] tmplist;
    return list;
}
void siftdown(int* list, int listSize, int it, long long& cmp) {
    auto swap = [&](int& a, int& b) {if(a==b)return;a^=b;b^=a;a^=b; };
    if (((it + 1) << 1) > listSize)
        return;
    if (((it + 1) << 1 | 1) > listSize) {
        //1
        cmp++;
        if ([&](int& a, int& b) { if (a>b){swap(a,b);return false;}return true; }(list[it], list[((it + 1) << 1) - 1]))
            return siftdown(list, listSize, ((it + 1) << 1) - 1, cmp);
        //!
        return;
    }
    cmp += 2;
    if (list[((it + 1) << 1) - 1] < list[((it + 1) << 1 | 1) - 1]) {
        if ([&](int& a, int& b) { if (a>b){swap(a,b);return true;}return false; }(list[it], list[((it + 1) << 1) - 1]))
            return siftdown(list, listSize, ((it + 1) << 1) - 1, cmp);
    } else {
        if ([&](int& a, int& b) { if (a>b){swap(a,b);return true;}return false; }(list[it], list[((it + 1) << 1 | 1) - 1]))
            return siftdown(list, listSize, ((it + 1) << 1 | 1) - 1, cmp);
    }
    //!
    return;
}
int* HeapSort(int* list, int listSize, long long& cmp) {
    //from big to small
    auto swap = [&](int& a, int& b) {if(a==b)return;a^=b;b^=a;a^=b; };
    for (int i = 2; i <= listSize; i++) {
        int pos = i;
        while (pos != 1) {
            cmp++;
            if ([&](int& a, int& b) { if (a<b){swap(a,b);return false;}return true; }(list[pos - 1], list[(pos >> 1) - 1]))
                break;
            pos = pos >> 1;
        }
    }
    for (int i = listSize; i > 1; i--) {
        swap(list[i - 1], list[0]);
        siftdown(list, i - 1, 0, cmp);
    }
    return list;
}
struct node {
    int val;
    node* left;
    node* right;
};
node tr[1000050];
void QuickSortCount(int* list, int listSize, long long& cmp) {
    for (int i = 1; i <= listSize + 1; i++) {
        tr[i].val         = i;
        tr[i].left        = tr + i - 1;
        tr[i].left->right = tr + i;
    }
    for (int i = listSize - 1; i >= 0; i--) {
        cmp += tr[list[i]].right->val - tr[list[i]].left->val - 2;
        tr[list[i]].right->left = tr[list[i]].left;
        tr[list[i]].left->right = tr[list[i]].right;
        tr[list[i]].left        = nullptr;
        tr[list[i]].right       = nullptr;
    }
}

int main() {
    int N, k;
    long long cmp = 0;
    scanf("%d %d", &N, &k);
    for (int i = 0; i < N; ++i)
        scanf("%d", &ll[i]);
    switch (k) {
    case 1:
        HeapSort(ll, N, cmp);
        break;
    case 2:
        MergeSort(ll, N, cmp);
        break;
    case 3:
        QuickSortCount(ll, N, cmp);
        break;
    }
    printf("%lld", cmp);
    return 0;
}