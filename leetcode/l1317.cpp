class Solution
{
public:
    bool val(int n)
    {
        if (n / 10)
        {
            if (n % 10)
                return val(n / 10);
            else
                return false;
        }
        else
        {
            if (n)
                return true;
            else
                return false;
        }
    }
    vector<int> getNoZeroIntegers(int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (val(i) && val(n - i))
            {
                vector<int> a{i, n - i};
                return a;
            }
        }
        vector<int> a{0, 0};
        return a;
    }
};