#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int* MergeSort(int* list, int listSize) {
    if (listSize == 1)
        return list;
    if (listSize == 2) {
        if (list[0] < list[1]) {
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
        if ((llst[lct] >= rlst[rct] && lct < listSize / 2) || rct >= listSize - listSize / 2) {
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
    int** mat = new int*[n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int[n]();
    }
    for (int i = 0; i < n; i++) {
        int suml = 0;
        char proc;
        cin.get();
        for (int j = 0; j < n; j++) {
            scanf("%c", &proc);
            proc -= '0';
            suml += proc;
            suml *= proc;
            // suml += proc *= proc; /*fatal*/
            mat[j][i] = suml;
        }
    }
    int pzmax = 0;
    int proc  = 0;
    for (int j = 0; j < n; j++) {
        MergeSort(mat[j], n);
        for (int i = 0; i < n; i++) {
            proc  = mat[j][i] * (i + 1);
            pzmax = pzmax > proc ? pzmax : proc;
        }
    }
    cout << pzmax;
    return 0;
}