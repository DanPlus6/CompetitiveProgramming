# Mock CCC '18 Contest 3 J3/S1 - A String Problem
from sys import stdin
from collections import Counter
def main() -> int:
    S = stdin.readline().strip()
    N = len(S)
    distincts = set(S)
    m = len(distincts)
    if m <= 2: return 0 # if condition already satisfied
    if N == m: N-2      # if all distinct
    leastToGreatest = sorted(Counter(S).items(), key=lambda x: x[1])
    return sum([leastToGreatest[i][1] for i in range(m-2)])
    
print(main())
