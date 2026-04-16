#!/bin/python3
import math
import os
import random
import re
import sys

# Complete the 'findCreature' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING input1
#  2. STRING input2
#  3. STRING input3


def findCreature(input1: str, input2: str, input3: str) -> str:
    def isValid(x: tuple[int,int]): return 0 <= x[0] <= 256 and 0 <= x[1] <= 256
    xg1, yg1, d1, dd1 = int(input1[0:2],16), int(input1[2:4],16), int(input1[5:7],16), int(input1[7:9],16)
    xg2, yg2, d2, dd2 = int(input2[0:2],16), int(input2[2:4],16), int(input2[5:7],16), int(input2[7:9],16)
    xg3, yg3, d3, dd3 = int(input3[0:2],16), int(input3[2:4],16), int(input3[5:7],16), int(input3[7:9],16)

    def findAllPos(r: int, c: int, V: int, H: int) -> set:
        pos = set()
        if isValid((r + V, c + H)): pos.add((r + V, c + H))
        if isValid((r + V, c - H)): pos.add((r + V, c - H))
        if isValid((r - V, c + H)): pos.add((r - V, c + H))
        if isValid((r - V, c - H)): pos.add((r - V, c - H))
        if isValid((r + H, c + V)): pos.add((r + H, c + V))
        if isValid((r + H, c - V)): pos.add((r + H, c - V))
        if isValid((r - H, c + V)): pos.add((r - H, c + V))
        if isValid((r - H, c - V)): pos.add((r - H, c - V))
        return pos
    
    s1 = findAllPos(xg1,yg1,d1,dd1)
    s2 = findAllPos(xg2,yg2,d2,dd2)
    s3 = findAllPos(xg3,yg3,d3,dd3)

    for i in s1: 
        if i in s2 and i in s3:
            return f"({i[0]:02X},{i[1]:02X})"

print(findCreature(input(),input(),input()))

# def to(x): return int(x,16)
# xg1, yg1, d1, dd1 = map(to,input().split())
# print(xg1, yg1, d1, dd1)
