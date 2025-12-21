# CCC '16 S1 - Ragaman
from sys import stdin
from collections import Counter
def main() -> bool:
    a = Counter(stdin.readline().strip())
    b = Counter(stdin.readline().strip())
    if a == b: return True
    if '*' not in b.keys() and a != b: return False

    res = 0
    for k,v in a.items():
        if k not in b.keys():
            res += v
            continue
        if b[k] != v:
            res += abs(b[k] - v)
            continue
    return True if b['*'] == res else False

print('A') if main() else print('N')
