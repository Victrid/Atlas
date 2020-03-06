#include <iostream>
#include <stdio.h>

using namespace std;

int bp(int N, int* spis, int poisk) {
    int min = 0, max = N - 1, mid;
    if (poisk >= spis[max])
        return N;
    if (poisk < spis[min])
        return 0;
    while (min <= max) {
        mid = (min + max) / 2;
        if (poisk == spis[mid])
            return mid + 1;
        else if (poisk < spis[mid])
            max = mid - 1;
        else
            min = mid + 1;
    }
    return 0;
}
int main() {
    //* scanf and printf to reduce time
    int N, k, b, c;
    cin >> N;
    int* spis = new int[N];
    for (int i = 0; i < N; i++)
        scanf("%d", spis + i);
    scanf("%d", &k);
    int* otv = new int[k];
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &b, &c);
        otv[i] = bp(N, spis, (b * b / c / 4));
    }
    for (int i = 0; i < k; i++) {
        if (i)
            printf("\n");
        printf("%d", otv[i]);
    }
    return 0;
}