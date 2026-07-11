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

    
print(main())

