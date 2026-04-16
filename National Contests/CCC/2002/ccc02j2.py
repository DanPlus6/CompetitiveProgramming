# CCC '02 J2 - AmeriCanadian
from sys import stdin
input = stdin.readline

while True:
    word = input().strip()
    if word == 'quit!': break
    if n := len(word) > 4:
        if word[-3] not in ['a', 'e', 'i', 'o', 'u', 'y'] and word[-2:] == 'or': print(word[:-2]+'our')
        else: print(word)
    else: print(word)
    

