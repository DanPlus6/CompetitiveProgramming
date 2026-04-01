# CCC '14 S3 - The Geneva Confection
from sys import stdin,stdout
from collections import deque
T = int(stdin.readline())
tests = [[int(stdin.readline().strip()) for i in range(int(stdin.readline()))] for i in range(T)]

def passTest(cars: list[int]) -> bool:
    Cars = cars
    n = len(Cars)
    branch = deque()
    ni = 1
    while True:
        if not Cars and not branch:
            return True
        if Cars and Cars[-1] == ni:
            Cars.pop()
            ni += 1
        elif branch and branch[0] == ni:
            branch.popleft()
            ni += 1
        else:
            if not Cars: return False
            branch.appendleft(Cars.pop())
    if Cars or branch: return False


for i in range(T):
    if i == T-1:
        stdout.write('Y') if passTest(tests[i]) else print('N')
        break
    stdout.write('Y\n') if passTest(tests[i]) else print('N\n')

