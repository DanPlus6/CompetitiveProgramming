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
