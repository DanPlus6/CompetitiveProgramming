# CCC '21 J4 - Arranging Books

# 15/15
B = input()
n = len(B)

ct = {'L':0,'M':0,'S':0}
for i in B:
    ct[i] += 1

swaps = 0
ems = 0
for i in B[:ct['L']]:
    if i != 'L':
        swaps += 1
        if i == 'M':
            ems += 1

els = 0
for i in B[ct['L']:ct['L']+ct['M']]:
    if i != 'M':
        swaps += 1
        if i == 'L':
            els += 1

swaps -= min(els,ems)
print(swaps)


# 11/15
"""
B = input()
n = len(B)

ct = {'L':0,'M':0,'S':0}
for i in B:
    ct[i] += 1

swaps = 0
for i in B[0:ct['L']]:
    if i == 'S':
        swaps += 1

for i in B[ct['L']:ct['L']+ct['M']]:
    if i != 'M':
        swaps += 1

print(swaps)
"""


