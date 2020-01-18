#include <iostream>
using namespace std;
int main()
{
    int m, n;
    int MAT[10][10]={0};
    bool ENDL_FLAG = false, SPACE_FLAG = false;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> MAT[i][j];
        }
    }
    cout << n << ' ' << m << endl;
    for (int j = 0; j < n; j++)
    {
        if (ENDL_FLAG)
            cout << endl;
        for (int i =(m-1); i >=0; i--)
        {
            if (SPACE_FLAG)
                cout << ' ';
            cout << MAT[i][j];
            SPACE_FLAG = true;
        }
        ENDL_FLAG = true;
        SPACE_FLAG = false;
    }
    return 0;
}
