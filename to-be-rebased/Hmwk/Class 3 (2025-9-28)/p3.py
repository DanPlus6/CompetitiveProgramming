# CCC '20 J4 - Cyclic Shifts

# attempt 2
T = input()
S = input()

pos = []
for i in range(len(S)):
    S = S[1:] + S[0]
    pos.append(S)

for i in pos:
    if i in T:
        print('yes')
        break
else:
    print('no')


# attempt 1, pretty intuitive
"""
T = input()
S = input()
chunkLen = len(S)
tLen = len(T)


def cycShift(val,key):
    v,k = val,key
    if v == k:
        return True
    for i in range(len(v)):
        v = v[1:] + v[0]
        if v == k:
            return True
    return False

def main():
    l,r = 0,chunkLen
    while r < tLen:
        if cycShift(T[l:r],S):
            return 'yes'
        l+=1
        r+=1
    return 'no'

print(main())
"""


