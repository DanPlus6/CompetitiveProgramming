# DMOPC '17 Contest 2 P2 - Balance
from sys import stdin,stdout
X = stdin.readline().strip()
def bal(x,invertUsed = False) -> int:
    if len(x) % 2: return False
    stk = []
    for i in x:
        if i == '(':
            stk.append(i)
        elif i == ')':
            if not stk:
                if not invertUsed:
                    if invertUsed: return False
                    invertUsed = True
                    stk.append('(')
                else:
                    return False
            else:
                if stk[-1] != '(':
                    if invertUsed: return False
                    invertUsed = True
                stk.pop()
    
    if (invertUsed and stk) or (not invertUsed and len(stk)>2): return False
    return True

stdout.write('YES') if bal(X) else stdout.write('NO')
