#include <cstdio>
#include <iostream>

using namespace std;
//Rewrite without STL
int check() {
    int bednum      = 0;
    int current     = 0;
    int badcustomer = 0;
    scanf("%d", &bednum);
    if (!bednum)
        return -1;
    int avail[1000] = {0};
    getchar();
    char process = getchar();
    while (process != '\n') {
        if (avail[process] == 0) {
            avail[process] = 1;
            current++;
            if (current > bednum) {
                current--;
                avail[process] = 2;
                badcustomer++;
            }
        } else {
            if (avail[process] != 2)
                current--;
            avail[process] = 0;
        }
        process = getchar();
    }
    return badcustomer;
}
int main() {
    int board[10000];
    int bs      = 0;
    int process = check();
    while (process != -1) {
        board[bs] = process;
        bs++;
        process = check();
    }
    for (int i = 0; i < bs; i++) {
        if (board[i] != 0)
            printf("%d customer(s) walked away.\n", board[i]);
        else
            printf("All customers tanned successfully.\n");
    }
    return 0;
}