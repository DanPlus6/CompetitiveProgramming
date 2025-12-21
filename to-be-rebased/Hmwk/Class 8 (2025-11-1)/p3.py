# CCC '16 J3 - Hidden Palindrome
from sys import stdin

word = stdin.readline().strip('\n')
n = len(word)

maxx = 1
for i in range(n):
    for j in range(i+1,n):
        lenn = j-i+1
        if lenn == 1: continue
        s = word[i:j+1]

        for k in range(lenn//2):
            if s[k] != s[-1-k]:
                break
        else:
            maxx = max(maxx,lenn)

print(maxx)
