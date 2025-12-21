# Can Bob sort it?
from sys import stdin
def main():
    N = int(stdin.readline())
    arr = list(map(int, stdin.readline().split()))
    sarr = sorted(arr)

    if arr == sarr:
        return True

    res = 0
    for i in range(N):
        if arr[i] != sarr[i]: res += 1
        if res > 2:
            return False

    return True if res == 2 else False

print('YES') if main() else print('NO')
