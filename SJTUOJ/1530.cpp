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
char input[1000001] = {'\0'};
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
void estkpreorder(ltrav<char, input> s, int total) {
    if (s.current >= total)
        return;
    s.val = getchar();
    estkpreorder(s.left(), total);
    estkpreorder(s.right(), total);
    return;
}
void estkinorder(ltrav<char, input> s, int total) {
    if (s.current >= total)
        return;
    estkinorder(s.left(), total);
    s.val = getchar();
    estkinorder(s.right(), total);
    return;
}
void estkpostorder(ltrav<char, input> s, int total) {
    if (s.current >= total)
        return;
    estkpostorder(s.left(), total);
    estkpostorder(s.right(), total);
    s.val = getchar();
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
            estkpreorder(ltrav<char, input>{0, input[0]}, total);
            input[total] = '\0';
            printf("%s", input);
            break;
        case 1:
            //INORDER DECODE
            estkinorder(ltrav<char, input>{0, input[0]}, total);
            input[total] = '\0';
            printf("%s", input);
            break;
        case 2:
            //POSTORDER DECODE
            estkpostorder(ltrav<char, input>{0, input[0]}, total);
            input[total] = '\0';
            printf("%s", input);
            break;
        case 10:
            //PREORDER ENCODE
            fgets(input, sizeof(input), stdin);
            input[total] = '\0';
            printpreorder(ltrav<char, input>{0, input[0]}, total);
            break;
        case 11:
            //INORDER ENCODE
            fgets(input, sizeof(input), stdin);
            input[total] = '\0';
            printinorder(ltrav<char, input>{0, input[0]}, total);
            break;
        case 12:
            //POSTORDER ENCODE
            fgets(input, sizeof(input), stdin);
            input[total] = '\0';
            printpostorder(ltrav<char, input>{0, input[0]}, total);
            break;
        }
        putchar('\n');
    }
    return 0;
}