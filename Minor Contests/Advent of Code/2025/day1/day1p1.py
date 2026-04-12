with open('day1/p1.txt','r') as f:
    at = 50
    res = 0
    for i in f:
        ln = i.strip()
        op,turn = ln[0],int(ln[1:])

        if op == 'L':
            for i in range(turn):
                at -= 1
                if at == -1: at = 99
        else:
            for i in range(turn):
                at += 1
                if at == 100: at = 0
        if at == 0: res += 1
            

print(res)

