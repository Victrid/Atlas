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
char input[1000001] = {'\0'};
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
char treerecv[1000001] = {'\0'};
//queue and stack
//content: char*, default empty: nullptr
char* datastorage[4000003] = {nullptr};
char** frontptr;
char** endptr;
void clearqueue() {
    frontptr = datastorage;
    endptr   = datastorage + 1;
}
void clearstack() {
    endptr = datastorage;
}
void enqueue(char* cr) {
    *endptr = cr;
    endptr++;
}
void enstack(char* cr) {
    *endptr = cr;
    endptr++;
}
char* destack() {
    if (endptr == datastorage)
        return nullptr;
    else
        endptr--;
    return *endptr;
}
char* dequeue() {
    if (frontptr + 1 == endptr)
        return nullptr;
    else
        frontptr++;
    return *frontptr;
}
void estkpreorder(ltrav<char, treerecv> s, int total) {
    if (s.current >= total)
        return;
    enqueue(&(s.val));
    estkpreorder(s.left(), total);
    estkpreorder(s.right(), total);
    return;
}
void estkinorder(ltrav<char, treerecv> s, int total) {
    if (s.current >= total)
        return;
    estkinorder(s.left(), total);
    enqueue(&(s.val));
    estkinorder(s.right(), total);
    return;
}
void estkpostorder(ltrav<char, treerecv> s, int total) {
    if (s.current >= total)
        return;
    estkpostorder(s.left(), total);
    estkpostorder(s.right(), total);
    enqueue(&(s.val));
    return;
}
void vldr(int total) {
    for (int i = 0; i < total; i++) {
        *dequeue() = input[i];
    }
    for (int i = 0; i < total; i++) {
        putchar(treerecv[i]);
    }
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
        fgets(input, sizeof(input), stdin);
        input[total] = '\0';
        switch (ordf) {
        case 0:
            //PREORDER DECODE
            clearqueue();
            estkpreorder(ltrav<char, treerecv>{0, treerecv[0]}, total);
            vldr(total);
            break;
        case 1:
            //INORDER DECODE
            clearqueue();
            estkinorder(ltrav<char, treerecv>{0, treerecv[0]}, total);
            vldr(total);
            break;
        case 2:
            //POSTORDER DECODE
            clearqueue();
            estkpostorder(ltrav<char, treerecv>{0, treerecv[0]}, total);
            vldr(total);
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