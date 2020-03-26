#include <iostream>
using namespace std;
struct level {
    int* likes;
    int* hates;
    int maxdishes;
    int man;
};
level getinput() {
    int dish, man;
    cin >> dish >> man;
    int* likes = new int[man]();
    int* hates = new int[man]();
    int tempproc;
    cin.get();
    for (int i = 0; i < man; ++i) {
        for (int cnt = 0;; ++cnt) {
            cin >> tempproc;
            if (tempproc >= 0)
                likes[i] += 1 << (tempproc - 1);
            else
                hates[i] += 1 << (-tempproc - 1);
            if (cin.get() == '\n')
                break;
        }
    }
    return level{likes, hates, dish, man};
} //everyman

int main() {
    int t;
    cin >> t;
    bool* ans = new bool[t]();
    for (int i = 0; i < t; i++) {
        level input = getinput();
        int maxn    = (1 << (input.maxdishes + 1)) - 1;
        //here seems do not cost so much time...
        // That's strange.. it's o(2^n)
        for (int z = 0; z < maxn; z++) {
            for (int i = 0; i < input.man; i++) {
                if ((z & input.likes[i]) == 0 && (~z & input.hates[i]) == 0)
                    goto next;
            }
            ans[i] = true;
            goto nextnext;
            next:;
        }
        ans[i] = false;
        nextnext:;
    }
    for (int i = 0; i < t; i++) {
        cout << (ans[i] ? "Bingo!\n" : "Sigh...\n");
    }
    return 0;
}