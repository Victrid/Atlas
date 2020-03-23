#include <cstring>
#include <iostream>
using namespace std;
int* MergeSort(int* list, int listSize) {
    if (listSize == 1)
        return list;
    if (listSize == 2) {
        if (list[0] > list[1]) {
            int temp = list[0];
            list[0]  = list[1];
            list[1]  = temp;
            return list;
        }
        return list;
    }
    int* tmplist = new int[listSize];
    int* llst    = MergeSort(list, listSize / 2);
    int* rlst    = MergeSort(list + listSize / 2, listSize - listSize / 2);
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
    memcpy(list, tmplist, sizeof(int) * listSize);
    delete[] tmplist;
    return list;
}
int main() {
    int n;
    cin >> n;
    int* l1 = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &l1[i]);
    MergeSort(l1, n);
    long long ans = 0;
    int lf, rf;
    if (n % 2) {
        lf = n / 2;
        rf = n / 2;
    } else {
        lf = n / 2 - 1;
        rf = n / 2;
    }
    while (lf != -1) {
        //! the digits' problem
        ans += (long long)(rf - lf) * (long long)(l1[rf] - l1[lf]);
        lf--;
        rf++;
        //need to be moded
        ans %= 1000000007;
    }
    cout << ans;
    return 0;
}