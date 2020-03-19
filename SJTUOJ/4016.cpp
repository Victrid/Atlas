#include <iostream>
//! Ugly
using namespace std;
int maxnum = -1000;
int inline maxi(int a, int b) { return a > b ? a : b; }
int inline mini(int a) { return a <= 24 ? a : -1000; }
int polirovat(int a, int b, int calctype) {
    switch (calctype) {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    case 3:
        return a / b;
    case 4:
        return b - a;
    case 5:
        return b / a;
    }
    return 0;
}
int summation(int c1) {
    maxnum = maxi(mini(c1), maxnum);
    return maxnum;
}
int maxa(int c1, int c2) {
    for (int i = 0; i < 6; i++)
        if ((i != 3 && i != 5) || (c2 != 0 && i == 3 && (!(c1 % c2))) || (c1 != 0 && i == 5 && (!(c2 % c1))))
            summation(polirovat(c1, c2, i));
    return maxnum;
}
int maxa(int c1, int c2, int c3) {
    for (int i = 0; i < 6; i++) {
        if ((i != 3 && i != 5) || (c2 != 0 && i == 3 && (!(c1 % c2))) || (c1 != 0 && i == 5 && (!(c2 % c1))))
            summation(maxa(polirovat(c1, c2, i), c3));
        if ((i != 3 && i != 5) || (c3 != 0 && i == 3 && (!(c1 % c3))) || (c1 != 0 && i == 5 && (!(c3 % c1))))
            summation(maxa(polirovat(c1, c3, i), c2));
        if ((i != 3 && i != 5) || (c3 != 0 && i == 3 && (!(c2 % c3))) || (c2 != 0 && i == 5 && (!(c3 % c2))))
            summation(maxa(polirovat(c2, c3, i), c1));
    }
    return maxnum;
}
int maxa(int c1, int c2, int c3, int c4) {
    for (int i = 0; i < 6; i++) {
        if ((i != 3 && i != 5) || (c2 != 0 && i == 3 && (!(c1 % c2))) || (c1 != 0 && i == 5 && (!(c2 % c1))))
            summation(maxa(polirovat(c1, c2, i), c3, c4));
        if ((i != 3 && i != 5) || (c3 != 0 && i == 3 && (!(c1 % c3))) || (c1 != 0 && i == 5 && (!(c3 % c1))))
            summation(maxa(polirovat(c1, c3, i), c2, c4));
        if ((i != 3 && i != 5) || (c3 != 0 && i == 3 && (!(c2 % c3))) || (c2 != 0 && i == 5 && (!(c3 % c2))))
            summation(maxa(polirovat(c2, c3, i), c1, c4));
        if ((i != 3 && i != 5) || (c4 != 0 && i == 3 && (!(c1 % c4))) || (c1 != 0 && i == 5 && (!(c4 % c1))))
            summation(maxa(polirovat(c1, c4, i), c3, c2));
        if ((i != 3 && i != 5) || (c4 != 0 && i == 3 && (!(c2 % c4))) || (c2 != 0 && i == 5 && (!(c4 % c2))))
            summation(maxa(polirovat(c2, c4, i), c1, c3));
        if ((i != 3 && i != 5) || (c4 != 0 && i == 3 && (!(c3 % c4))) || (c3 != 0 && i == 5 && (!(c4 % c3))))
            summation(maxa(polirovat(c3, c4, i), c1, c2));
        for (int j = 0; j < 6; j++) {
            if (((i != 3 && i != 5) || (c2 != 0 && i == 3 && (!(c1 % c2))) ||
                 (c1 != 0 && i == 5 && (!(c2 % c1)))) &&
                ((j != 3 && j != 5) || (c4 != 0 && j == 3 && (!(c3 % c4))) || (c3 != 0 && j == 5 && (!(c4 % c3)))))
                summation(maxa(polirovat(c1, c2, i), polirovat(c3, c4, j)));
            if (((i != 3 && i != 5) || (c3 != 0 && i == 3 && (!(c2 % c3))) ||
                 (c2 != 0 && i == 5 && (!(c3 % c2)))) &&
                ((j != 3 && j != 5) || (c4 != 0 && j == 3 && (!(c1 % c4))) || (c1 != 0 && j == 5 && (!(c4 % c1)))))
                summation(maxa(polirovat(c2, c3, i), polirovat(c1, c4, j)));
            if (((i != 3 && i != 5) || (c4 != 0 && i == 3 && (!(c2 % c4))) ||
                 (c2 != 0 && i == 5 && (!(c4 % c2)))) &&
                ((j != 3 && j != 5) || (c3 != 0 && j == 3 && (!(c1 % c3))) || (c1 != 0 && j == 5 && (!(c3 % c1)))))
                summation(maxa(polirovat(c2, c4, i), polirovat(c1, c3, j)));
        }
    }
    return maxnum;
}
int main() {
    int N, c1, c2, c3, c4;
    cin >> N;
    int* s = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> c1 >> c2 >> c3 >> c4;
        s[i]   = maxa(c1, c2, c3, c4);
        maxnum = -1000;
    }
    for (int i = 0; i < N; i++) {
        if (i)
            cout << endl;
        cout << s[i];
    }
    // int z = 0;
    // for (int c1 = 1; c1 < 14; c1++)
    //     for (int c2 = c1; c2 < 14; c2++)
    //         for (int c3 = c2; c3 < 14; c3++) {
    //             for (int c4 = c3; c4 < 14; c4++) {
    //                 z += !(maxa(c1, c2, c3, c4) == 24);
    //                 maxnum = -1000;
    //             }
    //         }
    // cout << z;
}