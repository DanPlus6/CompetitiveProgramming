# CCC '26 J1 -  Concert Tickets
from sys import stdin
input = stdin.readline

B = int(input())
T = int(input()) - int(input())

if B <= T: print('Y',T-B) 
elif B > T: print('N')
