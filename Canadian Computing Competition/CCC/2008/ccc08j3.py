# CCC '08 J3 - GPS Text Entry
from sys import stdin
input = stdin.readline

X = {
    "A": 0, "B": 1, "C": 2, "D": 3, "E": 4, "F": 5,
    "G": 0, "H": 1, "I": 2, "J": 3, "K": 4, "L": 5,
    "M": 0, "N": 1, "O": 2, "P": 3, "Q": 4, "R": 5,
    "S": 0, "T": 1, "U": 2, "V": 3, "W": 4, "X": 5,
    "Y": 0, "Z": 1, " ": 2, "-": 3, ".": 4, "\n": 5
}
Y = {
    "A": 0, "B": 0, "C": 0, "D": 0, "E": 0, "F": 0,
    "G": 1, "H": 1, "I": 1, "J": 1, "K": 1, "L": 1,
    "M": 2, "N": 2, "O": 2, "P": 2, "Q": 2, "R": 2, 
    "S": 3, "T": 3, "U": 3, "V": 3, "W": 3, "X": 3,
    "Y": 4, "Z": 4, " ": 4, "-": 4, ".": 4, "\n": 4
}


pos = [0,0]
res = 0
ipt = input()
for i in ipt:
    res += abs(pos[0] - X[i]); pos[0] = X[i]
    res += abs(pos[1] - Y[i]); pos[1] = Y[i]


print(res)
