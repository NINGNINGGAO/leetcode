class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        j = len(height) - 1
        res = 0
        while (i < j):
            num = j - i
            if (height[i] < height[j]):
                temp = height[i] * num
                i += 1
            else:
                temp = height[j] * num
                j -= 1
            res = temp if temp > res else res
        return res
