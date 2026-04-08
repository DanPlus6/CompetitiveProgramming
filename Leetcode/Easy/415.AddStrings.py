from collections import deque

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        minL = min(len(num1), len(num2))
        maxL = max(len(num1), len(num2))

        res = deque()
        carry = 0
        it1, it2 = len(num1)-1, len(num2)-1
        for i in range(minL):
            tmpSum = int(num1[it1]) + int(num2[it2]) + carry
            carry = 0

            res.appendleft(tmpSum % 10)
            carry += tmpSum // 10

            it1 -= 1
            it2 -= 1

        if len(num2) > len(num1):
            num1 = num2
            it1 = it2

        for i in range(maxL - minL):
            tmpSum = int(num1[it1]) + carry
            carry = 0

            res.appendleft(tmpSum % 10)
            carry += tmpSum // 10

            it1 -= 1
            it2 -= 1
        
        if carry: res.appendleft(carry)
        return "".join(map(str,res))
