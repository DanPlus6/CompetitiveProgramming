# Count Multiples
def main():
    from sys import stdin
    x,y,A,B = map(int, stdin.readline().split())

    if A == B and A == 1:
        return y-x+1

    if x == y:
        if x % A == 0 or x % B == 0: return 1
        return 0
    
    
    
print(main())

# but can we make this even faster?
"""
a,b = 1,1
runA,runB = True,True
while runA or runB:
    if runA:
        if a * A < x:
            a += 1 
        else:
            runA = False
    if runB:
        if b * B < x:
            b += 1 
        else:
            runB = False

res = 0
runA,runB = True,True
while runA or runB:
    aa = a * A
    bb = b * B
    if aa == bb and aa <= y and aa >= x:
        print(aa)
        a += 1 
        b += 1
        res += 1
        continue
    if runA:
        aa = a * A; print(aa)
        if aa <= y and aa >= x:
            a += 1
            res += 1
        else:
            runA = False
    if runB:
        bb = b * B; print(bb)
        if bb <= y and bb >= x:
            b += 1 
            res += 1
        else:
            runB = False
"""


# naieve
"""
semi = A if A < B else B
start = x if x >= semi else semi

res = 0
for i in range(start,y+1):
    if i % A == 0 or i % B == 0: res += 1
"""
