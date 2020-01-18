#include <iostream>

using namespace std;

bool isMarvel(int number)
{
    while (number % 2 == 0)
        number /= 2;
    while (number % 3 == 0)
        number /= 3;
    while (number % 5 == 0)
        number /= 5;
    while (number % 7 == 0)
        number /= 7;
    return number == 1;
}

int main()
{
    int Minimum, Maximum;
    cin >> Minimum >> Maximum;
    //error leads to quit
    if (Minimum < 1 || Minimum > 99999 || Maximum < 1 || Maximum > 99999 || Minimum > Maximum)
    {
        cout << "error";
        return 0;
    }
    //go through limits
    bool FOUND_FLAG = false;
    for (int i = Minimum; i <= Maximum; i++)
    {
        if (isMarvel(i))
        {
            if (FOUND_FLAG)
                cout << endl;
            FOUND_FLAG = true;
            cout << i;
        }
    }
    if (!FOUND_FLAG)
        cout << "no";
    return 0;
}