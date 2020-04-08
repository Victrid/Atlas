#include <cstring>
#include <iostream>
using namespace std;
//binary answer
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
int place[100000], place_count, knife_count;
bool check(int mind) {
    int i = 0, total = 0;
    for (int j = 0; j < place_count; j++) {
        if (place[j] - place[i] >= mind) {
            i = j;
            total++;
            if (total == knife_count - 1)
                return 1;
        }
    }
    return 0;
};
int main() {
    cin >> place_count >> knife_count;
    for (int i = place_count; i > 0; i--) {
        scanf("%d", place + i - 1);
    }
    MergeSort(place, place_count);
    int l = 0,
        r = place[place_count - 1];
    while (l < r) {
        if (check((l + r + 1) / 2))
            l = (l + r + 1) / 2;
        else
            r = (l + r - 1) / 2;
    }
    cout << l;
    return 0;
}