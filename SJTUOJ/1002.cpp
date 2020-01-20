//constructed using some macro and snippets
#include <iostream>
using namespace std;

int main()
{
    //using glide window method.
    int mat_h, mat_l;
    cin >> mat_h >> mat_l;

    //DynMat	Name:Pmat
    //Lines:mat_h	rows:mat_l
    int **Pmat = new int *[mat_h];
    for (int i = 0; i < mat_h; i++)
        *(Pmat + i) = new int[mat_l];
    int *Pmat_cfg = new int(mat_h);
    //End of Dynmat.

    for (int i = 0; i < mat_h; i++)
        for (int j = 0; j < mat_l; j++)
            cin >> Pmat[i][j];
    int srch_l, srch_h;
    cin >> srch_h >> srch_l;

    //DynMat	Name:Resmat
    //Lines:mat_h-srch_h+1	rows:mat_l-srch_l+1
    int **Resmat = new int *[mat_h - srch_h + 1];
    for (int i = 0; i < mat_h - srch_h + 1; i++)
        *(Resmat + i) = new int[mat_l - srch_l + 1]();
    int *Resmat_cfg = new int(mat_h - srch_h + 1);
    //End of Dynmat.

    //construct 1st window
    for (int i = 0; i < srch_h; i++)
        for (int j = 0; j < srch_l; j++)
            Resmat[0][0] += Pmat[i][j];

    //vertical and horizontal choose
    if (srch_l >= srch_h)
    { //construct vertical screener
        for (int i = 1; i < mat_h - srch_h + 1; i++)
        {
            Resmat[i][0] = Resmat[i - 1][0]; //get from upside
            for (int j = 0; j < srch_l; j++)
            {
                //column process
                Resmat[i][0] -= Pmat[i - 1][j];
                Resmat[i][0] += Pmat[srch_h + i - 1][j];
            }
        }

        //screen
        for (int j = 1; j < mat_l - srch_l + 1; j++)
        {
            //1st window
            Resmat[0][j] = Resmat[0][j - 1]; //get from upside
            for (int i = 0; i < srch_h; i++)
            {
                //row process
                Resmat[0][j] -= Pmat[i][j - 1];
                Resmat[0][j] += Pmat[i][j + srch_l - 1];
            }
            //screener
            for (int i = 1; i < mat_h - srch_h + 1; i++)
            {
                Resmat[i][j] = Resmat[i - 1][j]; //left
                for (int z = 0; z < srch_l; z++)
                {
                    //column
                    Resmat[i][j] -= Pmat[i - 1][j + z];
                    Resmat[i][j] += Pmat[i + srch_h - 1][j + z];
                }
            }
        }
    }
    else
    { //construct horiz screener
        for (int j = 1; j < mat_l - srch_l + 1; j++)
        {
            Resmat[0][j] = Resmat[0][j - 1]; //get from left
            for (int i = 0; i < srch_h; i++)
            {
                //column process
                Resmat[0][j] -= Pmat[i][j - 1];
                Resmat[0][j] += Pmat[i][srch_l + j - 1];
            }
        }

        //screen
        for (int i = 1; i < mat_h - srch_h + 1; i++)
        {
            //1st window
            Resmat[i][0] = Resmat[i - 1][0]; //get from upside
            for (int j = 0; j < srch_l; j++)
            {
                //row process
                Resmat[i][0] -= Pmat[i - 1][j];
                Resmat[i][0] += Pmat[i + srch_h - 1][j];
            }
            //screener
            for (int j = 1; j < mat_l - srch_l + 1; j++)
            {
                Resmat[i][j] = Resmat[i][j - 1]; //left
                for (int z = 0; z < srch_h; z++)
                {
                    //column
                    Resmat[i][j] -= Pmat[i + z][j - 1];
                    Resmat[i][j] += Pmat[i + z][srch_l + j - 1];
                }
            }
        }
    }

    //search
    int max = 0;
    for (int i = 0; i < mat_h - srch_h + 1; i++)
        for (int j = 0; j < mat_l - srch_l + 1; j++)
            max = max < Resmat[i][j] ? Resmat[i][j] : max;

    cout << max;

    //delete dynamic variable

    //Release DynMat
    //Name:Resmat
    for (int i = 0; i < *Resmat_cfg; i++)
        delete[] * (Resmat + i);
    delete[] Resmat;
    delete Resmat_cfg;
    //End of Release.

    //Release DynMat
    //Name:Pmat
    for (int i = 0; i < *Pmat_cfg; i++)
        delete[] * (Pmat + i);
    delete[] Pmat;
    delete Pmat_cfg;
    //End of Release.

    return 0;
}
