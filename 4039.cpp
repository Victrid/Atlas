#include <iostream>
using namespace std;
int main()
{
    int num;
    bool CF=false;
    cin >> num;
    for (int i = 2; i <= num;)
    {
        if (!(num % i))
        {
            num /= i;
            if (CF) cout << ' ';
            cout << i;
            CF = true;
            continue;
        }
        ++i;
    }
    return 0;
}