//C
void reverseString(char *s, int sSize)
{
    char temp;
    for (int i = 1; i <= sSize / 2; i++)
    {
        temp = s[i - 1];
        s[i - 1] = s[sSize - i];
        s[sSize - i] = temp;
    }
}