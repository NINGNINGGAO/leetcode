/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sort(int* nums, int begin, int end)
{
    int l=begin, r=end;
    int v = nums[l+(r-l)/2];
    while(l <= r)
    {
        while(nums[l] < v) l++;
        while(nums[r] > v) r--;
        if(l <= r)
        {
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
            l++; r--;
        }
    }
    if(r > begin)
        sort(nums, begin, r);
    if(l < end)
        sort(nums, l, end);
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    if(numsSize<3)
        return 0;
    sort(nums,0,numsSize-1);
    int **p=(int**)malloc(sizeof(int*)*16384);
    int count=0;
    *returnSize=0;
    for(int left=0;left<numsSize-2;left++){
        if(nums[left]>0) break;
        if(left>0 && nums[left]==nums[left-1]) continue;
        int mid=left+1;
        int right=numsSize-1;
        while(mid<right){
            int sum=nums[left]+nums[mid]+nums[right];
            if(sum<0){
                mid++;
            }
            else if(sum>0){
                right--;
            }
            else{
                    count=count+1;
                    p[count-1]=(int*)malloc(sizeof(int)*3);
                    p[count-1][0]=nums[left];
                    p[count-1][1]=nums[mid];
                    p[count-1][2]=nums[right];
                while(mid<right&&nums[mid]==nums[mid+1])
                    mid++;
                while(mid<right&&nums[right]==nums[right-1])
                    right--;
                mid++;
                right--;
            }
        }
    }
    *returnSize=count;
    return p;
}
