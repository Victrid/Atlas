#include <cstring>
#include <iostream>

using namespace std;

int pharse(char chz) {
    if (chz == ' ')
        return 0;
    return chz - 'A' >= 26 ? chz - 'a' + 27 : chz - 'A' + 1;
}
int main() {
    string chs;
    int ans = 0;
    getline(cin, chs);
    for (int i = 0; chs[i] != '\0'; i++) {
        ans += (i + 1) * pharse(chs[i]);
    }
    cout << ans;
    return 0;
}
