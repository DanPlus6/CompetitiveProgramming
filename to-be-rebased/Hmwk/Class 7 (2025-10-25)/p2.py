# CCC '15 J2 - Happy or Sad
from sys import stdin
def main() -> str:
    ln = stdin.readline()
    h,s = 0,0
    for i in range(len(ln)-2):
        cur = ln[i:i+3]
        if cur == ':-)':
            h += 1
        elif cur == ':-(':
            s += 1

    if not h and not s:
        return 'none'
    elif h == s:
        return 'unsure'
    elif h > s:
        return 'happy'
    elif s > h:
        return 'sad'

print(main())
