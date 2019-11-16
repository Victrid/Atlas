#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int num;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        while (num != 0)
        {
            if (num & 1)
                cnt++;
            num = num >> 1;
        }
    }
    cout << cnt;
    return 0;
}