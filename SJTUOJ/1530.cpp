#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//草，这个HS08TTC，改都不改一下
template <typename T, T* seq>
struct ltrav {
    int current;
    T& val;
    ltrav<T, seq> left() {
        return ltrav<T, seq>{(current << 1) + 1, seq[(current << 1) + 1]};
    }
    ltrav<T, seq> right() {
        return ltrav<T, seq>{(current << 1) + 2, seq[(current << 1) + 2]};
    }
    ltrav<T, seq> father() {
        return ltrav<T, seq>{((current + 1) << 1) - 1, seq[((current + 1) << 1) - 1]};
    }
};
//1000001
char input[20] = {'\0'};
//queue and stack
char datastorage[4000003] = {'\0'};
char* frontptr;
char* endptr;
void clearqueue() {
    frontptr = datastorage;
    endptr   = datastorage + 1;
}
void clearstack() {
    endptr = datastorage;
}
void enqueue(char cr) {
    *endptr = cr;
    endptr++;
}
void enstack(char cr) {
    *endptr = cr;
    endptr++;
}
char destack() {
    if (endptr == datastorage)
        return '\0';
    else
        endptr--;
    return *endptr;
}
char dequeue() {
    if (frontptr + 1 == endptr)
        return '\0';
    else
        frontptr++;
    return *frontptr;
}
// group of encode CHECK OK
void printpreorder(ltrav<char, input> s, int total) {
    if (s.current >= total)
        return;
    putchar(s.val);
    printpreorder(s.left(), total);
    printpreorder(s.right(), total);
    return;
}
void printinorder(ltrav<char, input> s, int total) {
    if (s.current >= total)
        return;
    printinorder(s.left(), total);
    putchar(s.val);
    printinorder(s.right(), total);
    return;
}
void printpostorder(ltrav<char, input> s, int total) {
    if (s.current >= total)
        return;
    printpostorder(s.left(), total);
    printpostorder(s.right(), total);
    putchar(s.val);
    return;
}

//group of decode
int get_full_tree(int total) {
    int p = 1;
    while (p - 1 < total)
        p *= 2;
    return p - 1;
}
void recoverinorder(int l, int r, int total, int treetotal) {
    if ((l + r) / 2 >= treetotal)
        return;
    if ((l + r) / 2 < total)
        putchar(input[(l + r) / 2]);
    if (l == r)
        return;
    recoverinorder(l, (l + r) / 2 - 1, total, treetotal);
    recoverinorder((l + r) / 2 + 1, r, total, treetotal);
}
void recoverpreorder(int l, int r, int total, int treetotal) {
    if (l >= treetotal)
        return;
    if (l < total)
        putchar(input[l]);
    if (l == r)
        return;
    recoverpreorder(l + 1, (l + r) / 2, total, treetotal);
    recoverpreorder((l + r) / 2 + 1, r, total, treetotal);
}
void recoverpostorder(int l, int r, int total, int treetotal) {
    if (r >= treetotal)
        return;
    if (r < total)
        putchar(input[r]);
    if (l == r)
        return;
    recoverpostorder(l, (l + r) / 2 - 1, total, treetotal);
    recoverpostorder((l + r) / 2, r - 1, total, treetotal);
}

int main() {
    int t, total, chr;
    int ordf, chdf;
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
        fgets(input, sizeof(input), stdin);
        input[total] = '\0';
        switch (ordf) {
        case 0:
            //PREORDER DECODE
            recoverpreorder(0, get_full_tree(total), total, get_full_tree(total));
            break;
        case 1:
            //INORDER DECODE
            recoverinorder(0, get_full_tree(total), total, get_full_tree(total));
            break;
        case 2:
            //POSTORDER DECODE
            recoverinorder(0, get_full_tree(total), total, get_full_tree(total));
            break;
        case 10:
            //PREORDER ENCODE
            printpreorder(ltrav<char, input>{0, input[0]}, total);
            break;
        case 11:
            //INORDER ENCODE
            printinorder(ltrav<char, input>{0, input[0]}, total);
            break;
        case 12:
            //POSTORDER ENCODE
            printpostorder(ltrav<char, input>{0, input[0]}, total);
            break;
        }
        putchar('\n');
    }
    return 0;
}