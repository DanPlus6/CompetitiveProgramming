# CCC '01 J1 - Dressing Up
H = int(input())
for i in range(H//2):
    numAsterisk = i*2+1
    print('*'*numAsterisk + ' '*((H - numAsterisk)*2) + '*'*numAsterisk)

print('*'*(H*2))

for i in range(H//2-1,-1,-1):
    numAsterisk = i*2+1
    print('*'*numAsterisk + ' '*((H - numAsterisk)*2) + '*'*numAsterisk)

