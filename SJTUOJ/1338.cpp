#include <iostream>

using namespace std;

long int* MergeSort(long int* list, int listSize) {
    if (listSize == 1)
        return list;
    if (listSize == 2) {
        if (list[0] > list[1]) {
            long int temp = list[0];
            list[0]  = list[1];
            list[1]  = temp;
            return list;
        }
        return list;
    }
    long int* tmplist = new long int[listSize];
    long int* llst    = MergeSort(list, listSize / 2);
    long int* rlst    = MergeSort(list + listSize / 2, listSize - listSize / 2);
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
    for (int i = 0; i < listSize; i++)
        list[i] = tmplist[i];

    return list;
}

int main() {
    //Chebyshyov neravyenctvo
    int m;
    cin >> m;
    //! MUST BE A LONG INT!
    long int* l1 = new long int[m];
    long int* l2 = new long int[m];
    for (int i = 0; i < m; i++) {
        cin >> l1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l2[i];
    }
    MergeSort(l1, m);
    MergeSort(l2, m);

    // for (int i = 0; i < m; i++) {
    //     cout << l1[i] << ' ';
    // }
    long int max = 0, min = 0;
    for (int i = 0; i < m; i++) {
        max += l1[i] * l2[i];
        min += l1[i] * l2[m - i - 1];
    }
    cout << max << ' ' << min;
    return 0;
}