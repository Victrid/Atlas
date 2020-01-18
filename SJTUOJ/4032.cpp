#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c, temp;
    cin >> a >> b >> c;
    //rank
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    //is triangle
    if (c >= (a + b) || a <= 0)
    {
        cout << "-1";
        return 0;
    }
    //is RT
    if ((c * c - a * a - b * b) <= 1e-6 && (c * c - a * a - b * b) >= -1e-6)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}