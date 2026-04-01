# CCC '15 J3 - Rövarspråket
from sys import stdin
def main() -> str:
    raw = stdin.readline()
    res = ''
    for i in raw:
        if i in 'aeiou':
            # if vowel
            res += i
            continue

        # if consonant
        # self
        res += i

        # nearest vowel
        ore = ord(i)
        if ore > 97 and ore <= 99:
            res += 'a'
        elif ore > 99 and ore <= 103:
            res += 'e'
        elif ore > 103 and ore <= 108:
            res += 'i'
        elif ore > 108 and ore <= 114:
            res += 'o'
        elif ore > 114:
            res += 'u'

        # next consonant
        if i == 'z':
            res += 'z'
        else:
            if ore not in [100,104,110,116]:
                res += chr(ore+1)
                continue
            res += chr(ore+2)

    return res.strip()
print(main())
