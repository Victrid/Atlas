#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex
{
    friend ostream &operator<<(ostream &, const MyComplex &);
    friend istream &operator>>(istream &, MyComplex &);
    friend MyComplex operator+(const MyComplex &, const MyComplex &);
    friend MyComplex operator-(const MyComplex &, const MyComplex &);
    friend MyComplex operator!(const MyComplex &);
    friend MyComplex operator*(const MyComplex &, const MyComplex &);
    friend MyComplex operator/(const MyComplex &, const MyComplex &);
private:
    double x, y;

public:
    MyComplex &operator=(const MyComplex &);
    MyComplex &operator+=(const MyComplex &);
    MyComplex &operator-=(const MyComplex &);
    MyComplex &operator*=(const MyComplex &);
    MyComplex &operator/=(const MyComplex &);
};
ostream &operator<<(ostream &ost, const MyComplex &z)
{
    ost <<setiosflags(ios::fixed)<<setprecision(2)<< z.x << ' ' << z.y;
    return ost;
}
istream &operator>>(istream &ist, MyComplex &z)
{
    ist >> z.x >> z.y;
    return ist;
}
MyComplex operator+(const MyComplex &a, const MyComplex &b)
{
    MyComplex Temp;
    Temp.x = a.x + b.x;
    Temp.y = a.y + b.y;
    return Temp;
}
MyComplex operator-(const MyComplex &a, const MyComplex &b)
{
    MyComplex Temp;
    Temp.x = a.x - b.x;
    Temp.y = a.y - b.y;
    return Temp;
}
MyComplex operator!(const MyComplex &a)
{
    MyComplex Temp;
    Temp.x = a.x;
    Temp.y = -a.y;
    return Temp;
}
MyComplex operator*(const MyComplex &a, const MyComplex &b)
{
    MyComplex Temp;
    Temp.x = a.x * b.x - a.y * b.y;
    Temp.y = a.x * b.y + a.y * b.x;
    return Temp;
}
MyComplex operator/(const MyComplex &a, const MyComplex &b)
{
    MyComplex Temp;
    Temp = a * (!b);
    Temp.x /= (b * (!b)).x;
    Temp.y /= (b * (!b)).x;
    return Temp;
}
MyComplex &MyComplex::operator=(const MyComplex &a)
{
    x = a.x;
    y = a.y;
    return *this;
}
MyComplex &MyComplex::operator+=(const MyComplex &a)
{
    *this = *this + a;
    return *this;
}
MyComplex &MyComplex::operator-=(const MyComplex &a)
{
    *this = *this - a;
    return *this;
}
MyComplex &MyComplex::operator*=(const MyComplex &a)
{
    *this = *this * a;
    return *this;
}
MyComplex &MyComplex::operator/=(const MyComplex &a)
{
    *this = *this / a;
    return *this;
}
int main()
{
    MyComplex z1;
    MyComplex z2;

    cin >> z1 >> z2;

    cout << z1 + z2 << endl;
    cout << z1 - z2 << endl;
    cout << z1 * z2 << endl;
    cout << z1 / z2 << endl;
    cout << (z1 += z2) << endl;
    cout << (z1 -= z2) << endl;
    cout << (z1 *= z2) << endl;
    cout << (z1 /= z2) << endl;

    return 0;
}