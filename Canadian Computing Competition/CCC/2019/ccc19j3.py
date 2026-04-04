# CCC '19 J3 - Cold Compress
ipt = [input() for i in range(int(input()))]

for i in ipt:
    # input = "+++===!!!!!"
    # output = "3 + 3 = 5 !"
    res = ''
    hold,ct = '',0
    for k,j in enumerate(i):
        if not hold:
            hold = j
            ct = 1
        elif hold and j != hold:
            res += f'{ct} {hold} '
            hold = j
            ct = 1
        elif j == hold:
            ct += 1
        if k == len(i)-1:
            res += f'{ct} {hold}'
    print(res.strip())

