# CCC '08 J4 - From Prefix to Postfix
from sys import stdin, stdout
input = stdin.readline

while True:
    ln = list(input().split())
    if len(ln) == 1:
        if ln[0] != "0":
            print(ln[0])
        else: break
    
    stk = []
    for elem in reversed(ln):
        if elem.isdigit():
            stk.append(elem)
        else:
            fstOp = stk.pop()
            secOp = stk.pop()
            stk.append(fstOp + " " + secOp + " " + elem)
    
    stdout.write("".join(stk)+'\n')
    
