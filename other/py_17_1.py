class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        L1 = [""]
        L2 = []
        h = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl", "6": "mno",
            "7": "pqrs", "8": "tuv", "9": "wxyz"}
        for char in digits:
            L1 = [each + i for each in L1 for i in h[char]]
        return L1
