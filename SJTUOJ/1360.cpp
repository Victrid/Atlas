#include <iostream>
using namespace std;
struct t {
    int t1;
    int t2;
};
t* MergeSort(t* list, int listSize) {
    if (listSize == 1)
        return list;
    if (listSize == 2) {
        if (list[0].t2 > list[1].t2) {
            t temp  = list[0];
            list[0] = list[1];
            list[1] = temp;
            return list;
        }
        return list;
    }
    t* tmplist = new t[listSize];
    t* llst    = MergeSort(list, listSize / 2);
    t* rlst    = MergeSort(list + listSize / 2, listSize - listSize / 2);
    int lct = 0, rct = 0;
    while (lct + rct != listSize) {
        if ((llst[lct].t2 <= rlst[rct].t2 && lct < listSize / 2) || rct >= listSize - listSize / 2) {
            tmplist[lct + rct] = llst[lct];
            lct++;
        } else {
            tmplist[lct + rct] = rlst[rct];
            rct++;
        }
    }
    for (int i = 0; i < listSize; i++) {
        list[i] = tmplist[i];
    }
    return list;
}
inline int maxi(int i1, int i2) {
    return i1 > i2 ? i1 : i2;
}
int main() {
    int n;
    cin >> n;
    t *timeset = new t[n], *moveptr = timeset;
    for (int i = 0; i < n; i++) {
        cin >> timeset[i].t1;
        cin >> timeset[i].t2;
    }
    MergeSort(timeset, n);
    int* totalis = new int[timeset[n - 1].t2 + 1];
    totalis[0]   = 0;
    for (int i = 1; i < timeset[n - 1].t2 + 1; i++) {
        while (moveptr->t2 < i) {
            moveptr++;
        }
        totalis[i] = totalis[i - 1];
        while (moveptr->t2 == i) {
            totalis[i] = maxi(totalis[i], totalis[moveptr->t1] + 1);
            moveptr++;
        }
    }
    cout << totalis[timeset[n - 1].t2];
    return 0;
}