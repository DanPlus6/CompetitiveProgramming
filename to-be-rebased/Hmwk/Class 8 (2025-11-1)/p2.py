# CCC '16 J2 - Magic Squares
from sys import stdin
def main() -> bool:
    C = 4
    square = [list(map(int, stdin.readline().split()))]
    val = sum(square[0])
    for i in range(C-1):
        row = list(map(int, stdin.readline().split()))
        if sum(row) != val:
            return False
        square.append(row)
    
    for c in range(C):
        if sum([i[c] for i in square]) != val:
            return False
    return True
    

print('magic') if main() else print('not magic')
