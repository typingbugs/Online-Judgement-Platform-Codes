/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* temp;
    temp = (int*)malloc(2 * sizeof(int));
    for (int j = 0; j < numsSize - 1; j++)
        for (int k = j + 1; k < numsSize; k++)
            if (nums[j] + nums[k] == target)
            {
                temp[0] = j;
                temp[1] = k;
                *returnSize = 2;
            }
    return temp;
}