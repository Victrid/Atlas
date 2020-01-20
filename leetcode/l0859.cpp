class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.length() != B.length())
            return false;
        int invcnt = 0;
        for (int i = 0; i < A.length(); i++)
        {
            if (A[i] != B[i])
                invcnt++;
        }
        if (invcnt == 0)
        {
            int rev[128] = {0};
            for (int i = 0; i < A.length(); i++)
                rev[A[i]]++;
            for (int i = 0; i < 128; i++)
                if (rev[i] > 1)
                    return true;
            return false;
        }
        if (invcnt >= 3 || invcnt == 1)
            return false;
        int jl, jr;
        for (int i = 0; i < A.length(); i++)
            if (A[i] != B[i])
                jl = i;
        for (int i = A.length() - 1; i >= 0; i--)
            if (A[i] != B[i])
                jr = i;
        if (A[jl] == B[jr] && A[jr] == B[jl])
            return true;
        return false;
    }
};