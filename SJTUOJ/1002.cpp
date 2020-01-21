//1002 rewrite cf FineArtz
#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    //DynMat	Name:Summat
    //Lines:m+1	rows:n+1
    int **Summat = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
        *(Summat + i) = new int[n + 1]();
    int *Summat_cfg = new int(m + 1);
    //End of Dynmat.
    int getnum;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> getnum;
            Summat[i][j] = getnum + Summat[i - 1][j] + Summat[i][j - 1] - Summat[i - 1][j - 1];
        }
    int l, h;
    cin >> l >> h;
    int max = 0;
    int total = 0;
    for (int i = 0; i < m + 1 - l; i++)
        for (int j = 0; j < n + 1 - h; j++)
        {
            total = (Summat[i + l][j + h] + Summat[i][j] - Summat[i + l][j] - Summat[i][j + h]);
            max = total > max ? total : max;
        }
    cout << max;
    //Release DynMat
    //Name:Summat
    for (int i = 0; i < *Summat_cfg; i++)
        delete[] * (Summat + i);
    delete[] Summat;
    delete Summat_cfg;
    //End of Release.
    return 0;
}