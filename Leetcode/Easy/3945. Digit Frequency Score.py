# Author: DanPlus6 // David Fu
# Problem Name: 3945. Digit Frequency Score
# Problem Code: digit-frequency-score
# Problem URL:  https://leetcode.com/problems/digit-frequency-score/
from collections import Counter

class Solution:
    def digitFrequencyScore(self, n: int) -> int: return sum([int(k)*v for k,v in Counter(str(n)).items()])

