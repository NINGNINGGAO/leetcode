
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
int abs(int a) {
    if (a > 0) return a;
    if (a < 0) return -a;
}
int threeSumClosest(int* nums, int numsSize, int target){
    nums = sort(nums, numsSize);
    int i, j, k;
    int res = INT_MAX/2;
    int temp;
    
    for (i = 0; i < numsSize - 2; i++) {
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            temp = nums[i] + nums[j] + nums[k];
		    if (abs(target - temp) > abs(target - res)) {
			    res = temp;
		    }
		    if (temp < target) {
			    while (j < k && nums[j] == nums[j+1]) j++;
			    j++;
		    } else if (temp < target) {
			    while (j < k && nums[k] == nums[k-1]) k--;
			    k--;
		    } else {
			    return res;
		    }
        }
	return res;
}
