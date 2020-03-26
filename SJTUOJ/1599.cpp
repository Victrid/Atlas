#include <cstdio>
#include <iostream>
//cstdio有幸埋printf，iostream无辜铸cin
using namespace std;
inline bool pairing(char c1, char c2) {
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
}
template <typename T>
class basestack {
private:
    T container[100002];
    T* top_ptr;
    int total;

public:
    basestack() {
        top_ptr = container;
        total   = 0;
    }
    int height() { return total; }
    T push(T p) {
        *top_ptr = p;
        top_ptr++;
        total++;
        return *(top_ptr - 1);
    }
    T* top() { return total ? (top_ptr - 1) : nullptr; }
    T pop() {
        if (total == 0)
            return *top_ptr;
        top_ptr--;
        total--;
        return *top_ptr;
    }
};

class bracketstack {
private:
    basestack<char> container;
    basestack<char*> brstack;
    basestack<char*> trashbin;

public:
    bracketstack(){};
    bool balance() { return (brstack.height() == 0); }
    void operate() {
        int operation;
        char proc;
        scanf("%d", &operation);
        char* ans;
        switch (operation) {
        case 1:
            scanf(" %c", &proc);
            container.push(proc);
            if (brstack.height() != 0 && pairing(**(brstack.top()), proc)) {
                trashbin.push(brstack.pop());
            } else {
                brstack.push(container.top());
            }
            break;
        case 2:
            if (container.height() != 0) {
                if (brstack.height() != 0 && *(brstack.top()) == container.top()) {
                    brstack.pop();
                } else {
                    brstack.push(trashbin.pop());
                }
                //! here change the container at the last.
                container.pop();
            }
            break;
        case 3:
            ans = container.top();
            if (ans == nullptr)
                break;
            printf("%c\n", *(ans));
            break;
        case 4:
            printf(balance() ? "YES\n" : "NO\n");
            break;
        }
    }
};

bracketstack b;

int main() {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        b.operate();
    }
    return 0;
}