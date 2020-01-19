int checksngl(int *array, int numsSize)
{
    for (int i = 0; i < numsSize - 1; i++)
        if (array[i + 1] < array[i])
            return i;
    return -1;
}
bool checkPossibility(int *nums, int numsSize)
{
    int i = checksngl(nums, numsSize);
    if (i == -1)
        return true;
    else
    {
        int bcup = nums[i];
        int acup = nums[i + 1];
        nums[i] = nums[i + 1];
        if (checksngl(nums, numsSize) == -1)
            return true;
        nums[i] = bcup;
        nums[i + 1] = bcup;
        if (checksngl(nums, numsSize) == -1)
            return true;
        return false;
    }
}