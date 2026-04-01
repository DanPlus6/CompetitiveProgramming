# Problem J1: Concert Tickets
from sys import stdin
input = stdin.readline
from collections import defaultdict

B = int(input())
T = int(input()) - int(input())

if B <= T: print('Y',T-B) 
elif B > T: print('N')
