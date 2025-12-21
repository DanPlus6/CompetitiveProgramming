# Postfix Notation
from sys import stdin
profix = list(stdin.readline().split())

stack = []
for i in profix:
    if i[0].isdigit() or (len(i) > 1 and i[0] == '-'):
        stack.append(int(i))
    else:
        v1 = stack.pop(); v2 = stack.pop()
        
        if i == '+':
            stack.append(v2+v1)
        elif i == '-':
            stack.append(v2-v1)
        elif i == '*':
            stack.append(v2*v1)
        elif i == '/':
            stack.append(v2/v1)
        elif i == '^':
            stack.append(v2**v1)
        elif i == '%':
            stack.append(v2%v1)

print(stack[0])
