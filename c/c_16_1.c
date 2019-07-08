
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
    if (a < 0) {
        a = -a;
    }
    return a;
}

int threeSumClosest(int* nums, int numsSize, int target){
    nums = sort(nums, numsSize);
    int i, j, k;
    int res = INT_MAX;
    int temp, mid;
    
    for (i = 0; i < numsSize - 2; i++) {
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            temp = nums[i] + nums[j] + nums[k];
            mid = target - temp;
		    if (abs(mid) <= abs(res)) {
			    res = mid;
		    }
		    if (mid > 0) {
			    while (j < k && nums[j] == nums[j+1]) j++;
			    j++;
		    } else if (mid < 0) {
			    while (j < k && nums[k] == nums[k-1]) k--;
			    k--;
		    } else {
			    return target;
		    }
        }
    }
    return target - res;
}
