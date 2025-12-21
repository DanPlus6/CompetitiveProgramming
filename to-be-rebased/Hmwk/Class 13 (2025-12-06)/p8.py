# COCI '13 Contest 5 #3 Eksplozjia
from sys import stdin
S = stdin.readline().strip()
B = list(stdin.readline().strip())
lenB = len(B)

# Orz A-stick-bug (github)
stk = []
for i in S:
    stk.append(i)
    stkLen = len(stk)
    if stkLen >= lenB and stk[(stkLen-lenB):] == B:
        for i in range(lenB):
            stk.pop()

print('FRULA') if not stk else print(''.join(stk))
