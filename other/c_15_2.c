

/**
  * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//冒泡排序
int *sort(int *nums, int numsSize)
{
    int i, j ,temp;
    for (i = 0; i < numsSize-1; i++)
    {
        for (j = 0; j < numsSize-1-i; j++)
        {
            if (nums[j] > nums[j+1])
            {
                temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    return nums;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int target = 0, newTarget;
    int i, j, k;
    int ptr_ra = -1;

    //long long max = ((numsSize-2) * (numsSize-1) * (numsSize)) / 6;
    int **returnArray = (int **)malloc(sizeof(int *) * 17000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 17000);
    nums = sort(nums, numsSize);
    
    for (i = 0; i < numsSize-2; i++)
    {
        if (i == 0 || (i > 0) && (nums[i] != nums[i-1]))
        {        
            //双指针
            j = i + 1;
            k = numsSize - 1;
            newTarget = target - nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] == newTarget)
                {
                    
                    returnArray[++ptr_ra] = (int *)malloc(sizeof(int) * 3);
                    returnArray[ptr_ra][0] = nums[i];
                    returnArray[ptr_ra][1] = nums[j];
                    returnArray[ptr_ra][2] = nums[k];
                    (*returnColumnSizes)[ptr_ra] = 3;
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] < newTarget)
                {
                    while (j < k && nums[j] == nums[j+1]) j++;
                    j++;
                }
                else if (nums[j] + nums[k] > newTarget)
                {
                    while (j < k &&  nums[k] == nums[k-1]) k--;
                    k--;
                }
            }
        }
        
    }
    
    
    *returnSize = ptr_ra+1;
    return returnArray;

}
