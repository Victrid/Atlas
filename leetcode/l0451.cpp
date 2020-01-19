class Solution
{
public:
    int getmax(int *cmap)
    {
        int max = 128;
        for (int i = 0; i < 128; i++)
        {
            if (cmap[i] > cmap[max])
                max = i;
        }
        return max;
    }
    string frequencySort(string s)
    {
        int len = s.length();

        int *cmap = new int[129]();
        for (int i = 0; i < len; i++)
        {
            cmap[(int)s[i]]++;
        }
        int i = 128;
        int empty = 0;
        while (1 == 1)
        {
            i = getmax(cmap);
            if (i == 128)
                break;
            while (cmap[i] != 0)
            {
                s[empty] = (char)(i);
                empty++;
                cmap[i]--;
            }
        }
        return s;
    }
};