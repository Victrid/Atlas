class Solution
{
public:
    int firstUniqChar(string s)
    {
        int l = s.length();
        bool nu = false;
        
        for (int i = 0; i < l; i++)
        {
            nu = false;
            if (s[i] == '\0')
                continue;
            for (int j = i + 1; j < l; j++)
            {
                if (s[i] == s[j])
                {
                    s[j] = '\0';
                    nu = true;
                }
            }
            if (nu)
                s[i] = '\0';
        }

        for (int i = 0; i < l; i++)
        {
            if (s[i] != '\0')
                return i;
        }
        return -1;
    }
};