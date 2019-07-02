int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int temp, n = 0, m = numsSize - 1;
    int **ptr = (int **)malloc(sizeof(int *) * 20000);
    for (int j = numsSize - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (nums[i] >= nums[i + 1])
            {
                temp = nums[i + 1];
                nums[i + 1] = nums[i];
                nums[i] = temp;
            }
        }
    }
    for (int k = 1; k < numsSize - 1; k++)
    {
        n = 0;
        m = numsSize - 1;
        if (k > 1 && nums[k] == nums[k - 1])
        {
            n = k - 1;
            if (nums[n - 1] == nums[n])
                continue;
        }
        while (n < k && m > k)
        {
            if (nums[n] + nums[m] == -nums[k])
            {
                ptr[*returnSize] = (int *)malloc(sizeof(int) * 3);
                ptr[*returnSize][0] = nums[n];
                ptr[*returnSize][1] = nums[k];
                ptr[*returnSize][2] = nums[m];
                *returnSize += 1;
                n++;
                while (n < m && nums[n] == nums[n - 1])
                    n++;
            }
            else
            {
                if (nums[n] + nums[m] > -nums[k])
                    m--;
                else
                    n++;
            }   
        }
    }
    return ptr;
}
