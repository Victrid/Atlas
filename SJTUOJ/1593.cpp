#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct mouse {
    int number;
    int score;
    int strength;
};

mouse tmplist[200005];
mouse ml[200005];

mouse* MergeSort(mouse* list, int listSize) {
    if (listSize == 1)
        return list;
    if (listSize == 2) {
        if (list[0].score < list[1].score || (list[0].score == list[1].score && list[0].number > list[1].number)) {
            mouse temp = list[0];
            list[0]    = list[1];
            list[1]    = temp;
            return list;
        }
        return list;
    }

    mouse* llst = MergeSort(list, listSize / 2);
    mouse* rlst = MergeSort(list + listSize / 2, listSize - listSize / 2);
    int lct = 0, rct = 0;
    while (lct + rct != listSize) {
        if (((llst[lct].score > rlst[rct].score || (llst[lct].score == rlst[rct].score && llst[lct].number < rlst[rct].number)) && lct < listSize / 2) || rct >= listSize - listSize / 2) {
            tmplist[lct + rct] = llst[lct];
            lct++;
        } else {
            tmplist[lct + rct] = rlst[rct];
            rct++;
        }
    }
    memcpy(list, tmplist, listSize * sizeof(mouse));
    return list;
}

int main() {
    int N, R;
    cin >> N >> R;
    for (int i = 0; i < 2 * N; i++) {
        ml[i].number = i + 1;
        scanf("%d", &(ml[i].score));
    }
    for (int i = 0; i < 2 * N; i++) {
        scanf("%d", &(ml[i].strength));
    }
    MergeSort(ml, 2 * N);
    for (int i = 0; i < R; i++) {
        for (int i = 0; i < 2 * N; i += 2) {
            if (ml[i].strength > ml[i + 1].strength)
                ml[i].score += 2;
            if (ml[i].strength == ml[i + 1].strength)
                ml[i].score++, ml[i + 1].score++;
            if (ml[i].strength < ml[i + 1].strength)
                ml[i + 1].score += 2;
        }
        MergeSort(ml, 2 * N);
    }
    for (int i = 0; i < 2 * N; i++) {
        if (i)
            printf("%c",' ');
        printf("%d",ml[i].number);
    }
    return 0;
}