# List Minimum (Easy)
from sys import stdout
N = int(input())
for i in range(N):
    if i != N-1:
        stdout.write(str(i+1)+" ")
    else:
        stdout.write(str(N))
