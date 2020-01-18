#include <iostream>
using namespace std;
int next(bool table[], int total, int start, int step);
int main()
{
    int N;
    int M;
    int start = 0;
    cin >> N >> M;
    bool *table = new bool[N];
    for (int n = 0; n < N; n++)
        table[n] = true;
    start = 0;
    for (int i = 1; i <= N; i++)
    {
        start = next(table, N, start, M);
        table[start] = false;
    }
    cout << start + 1;
    return 0;
}
int next(bool table[], int total, int start, int step)
{
    while (step != 0)
    {
        if (table[start])
            step--;
        if (step == 0)
            return start;
        ++start;
        if (start == total)
            start = 0;
    }
}
