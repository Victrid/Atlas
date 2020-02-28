#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int check() {
    int bednum      = 0;
    int current     = 0;
    int badcustomer = 0;
    cin >> bednum;
    if (!bednum)
        return -1;
    char process = cin.get();
    unordered_map<char, int> jiten;
    while (cin.get(process) && process != '\n') {
        if (jiten.find(process) == jiten.end()) {
            jiten[process] = 1;
            current++;
            if (current > bednum) {
                current--;
                jiten[process] = 2;
                badcustomer++;
            }
        } else {
            if (jiten[process] != 2)
                current--;
            jiten[process] = 0;
        }
    }
    return badcustomer;
}
int main() {
    vector<int> board;
    int process = check();
    while (process != -1) {
        board.push_back(process);
        process = check();
    }
    for (auto it = board.begin(); it < board.end(); it++) {
        if (it != board.begin())
            cout << endl;
        cout << (*it ? to_string(*it) + " customer(s) walked away." : "All customers tanned successfully.");
    }
    return 0;
}