# inspired by other person's code for better space complexity
class Solution:
    def fizzBuzz(self, n: int) -> list[str]:
        ans = ["1"]
        for i in range(1,n):
            temp_i = i+1
            if temp_i % 3 == 0 and temp_i % 5 == 0:
                ans.append("FizzBuzz")
            elif temp_i % 3 == 0:
                ans.append("Fizz")
            elif temp_i % 5 == 0:
                ans.append("Buzz")
            else:
                ans.append(str(temp_i))
        
        return ans

# my code, only bad space complexity
"""
class Solution:
    def fizzBuzz(self, n: int) -> list[str]:
        ans = []
        for i in range(1,n+1):
            if i % 3 == 0 and i % 5 == 0:
                ans.append("FizzBuzz")
            elif i % 3 == 0:
                ans.append("Fizz")
            elif i % 5 == 0:
                ans.append("Buzz")
            else:
                ans.append(str(i))
        
        return ans
"""