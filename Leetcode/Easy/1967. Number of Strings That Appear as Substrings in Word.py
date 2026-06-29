# 1967. Number of Strings That Appear as Substrings in Word

class Solution:
    def numOfStrings(self, patterns: list[str], word: str) -> int:
        return sum([1 for p in patterns if p in word])
