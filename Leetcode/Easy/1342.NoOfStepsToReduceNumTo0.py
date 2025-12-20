# more efficient solution, efficient time cplexity, space complexity didn't change much
class Solution:
    def numberOfSteps(self, num: int) -> int:
        if num == 1:
            return 1

        steps = 0
        while True:
            if num == 0:
                break

            steps+=1
            if num % 2 == 0:
                num /= 2
            else:
                num -= 1
        
        return steps

# default option, inefficient space and time complexity
"""
class Solution:
    def numberOfSteps(self, num: int) -> int:
        if num == 1:
            return 1

        steps = 0
        while num > 0:
            steps+=1
            if num % 2 == 0:
                num /= 2
            else:
                num -= 1
        
        return steps
"""

