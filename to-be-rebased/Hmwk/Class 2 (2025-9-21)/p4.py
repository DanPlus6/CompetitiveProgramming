# USACO 2020 Dec Bronze P2 - Daisy Chains
N = int(input())
flowers = list(map(int,input().split()))

ans = 0
for left in range(N):
    sum,sbarr = 0,set()
    for right in range(left,N):
        sum += flowers[right]
        sbarr.add(flowers[right])
        if sum / (right-left+1) in sbarr:
            ans += 1
    
print(ans)

