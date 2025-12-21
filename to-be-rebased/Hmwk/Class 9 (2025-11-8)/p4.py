# USACO 2023 January Bronze P1 - Leaders
from sys import stdin
N = int(stdin.readline())
breeds = stdin.readline()
E = list(map(int,stdin.readline().split()))

# Orz bruce
# I was lwk two centimeters away from the answer
# but Dr.Bruce is goated
gres,hres = 0,0
if breeds[0] == 'G':
    gfoot = breeds.rfind('G')
    hhead = breeds.find('H')
    hfoot = breeds.rfind('H')

    if E[0] >= gfoot + 1: gres += 1
    if E[hhead] >= hfoot + 1: hres += 1

    for i in range(hhead):
        if breeds[i] == 'G' and E[i] >= hhead + 1: gres += 1
else:
    hfoot = breeds.rfind('H')
    ghead = breeds.find('G')
    gfoot = breeds.rfind('G')

    if E[0] >= hfoot + 1: hres += 1
    if E[ghead] >= gfoot + 1: gres += 1

    for i in range(ghead):
        if breeds[i] == 'H' and E[i] >= ghead + 1: hres += 1


print(gres*hres)
