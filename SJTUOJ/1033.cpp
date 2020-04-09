#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
//EXCEPTIONS
struct ENOB {};
struct EDIV {};

struct atoma {
    //value:
    // 1 2 3 4 5  6
    // + - * / ^ (-)
    //priority level:
    // 00111000
    //    |-----------  + - = 1, * / = 2 ^ = 3 - = 4
    //        |-------- number of digit. (^ in 999-ans)
    //   |-------------- bracketcount
    bool isoperator;
    long long value;
    int priority;
};
atoma ps[100];
atoma zero{0, 0, 0};
struct tree {
    atoma& at;
    tree* left;
    tree* right;
    tree(atoma& a, tree* l, tree* r) : at(a), left(l), right(r){};
    ~tree() {
        if (left != nullptr)
            delete left;
        if (right != nullptr)
            delete right;
    }
};
int read() {
    char ch = 0;

    int
        chcount    = 0,
        bracket    = 0,
        atomaplace = 0,
        digit      = 0;

    long long totalis = 0;
    while (true) {
        if (ch < '0' || ch > '9') {
            if (digit) {
                ps[atomaplace++] = atoma{false, totalis, 0};
            }
            digit   = 0;
            totalis = 0;
            switch (ch) {
            case '+':
                ps[atomaplace++] = atoma{true, 1, bracket * 100000 + 10000 + 1000 - chcount};
                break;
            case '-':
                if (atomaplace == 0 || ps[atomaplace - 1].isoperator) {
                    ps[atomaplace++] = atoma{true, 6, bracket * 100000 + 40000 + 1000 - chcount};
                } else
                    ps[atomaplace++] = atoma{true, 2, bracket * 100000 + 10000 + 1000 - chcount};
                break;
            case '*':
                ps[atomaplace++] = atoma{true, 3, bracket * 100000 + 20000 + 1000 - chcount};
                break;
            case '/':
                ps[atomaplace++] = atoma{true, 4, bracket * 100000 + 20000 + 1000 - chcount};
                break;
            case '^':
                ps[atomaplace++] = atoma{true, 5, bracket * 100000 + 30000 + chcount};
                break;
            case '(':
                bracket++;
                break;
            case ')':
                if (bracket == 0)
                    throw(ENOB());
                bracket--;
                break;
            case '\n':
                //!!!!!!I'm too foolish!
                if (bracket != 0)
                    throw(ENOB());
                return atomaplace;
            default:
                break;
            }
            ch = getchar();
            chcount++;
        } else {
            digit++;
            totalis = totalis * 10 + (ch - '0');
            ch      = getchar();
            chcount++;
        }
    }
}
tree* search(int left, int right) {
    if (left > right)
        return new tree(zero, nullptr, nullptr);
    if (left == right)
        return new tree(ps[left], nullptr, nullptr);
    int min = 1e9;
    int loc = -1;
    for (int i = left; i <= right; i++) {
        if (ps[i].priority != 0 && ps[i].priority < min) {
            loc = i;
            min = ps[i].priority;
        }
    }
    tree* lf = search(left, loc - 1);
    tree* rt = search(loc + 1, right);
    return new tree(ps[loc], lf, rt);
}

long long integerpow(long long base, long long power) {
    long long ans = 1, tmp = base;
    while (power > 0) {
        if (power & 1)
            ans *= tmp;
        power >>= 1;
        tmp *= tmp;
    }
    return ans;
}

tree* shorten(tree* root) {
    if (!root->at.isoperator) {
        return root;
    }
    shorten(root->left);
    shorten(root->right);
    switch (root->at.value) {
    case 1:
        root->at.value = root->left->at.value + root->right->at.value;
        break;
    case 2:
        root->at.value = root->left->at.value - root->right->at.value;
        break;
    case 3:
        root->at.value = root->left->at.value * root->right->at.value;
        break;
    case 4:
        if (root->right->at.value == 0)
            throw(EDIV());
        root->at.value = root->left->at.value / root->right->at.value;
        break;
    case 6:
        root->at.value = root->left->at.value - root->right->at.value;
        break;
    case 5:
        if (root->right->at.value == 0)
            throw(EDIV());
        root->at.value = integerpow(root->left->at.value, root->right->at.value);
        break;
    }
    root->at.isoperator = false;
    root->at.priority   = 0;
    delete root->left;
    delete root->right;
    root->left  = nullptr;
    root->right = nullptr;
    return root;
}

int main() {
    int atomacount;
    try {
        atomacount = read();
    } catch (ENOB) {
        cout << "Error" << endl;
        return 0;
    }
    tree* lg = search(0, atomacount - 1);
    try {
        cout << shorten(lg)->at.value << endl;
    } catch (EDIV) {
        cout << "Error" << endl;
        return 0;
    }
    return 0;
}