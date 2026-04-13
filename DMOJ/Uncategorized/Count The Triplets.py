# Count The Triplets
# what I was trying to do but properly implemented and less redundant
from sys import stdin
def main():
    N = int(stdin.readline())
    arr = sorted(list(map(int, stdin.readline().split())))
    sarr = set(arr)

    seen = set()
    for i in range(N):
        for j in range(i+1,N):
            if (arr[i] + arr[j]) in sarr:
                seen.add((arr[i],arr[j]))
    
    return len(seen) if seen else -1


# wtf am I doing
"""
from sys import stdin
def main():
    N = int(stdin.readline())
    arr = sorted(list(map(int, stdin.readline().split())))

    ret = 0
    # seen = set()
    for k in range(N-1,-1,-1):
        ak = arr[k]

        l,r = 0,k-1
        while l<r:
            ai,aj = arr[l],arr[r]
            aiaj = ai+aj
            # aiajak = tuple(sorted((arr[l],arr[r],ak)))
            if aiaj == ak:
                ret += 1
                # seen.add(tuple(sorted((arr[l],arr[r],ak))))
                l += 1
            elif aiaj < ak:
                l += 1
            elif aiaj > ak:
                r -= 1

    return ret
"""

# wtf am I doing

"""
def main():
    N = int(input())
    arr = list(map(int, input().split()))

    aiaj = set()
    for i in range(N):
        for j in range(i+1):
            aiaj.add( tuple( sorted( (arr[i],arr[j]) ) ) )
       
    ret = 0
    for i in aiaj:
        if i[0]+i[1] in arr:
            ret += 1
    return ret if ret else -1
"""
    
print(main())

