#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//草，这个HS08TTC，改都不改一下
char input[1000001] = {'\0'};
void printpreorder(int current, int total) {
    if (current >= total)
        return;
    putchar(input[current]);
    printpreorder((current << 1) + 1, total);
    printpreorder((current << 1) + 2, total);
    return;
}
void printinorder(int current, int total) {
    if (current >= total)
        return;
    printinorder((current << 1) + 1, total);
    putchar(input[current]);
    printinorder((current << 1) + 2, total);
    return;
}
void printpostorder(int current, int total) {
    if (current >= total)
        return;
    printpostorder((current << 1) + 1, total);
    printpostorder((current << 1) + 2, total);
    putchar(input[current]);
    return;
}
void estkpreorder(int current, int total) {
    if (current >= total)
        return;
    input[current] = getchar();
    estkpreorder((current << 1) + 1, total);
    estkpreorder((current << 1) + 2, total);
    return;
}
void estkinorder(int current, int total) {
    if (current >= total)
        return;
    estkinorder((current << 1) + 1, total);
    input[current] = getchar();
    estkinorder((current << 1) + 2, total);
    return;
}
void estkpostorder(int current, int total) {
    if (current >= total)
        return;
    estkpostorder((current << 1) + 1, total);
    estkpostorder((current << 1) + 2, total);
    input[current] = getchar();
    return;
}

int main() {
    int t, total, chr;
    int ordf;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &total);
        do {
            chr = getchar();
        } while (chr == ' ');
        chr = getchar();
        switch (chr) {
        case 'N':
            ordf = 1;
            break;
        case 'R':
            ordf = 0;
            break;
        case 'O':
            ordf = 2;
            break;
        }
        do {
            chr = getchar();
        } while (chr != ' ');
        chr = getchar();
        if (chr == 'E')
            ordf += 10;
        do {
            chr = getchar();
        } while (chr != '\n');

        switch (ordf) {
        case 0:
            //PREORDER DECODE
            estkpreorder(0, total);
            input[total] = '\0';
            puts(input);
            break;
        case 1:
            //INORDER DECODE
            estkinorder(0, total);
            input[total] = '\0';
            puts(input);
            break;
        case 2:
            //POSTORDER DECODE
            estkpostorder(0, total);
            input[total] = '\0';
            puts(input);
            break;
        case 10:
            //PREORDER ENCODE
            scanf("%s", input);
            printpreorder(0, total);
            break;
        case 11:
            //INORDER ENCODE
            scanf("%s", input);
            printinorder(0, total);
            break;
        case 12:
            //POSTORDER ENCODE
            scanf("%s", input);
            printpostorder(0, total);
            break;
        }
        putchar('\n');
    }
    return 0;
}