# 3754. Concatenate Non-Zero Digits and Multiply by Sum I
class Solution:
    def sumAndMultiply(self, n: int) -> int:
        dig = {
            '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9
        }
        digSum = 0
        x = ""
        for d in str(n):
            if d != '0':
                digSum += dig[d]
                x += d
        x = int(x) if x != '' else 0
        return x*digSum

