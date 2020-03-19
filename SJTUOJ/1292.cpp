#include <iostream>
using namespace std;
//Cyka. I'm a blind starcraft player
//I'm a blind starcraft player
//I'm a blind starcraft player
inline int swapi(int& i, int& j) {
    int temp = i;
    i        = j;
    j        = temp;
    return 0;
}
int main() {
    int numbers;
    int maxround[10]   = {0};
    int totalsteps[10] = {0};
    int groupcount     = 0;
    while (~scanf("%d", &numbers)) {
        int* ff              = new int[numbers + 1];
        maxround[groupcount] = 0;
        for (int i = 1; i <= numbers; i++)
            cin >> ff[i];
        for (int i = 1; i <= numbers; i++) {
            if (ff[i] != i) {
                int round = 0;
                //looping
                int tws1 = i, tws2;
                while (true) {
                    for (tws2 = i; ff[tws2] != tws1; tws2++)
                        ;
                    swap(ff[tws1], ff[tws2]);
                    totalsteps[groupcount]++;
                    round++;
                    if (round > 2)
                        round = 2;
                    if (ff[tws2] == tws2) {
                        maxround[groupcount] = maxround[groupcount] > round ? maxround[groupcount] : round;
                        break;
                    }
                    tws1 = tws2;
                }
            }
        }
        groupcount++;
    }

    for (int i = 0; i < groupcount; i++) {
        if (i)
            cout << endl;
        cout << totalsteps[i] << endl
             << maxround[i];
    }
    return 0;
}