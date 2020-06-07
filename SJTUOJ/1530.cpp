#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//听说要用cin，👴服🌶
char input[1000001]  = {'\0'};
char input2[1000001] = {'\0'};
int indexa;
void printpreorder(int current, int total) {
    if (current >= total)
        return;
    cout << (char)input[current];
    printpreorder((current << 1) + 1, total);
    printpreorder((current << 1) + 2, total);
    return;
}
void printinorder(int current, int total) {
    if (current >= total)
        return;
    printinorder((current << 1) + 1, total);
    cout << (char)input[current];
    printinorder((current << 1) + 2, total);
    return;
}
void printpostorder(int current, int total) {
    if (current >= total)
        return;
    printpostorder((current << 1) + 1, total);
    printpostorder((current << 1) + 2, total);
    cout << (char)input[current];
    return;
}
void estkpreorder(int current, int total) {
    if (current >= total)
        return;
    input[current] = input2[indexa++];
    estkpreorder((current << 1) + 1, total);
    estkpreorder((current << 1) + 2, total);
    return;
}
void estkinorder(int current, int total) {
    if (current >= total)
        return;
    estkinorder((current << 1) + 1, total);
    input[current] = input2[indexa++];
    estkinorder((current << 1) + 2, total);
    return;
}
void estkpostorder(int current, int total) {
    if (current >= total)
        return;
    estkpostorder((current << 1) + 1, total);
    estkpostorder((current << 1) + 2, total);
    input[current] = input2[indexa++];
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t, total;
    char chr[10];
    int ordf;
    cin >> t;
    while (t--) {
        cin >> total;
        cin >> chr;
        ordf = 0;
        if (!strcmp(chr, "INORDER"))
            ordf += 1;
        if (!strcmp(chr, "POSTORDER"))
            ordf += 2;
        cin >> chr;
        if (!strcmp(chr, "DECODE"))
            ;
        if (!strcmp(chr, "ENCODE"))
            ordf += 10;

        switch (ordf) {
        case 0:
            //PREORDER DECODE
            cin >> input2;
            indexa = 0;
            estkpreorder(0, total);
            input[total] = '\0';
            cout << input;
            break;
        case 1:
            //INORDER DECODE
            cin >> input2;
            indexa = 0;
            estkinorder(0, total);
            input[total] = '\0';
            cout << input;
            break;
        case 2:
            //POSTORDER DECODE
            cin >> input2;
            indexa = 0;
            estkpostorder(0, total);
            input[total] = '\0';
            cout << input;
            break;
        case 10:
            //PREORDER ENCODE
            cin >> input;
            printpreorder(0, total);
            break;
        case 11:
            //INORDER ENCODE
            cin >> input;
            printinorder(0, total);
            break;
        case 12:
            //POSTORDER ENCODE
            cin >> input;
            printpostorder(0, total);
            break;
        }
        cout << endl;
    }
    return 0;
}