# CCC '15 J1 - Special Day
from sys import stdin
def main() -> str:
    m,d = int(stdin.readline()),int(stdin.readline())
    if m > 2:
        return 'After'
    elif m < 2:
        return 'Before'
    else:
        if d > 18:
            return 'After'
        elif d < 18:
            return 'Before'
        else:
            return 'Special'

print(main())


