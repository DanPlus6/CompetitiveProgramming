# SAC '22 Code Challenge 4 Junior P1 - Obligatory DeMello Problem
from sys import stdin
res = 0
for i in stdin.readline():
    if i in 'aeiouy': res += 1

print('good') if res >= 2 else print('bad')
