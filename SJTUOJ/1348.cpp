#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
int timelist[100005] = {0};
int man[1000001];
int woman[1000001];
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
    int N, M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &timelist[i]);
    scanf("%d", &M);
    int mann = 0, frau = 0, proc;
    for (int i = 0; i < M; i++) {
        scanf("%d", &proc);
        if (proc == 1)
            scanf("%d", &man[mann++]);
        else
            scanf("%d", &woman[frau++]);
    }

    MergeSort(man, mann);
    MergeSort(woman, frau);

    int
        current_time   = 0,
        *man_current   = man,
        *woman_current = woman,
        *man_qhead     = man,
        *woman_qhead   = woman,
        *man_end       = man + mann,
        *woman_end     = woman + frau;
    double
        man_wasted   = 0,
        woman_wasted = 0;

    for (int i = 0; i < N; i++) {
        while (*man_qhead <= current_time && man_qhead != man_end)
            man_qhead++;
        while (*woman_qhead <= current_time && woman_qhead != woman_end)
            woman_qhead++;
        while (man_current != man_qhead && woman_current != woman_qhead) {
            man_wasted += current_time - *man_current;
            woman_wasted += current_time - *woman_current;
            man_current++;
            woman_current++;
        }
        current_time += timelist[i];
    }
    current_time -= timelist[N-1];
    while (man_current != man_end) {
        man_wasted += current_time - *man_current;
        man_current++;
    }
    while (woman_current != woman_end) {
        woman_wasted += current_time - *woman_current;
        woman_current++;
    }
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << man_wasted / (double)mann << ' ' << woman_wasted / (double)frau;
    return 0;
}