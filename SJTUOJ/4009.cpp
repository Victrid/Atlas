#include <iostream>
#include <cstring>
using namespace std;
inline int div(int length, int index, int division) {
    return (index * (length / division) % (length - 1) + (length - 1)*(index == length - 1));
}
int main() {
    char cp[100];
    char ck[100];
    cin.getline(ck, 100);
    cin.getline(cp, 100);
    short int size = strlen(cp);
    if (cp[0] != ck[0] || size != strlen(ck)) {
        cout << "No Solution";
        return 0;
    }
    for (int i = size / 2; i >= 1; i--) {
        if (cp[i] == ck[1] && !(size % i)) {
            for (int j = 2; j < size; j++) {
                if (cp[div(size, j, size / i)] != ck[j])
                    goto z;
            }
            cout << size / i;
            return 0;
        }
    z:;
    }
    cout << "No Solution";
    return 0;
}