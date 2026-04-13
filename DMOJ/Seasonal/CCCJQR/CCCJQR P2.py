# CCCJQR P2
from sys import stdin
def main():
    p = int(stdin.readline().split()[-1])

    for i in range(int(stdin.readline())):
        e = int(stdin.readline().split()[-1])
        if p >= e: p -= e
    return i+1
print(main())
