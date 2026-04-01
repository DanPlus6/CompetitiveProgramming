# The Return of A Plus B
from sys import stdin

dec = {"1":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "10":10}
eng = {"one":1, "two":2, "three":3, "four":4, "five":5, "six":6, "seven":7, "eight":8, "nine":9, "ten":10}
fr = {"un":1, "deux":2, "trois":3, "quatre":4, "cinq":5, "six":6, "sept":7, "huit":8, "neuf":9, "dix":10}
ch = {"一":1, "二":2, "三":3, "四":4, "五":5, "六":6, "七":7, "八":8, "九":9, "十":10}

for i in range(int(stdin.readline())):
    a,b = stdin.readline().split()
    if a in dec.keys(): a = dec[a]
    if a in eng.keys(): a = eng[a]
    if a in fr.keys(): a = fr[a]
    if a in ch.keys(): a = ch[a]

    if b in dec.keys(): b = dec[b]
    if b in eng.keys(): b = eng[b]
    if b in fr.keys(): b = fr[b]
    if b in ch.keys(): b = ch[b]

    print(a+b)