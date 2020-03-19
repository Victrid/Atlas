#include <iomanip>
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
    for (int i = 0; i < listSize; i++) {
        list[i] = tmplist[i];
    }
    return list;
}

int main() {
    int n, m;
    cin >> n >> m;
    int size        = n * m;
    int* hgt        = new int[size];
    long long* hgt2 = new long long[size];
    for (int i = 0; i < size; i++) {
        cin >> hgt[i];
    }
    long long vol, existvol = 0;
    double ht = 0;
    cin >> vol;
    MergeSort(hgt, size); //from small to big
    hgt2[0] = 0;
    for (int i = 1; i < size; i++) {
        hgt2[i] = (hgt[i] - hgt[i - 1]) * i;
    }
    int hg = 0;
loop:
    existvol += hgt2[hg];
    if (existvol == vol) {
        ht = hgt[hg];
        goto ans;
    }
    if (existvol > vol) {
        ht = hgt[hg];
        ht -= (double)(existvol - vol) / (double)hg;
        goto ans;
    }
    hg++;
    if (hg == size) {
        ht = hgt[size - 1];
        ht += (double)(vol - existvol) / (double)size;
        goto ans;
    }
    goto loop;
ans:
    cout << setiosflags(ios::fixed) << setprecision(2) << ht << endl
         << (double)hg / (double)size * 100.0;
    return 0;
}