# CCC '12 S2 - Aromatic Numbers
from sys import stdin
S = stdin.readline().strip()
SYMBOLS = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}

res = 0
lastR = ''
lastPair = 0
for i in range(1,len(S),2):
    cur = S[i]
    cpair = int(S[i-1]) * SYMBOLS[cur]
    res += cpair
    
    if lastR and SYMBOLS[lastR] < SYMBOLS[cur] or not lastR:
        res -= 2*lastPair
    lastR = cur
    lastPair = cpair

print(res)

