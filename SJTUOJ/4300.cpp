#include <iostream>

using namespace std;

int *MergeSort(int *list, int listSize)
{
    if (listSize == 1)
        return list;
    if (listSize == 2)
    {
        if (list[0] > list[1])
        {
            int temp = list[0];
            list[0] = list[1];
            list[1] = temp;
            return list;
        }
        return list;
    }
    int *tmplist = new int[listSize];
    int *llst = MergeSort(list, listSize / 2);
    int *rlst = MergeSort(list + listSize / 2, listSize - listSize / 2);
    int lct = 0, rct = 0;
    while (lct + rct != listSize)
    {
        if ((llst[lct] <= rlst[rct] && lct < listSize / 2) || rct >= listSize - listSize / 2)
        {
            tmplist[lct + rct] = llst[lct];
            lct++;
        }
        else
        {
            tmplist[lct + rct] = rlst[rct];
            rct++;
        }
    }
    for (int i = 0; i < listSize; i++)
    {
        list[i] = tmplist[i];
    }
    return list;
}
int main()
{
    int n;
    cin >> n;
    int *cnlist = new int[n];
    for (int i = 0; i < n; i++)
        cin >> cnlist[i];
    MergeSort(cnlist, n);
    cout << cnlist[n / 2];
    return 0;
}