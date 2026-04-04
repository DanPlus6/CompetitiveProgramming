# CCC '12 J4 - Big Bang Secrets
from sys import stdin, stdout
input = stdin.readline

K = int(input())
raw = input().strip()

base = ord('A')
for i in range(1,len(raw)+1):
    stdout.write(chr(65 + (ord(raw[i-1]) - 65 - (3*i + K)) % 26))
