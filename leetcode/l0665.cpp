int CheckNoDec(int *array, int numsSize)
{
    for (int i = 0; i < numsSize - 1; i++)
        if (array[i + 1] < array[i])
            return i;
    return -1;
}
bool checkPossibility(int *nums, int numsSize)
{
    //method cf leetcode critics
    int i = CheckNoDec(nums, numsSize);
    if (i == -1)
        return true;
    else
    {
        int numleft = nums[i];
        int numright = nums[i + 1];
        //right to left
        nums[i] = nums[i + 1];
        if (CheckNoDec(nums, numsSize) == -1)
            return true;
        //left to right
        nums[i] = numleft;
        nums[i + 1] = numleft;
        if (CheckNoDec(nums, numsSize) == -1)
            return true;
        return false;
    }
}