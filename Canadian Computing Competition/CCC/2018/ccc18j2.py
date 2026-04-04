# CCC '18 J2 - Occupy parking
def main() -> int:
    from sys import stdin
    N = int(stdin.readline())
    yp = stdin.readline()
    tp = stdin.readline()

    res = 0
    for i in range(N):
        if yp[i] == 'C' and tp[i] == 'C':
            res += 1
    return res

print(main())
