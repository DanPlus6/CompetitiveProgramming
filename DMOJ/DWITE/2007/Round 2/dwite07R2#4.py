# DWITE '07 R2 #4 - All Is Balanced
from sys import stdin
C = 5
ipt = [''.join([i for i in filter(lambda x: x in ['(',')','[',']','{','}'],stdin.readline().strip('\n'))]) for i in range(C)]

def bal(x: str) -> bool:
    filo = []
    for i in range(len(x)):
        cur = x[i]
        if cur in '([{':
            filo.append(cur)
        elif cur in ')]}':
            if not filo:
                return False
            else:
                if cur == ')' and filo[-1] != '(':
                    return False
                elif cur == ']' and filo[-1] != '[':
                    return False
                elif cur == '}' and filo[-1] != '{':
                    return False
                else:
                    filo.pop()
    return True if not filo else False

for i in ipt:
    if bal(i):
        print('balanced')
    else:
        print('not balanced')


# you dum dum it is not always mirrored
# for example: {[()()]}
"""
for i in ipt:
    if not i:
        print('balanced')
        continue
    left = [')',']','}']
    for j in range(len(i)//2):
        cur = i[j]
        if cur in left:
            print('not balanced')
            break
        elif cur == '(' and i[0-j-1] != ')':
            print('not balanced')
            break
        elif cur == '[' and i[0-j-1] != ']':
            print('not balanced')
            break
        elif cur == '{' and i[0-j-1] != '}':
            print('not balanced')
            break
    else:
        print('balanced')
"""

