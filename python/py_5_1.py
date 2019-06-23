class Solution:
    def longestPalindrome(self, s: str) -> str:
        num = len(s)
        if num <= 1:
            return s
        
        max = 1
        res = s[0]
        
        dp = [[False for _ in range(num)] for _ in range(num)]
        
        for i in range(num):
            for j in range(i):
                if s[j] == s[i] and (i - j <= 2 or dp[j + 1][i - 1]):
                    dp[j][i] = True
                    if i - j + 1 > max:
                        max = i - j + 1
                        res = s[j:i + 1]
        return res
