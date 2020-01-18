#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n < 1 || n > 90)
    {
        cout << "error";
        return 0;
    }
    long long step[] = {1, 1};
    for (int i = 2; i <= n; ++i)
        step[i % 2] += step[(i + 1) % 2];
    cout << step[n % 2];
    return 0;
}