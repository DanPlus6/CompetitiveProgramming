# CCC '25 J5 - Connecting Territories
import sys
input = sys.stdin.readline


R,C,M = int(input()),int(input()),int(input())
if R*C <= M:
    res = 0
    for r in range(R):
        res += (r*C) % M + 1
    print(res)
    sys.exit(0)

# orz bruce 
pre = [0] * C
for r in range(R):
    cur = [0] * C
    for c in range(C):
        cell = (r*C+c) % M + 1
        if c == 0:
            cur[c] = min(pre[c],pre[c+1]) + cell
        elif c < C-1:
            cur[c] = min(pre[c-1],pre[c],pre[c+1]) + cell
        else:
            cur[c] = min(pre[c-1],pre[c]) + cell
        
    pre,cur = cur,pre


print(min(pre))

# orz bruce
# R, C, M = int(input()), int(input()), int(input())
# pre = [0] * C
# for i in range(R):
#    cur = [0] * C
#    for j in range(C):
#        cell = (i * C + j) % M + 1
#        if j == 0:
#            cur[j] = min(pre[j], pre[j+1]) + cell
#        elif j < C-1:
#            cur[j] = min(pre[j-1], pre[j], pre[j+1]) + cell
#        else:
#            cur[j] = min(pre[j-1], pre[j]) + cell
#    pre, cur = cur, pre
# print(min(pre))
