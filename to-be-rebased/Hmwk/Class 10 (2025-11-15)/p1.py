# Mock CCC '22 Contest 2 J1 - Opening Ceremony
from sys import stdin
f,m,b = map(int,stdin.readline().split())
F,M,B = map(int,stdin.readline().split())

print(F+M+B,f*F+m*M+b*B)

