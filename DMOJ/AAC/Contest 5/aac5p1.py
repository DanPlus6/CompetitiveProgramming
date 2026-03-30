# An Animal Contest 5 P1 - Bamboo Cookies
N = int(input()) # str(N) -> int N
A = list(map(int, input().split())) # str -> [str,str] -> map -> [int, int] -> [int, int]

odd = 0
even = 0
for num in A:
    if num % 2 == 0: 
       even += 1
    else:
        odd += 1

print(even//2 + odd//2)

