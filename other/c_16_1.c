
int* sort(int* nums, int numsSize) {
    int i, j, temp;
    for (i = 0; i < numsSize - 1; i++) {
        for (j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    } 
    return nums;
}
int threeSumClosest(int* nums, int numsSize, int target){
    nums = sort(nums, numsSize);
    int i, j, k;
    int res;
    int newtarget;
    
    for (i = 0; i < numsSize - 2; i++) {
        j = i + 1;
        k = numsSize - 1;
        newtarget = target - nums[i];
        while (j < k) {
            if (nums[j] + nums[k] - newtarget)
        }
}

