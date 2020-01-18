#include <iostream>

using namespace std;

int C(int, int); //get combination number

class IntArray
{
    friend ostream &operator<<(ostream &os, const IntArray &obj);
    friend istream &operator>>(istream &is, IntArray &obj);
    friend bool operator==(const IntArray &obj1, const IntArray &obj2);

private:
    int length;
    int *list;

public:
    IntArray(int l);                         //l为数组长度
    ~IntArray();                             //析构函数
    int &operator[](int index);              //右值
    const int &operator[](int index) const;  //左值
    IntArray operator()(int start, int end); //返回一个新的IntArray对象，包含从start下标到end下标的值
};
ostream &operator<<(ostream &os, const IntArray &obj);
istream &operator>>(istream &is, IntArray &obj);
bool operator==(const IntArray &obj1, const IntArray &obj2);

int main()
{
    int n;
    cin >> n;
    // int m;
    // cin >> m;
    // cout << C(n, m);
    IntArray data1(2 * n);
    cin >> data1;
    IntArray a(n - 1);
    IntArray b(n);
    cin >> a;
    for (int i = 0; i < n; i++)
        b[i] = C(data1[2 * i], data1[2 * i + 1]);

    cout << "The result is:" << endl;
    cout << b << endl;
    if (a == (b(1, n - 1)))
    {
        cout << "yes!";
    }
    else
    {
        cout << "no!";
    }
    return 0;
}

int C(int n, int m)
{
    //n total m select
    //calculate combination number using Euler equations.
    //1.validate
    if (m > n || m < 0 || n < 0)
        return 0;
    //2.defined calculation laws
    if (n == 0 || m == 0)
        return 1;
    //3.boost
    if (m == 1)
        return n;
    if ((2 * m) > n)
        return C(n, n - m);

    return (C(n - 1, m - 1) + C(n - 1, m));
}
ostream &operator<<(ostream &os, const IntArray &obj)
{
    bool SPACE_FLAG = false;
    for (int i = 0; i < obj.length; i++)
    {
        if (SPACE_FLAG)
            os << ' ';
        os << obj[i];
        SPACE_FLAG = true;
    }
    return os;
}
istream &operator>>(istream &is, IntArray &obj)
{
    for (int i = 0; i < obj.length; i++)
        is >> obj[i];
    return is;
}
bool operator==(const IntArray &obj1, const IntArray &obj2)
{
    if (obj1.length != obj2.length)
        return false;
    for (int i = 0; i < obj1.length; i++)
        if (obj1[i] != obj2[i])
            return false;
    return true;
}
IntArray::IntArray(int l)
{
    list = new int[l];
    length = l;
}
IntArray::~IntArray()
{
    delete[] list;
}
int &IntArray::operator[](int index)
{
    return *(list + index);
}
const int &IntArray::operator[](int index) const
{
    return *(list + index);
}
IntArray IntArray::operator()(int start, int end)
{
    IntArray Z(end - start + 1);
    for (int i = start; i <= end; ++i)
    {
        Z[i - start] = *(this->list + i);
    }
    return Z;
}