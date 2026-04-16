# TLE '16 Contest 6 (Mock CCC) S1 - Writing the CCC
from sys import stdin
from collections import defaultdict
def main() -> float:
    T = int(stdin.readline())
    types = [stdin.readline() for i in range(T)]
    N = int(stdin.readline())
    problems = defaultdict(list)
    for i in range(N):
        problem = stdin.readline()
        problems[problem].append(i+1)

    for i in types:
        for j in problems[i]:
            print(j)


main()    
