#include <iostream>

using namespace std;

int main()
{
    int sh, dh, h, n, app;
    int m = 0;
    cin >> sh >> dh >> n;
    h = sh + dh;
    for (int i = 0; i < n; i++)
    {
        cin >> app;
        if (app <= h)
            m++;
    }
    cout << m;
    return 0;
}