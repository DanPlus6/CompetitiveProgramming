# CCC '10 J2 - Up and Down
from sys import stdin, stdout
input = stdin.readline
print = stdout.write

# brother ts p2 be frying me fr
a1 = int(input())
a2 = int(input())
b1 = int(input())
b2 = int(input())
s = int(input())
aTotal = 0
bTotal = 0
aTally = 0
bTally = 0

while aTally < s:
    aTotal = aTotal + a1 - a2
    aTally = aTally + a1 + a2

while bTally < s:
    bTotal = bTotal + b1 - b2
    bTally = bTally + b1 + b2


if aTally == s:
    pass
elif aTally != s:
    x = aTally - s
    if x >= a2:
        aTotal = aTotal + a2 - x + a2
    else:
        aTotal += x

if bTally == s:
    pass
elif bTally != s:
    x = bTally - s
    if x >= b2:
        bTotal = bTotal + b2 - x + b2
    else:
        bTotal += x

if aTotal > bTotal:
    print('Nikky')
elif bTotal > aTotal:
    print('Byron')
else:
    print('Tied')


# def simulate(forward, backward, steps):
#     pos = 0
#     while steps > 0:
#         if steps >= forward:
#             pos += forward
#             steps -= forward
#         else:
#             pos += steps
#             steps = 0
#         if steps >= backward:
#             pos -= backward
#             steps -= backward
#         else:
#             pos -= steps
#             steps = 0
#     return abs(pos)

# nickyf = int(input()); nickyb = int(input())
# byronf = int(input()); byronb = int(input())
# lim = int(input())

# nicky = simulate(nickyf, nickyb, lim)
# byron = simulate(byronf, byronb, lim)

# if nicky > byron: print("Nicky")
# elif byron > nicky: print("Byron")
# else: print("Tied")


# def main() -> None:
#     nickyf = int(input()); nickyb = int(input()); byronf = int(input()); byronb = int(input()); lim = int(input())
#     nickysteps,byronsteps = lim,lim
#     nickyl,byronl = 0,0

#     while nickysteps != 0 or byronsteps != 0:
#         if nickysteps >= nickyf: # forward
#             nickyl += nickyf
#             nickysteps -= nickyf
#         else: # remainder
#             nickyl += nickysteps
#             nickysteps = 0
#         if nickysteps >= nickyb: # back
#             nickyl -= nickyb
#             nickysteps -= nickyb
#         else:
#             nickyl -= nickysteps
#             nickysteps = 0
        
#         if byronsteps >= byronf:
#             byronl += byronf
#             byronsteps -= byronf
#         else:
#             byronl += byronsteps
#             byronsteps = 0
#         if byronsteps >= byronb:
#             byronl -= byronb
#             byronsteps -= byronb
#         else:
#             byronl -= byronsteps
#             byronsteps = 0

#     nickyl = abs(nickyl)
#     byronl = abs(byronl)
#     if nickyl > byronl: return "Nicky"
#     elif byronl > nickyl: return "Byron"
#     else: return "Tied"

# print(main())
