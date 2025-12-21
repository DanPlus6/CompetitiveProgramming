# Back From Summer '17 P2: Crayola Lightsaber
from sys import stdin
# Orz sir bruce
def main() -> int:
    N = int(stdin.readline())
    if N == 1: return 1
    SABER = list(stdin.readline().split())
    colors = {'red':0, 'orange':0, 'yellow':0, 'green':0, 'blue':0, 'black':0}
    for i in SABER:
        colors[i] += 1

    ct = colors.values()
    rem = sum(ct) - (Max := max(ct))
    if (rem+1) < Max:
        return rem*2 + 1
    else:
        return sum(ct)

print(main())

# naieve and incorrect solution
"""
def main() -> int:
    N = int(stdin.readline())
    if N == 1: return 1
    SABER = list(stdin.readline().split())

    res = 1
    last = SABER[0]
    for i in range(1,N):
        if SABER[i] != last:
            res += 1
            last = SABER[i]
    
    return res
print(main())
"""
