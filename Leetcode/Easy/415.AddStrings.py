# 415. Add Strings
# from collections import deque

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        it1 = len(num1) - 1
        it2 = len(num2) - 1
        
        res = ""
        carry = 0
        while (it1 >= 0 or it2 >= 0 or carry):
            tmpSum = (int(num1[it1]) if it1 >= 0 else 0) + (int(num2[it2]) if it2 >= 0 else 0) + carry

            res += str(tmpSum % 10)
            carry = tmpSum // 10

            it1 -= 1
            it2 -= 1
        
        return res[::-1]


        # minL = min(len(num1), len(num2))
        # maxL = max(len(num1), len(num2))

        # res = deque()
        # carry = 0
        # it1, it2 = len(num1)-1, len(num2)-1
        # for i in range(minL):
        #     tmpSum = int(num1[it1]) + int(num2[it2]) + carry
        #     carry = 0

        #     res.appendleft(tmpSum % 10)
        #     carry += tmpSum // 10

        #     it1 -= 1
        #     it2 -= 1

        # if len(num2) > len(num1):
        #     num1 = num2
        #     it1 = it2

        # for i in range(maxL - minL):
        #     tmpSum = int(num1[it1]) + carry
        #     carry = 0

        #     res.appendleft(tmpSum % 10)
        #     carry += tmpSum // 10

        #     it1 -= 1
        #     it2 -= 1
        
        # if carry: res.appendleft(carry)
        # return "".join(map(str,res))
        
