//Error:
//Time limit exceeded when matrix became very large.
//need to be changed.


#include <iostream>

using namespace std;

int cc(int **matp, int m, int l, int h);

int main()
{
    int m, n, l, h;
    cin >> m >> n;
    int **matp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        *(matp + i) = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matp[i][j];
        }
    }
    cin >> l >> h;

    int max = 0;
    int temp = 0;
    for (int i = 0; i < m - l + 1; i++)
    {
        for (int j = 0; j < n - h + 1; j++)
        {
            temp = cc(matp + i, j, l, h);
            max = (temp >= max) ? temp : max;
        }
    }
    cout << max;
    return 0;
}

int cc(int **matp,int n ,int l, int h)
{
    static int ans;
    static int** mtp = nullptr;
    if (mtp != matp)
    {
        ans =0;
        for (int j = 0; j < h; j++)
        {
            for (int i = 0; i < l; i++)
            {
                ans += matp[i][j + xa];
            }
        }
        mtp = matp;
    }
    else
    {
        for (int i = 0; i < l; i++)
        {
            ans += matp[i][h + xa - 1];
            ans -= matp[i][xa-1];
        }
    }
    return ans;
}