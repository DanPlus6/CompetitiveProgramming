# I am so, so dissapointed in you David
# Way more efficient O(N*Sqrt(N)) solution
class Solution:
    def closestPrimes(self, left: int, right: int) -> list[int]:
        def isPrime(n):
            def isStrong(n,a):
                e=n-1
                p=pow(a,e,n)
                if(p!=1):return False
                while(True):
                    e=e>>1
                    p=pow(a,e,n)
                    if(p==n-1):return True
                    if(e&1):
                        if(p==1):
                            return True
                        break
                return False
            return isStrong(n,2) and (n<2047 or isStrong(n,3))
        x=-1
        y=-1

        if(left<3):
            x=2
            left=3
        else:
            left+=1 if (left&1)==0 else 0
            while(left<=right):
                if(isPrime(left)):
                    x=left
                    left+=2
                    break
                left+=2

        while(left<=right):
            if(isPrime(left)):
                y=left
                left+=2
                break
            left+=2

        t=y
        while(left<=right and (y-x>2 or y==-1)):
            if(isPrime(left)):
                if(y==-1 or (y-x)>(left-t)):
                    x=t
                    y=left 
                t=left
            left+=2

        if(y>0):
            return [x,y]
        return [-1,-1]


# 99% copied from another guy's solution
# focus on abstraction and re-usable knowledge David
# i'm so disappointed in you david
# LOCK IN DAVID
# GET BACK ON TRACK
# THE GRIND NEVER STOPS
"""
class Solution:
    def closestPrimes(self, left: int, right: int) -> list[int]:
        if left > right:
            return [-1,-1]
        sieve = [True] * (right+1)
        sieve[0] = sieve[1] = False

        for i in range(2, int(right**0.5)+1):
            if sieve[i]:
                for j in range(i*i,right+1,i):
                    sieve[j] = False
        
        primes = [i for i in range(left, right + 1) if sieve[i]]

        if len(primes) < 2:
            return [-1,-1]
        
        minDif = float('inf')
        num1,num2 = -1,-1
        for i in range(1,len(primes)):
            diff = primes[i] - primes[i-1]
            if diff < minDif:
                minDif = diff
                num1,num2 = primes[i-1],primes[i]
                
        return [num1,num2]
"""


