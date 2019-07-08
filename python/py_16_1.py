class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        numsSize = len(nums)
        nums.sort()
        res = float('inf')
        for i in range(numsSize - 2):
            j, k = i + 1, numsSize - 1
            while j < k :
                temp = nums[i] + nums[j] + nums[k]
                if abs(target - temp) < abs(target - res):
                    res = temp
                if target - temp < 0:
                    k -= 1
                elif target - temp > 0:
                    j += 1
                else:
                    return target
        return res
