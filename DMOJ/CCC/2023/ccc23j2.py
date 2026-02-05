# CCC '23 J2 - Chili Peppers
from sys import stdin
input = stdin.readline

spice = {"Poblano":1500,"Mirasol":6000,"Serrano":15500,"Cayenne":40000,"Thai":75000,"Habanero":125000}

res = 0
for i in range(int(input())):
    res += spice[input().strip()]

print(res)


