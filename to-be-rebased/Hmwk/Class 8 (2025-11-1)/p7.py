# ICPC PACNW 2016 C - Cameras
from sys import stdin
def main() -> int:
    N,K,R = map(int, stdin.readline().split())
    cams = [0 for i in range(N)]
    for i in range(K):
        cams[int(stdin.readline())-1] = 1
    
    # Orz bruce 😭
    res = 0
    s,stack = 0,[]
    for i in range(N):
        s += cams[i]
        if cams[i] == 0:
            stack.append(i)
        if i >= R-1:
            s -= cams[i-R]
            while s < 2:
                cams[stack.pop()] = 1
                s += 1
                res += 1

    return res

print(main())
