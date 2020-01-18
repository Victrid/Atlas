#include <iostream>
#include <cstring>

#define ODD 1
#define EVEN 0

using namespace std;

string input;
int length = 0;
int Leftrecorder = 0, Rightrecorder = 0;

int update(int i, int pattern)
{
    int leftlimit, rightlimit;
    if (pattern == ODD)
    {
        leftlimit = i;
        rightlimit = i;
    }
    else
    {
        if (i + 1 >= length || input[i] != input[i + 1])
            return 0;
        leftlimit = i;
        rightlimit = i + 1;
    }

    while (leftlimit - 1 >= 0 && rightlimit + 1 <= length - 1 && input[leftlimit - 1] == input[rightlimit + 1])
    {
        --leftlimit;
        ++rightlimit;
    }
    if (rightlimit - leftlimit > 0 && rightlimit - leftlimit > Rightrecorder - Leftrecorder)
    {
        Leftrecorder = leftlimit;
        Rightrecorder = rightlimit;
    }
}

int main()
{
    cin >> input;
    length = input.length();
    for (int i = 0; i < length; ++i)
    {
        update(i, ODD);
        update(i, EVEN);
    }
    if (Rightrecorder - Leftrecorder)
    {
        cout << Rightrecorder - Leftrecorder + 1 << endl;
        for (int i = Leftrecorder; i <= Rightrecorder; ++i)
            cout << input[i];
    }
    else
        cout << 0;
    return 0;
}