# USACO 2021 February Bronze P1 - Year of the Cow

# orz bruce :sob:
from sys import stdin

zodiacs = {'Ox': 1, 'Tiger': 2, 'Rabbit': 3, 'Dragon': 4, 'Snake': 5, 'Horse': 6, 'Goat': 7, 'Monkey': 8, 'Rooster': 9, 'Dog': 10, 'Pig': 11, 'Rat': 12}

links = {'Bessie':[0,0]}
for i in range(int(stdin.readline())):
    line = list(stdin.readline().strip('\n').split())
    name,prevOrNext,zodiac,compareName = line[0],line[3],zodiacs[line[4]],line[7]

    if i == 0:
        links[compareName] = [1,0]
    if prevOrNext == 'previous':
        dif = links[compareName][0] - zodiac
        if dif <= 0:
            dif += 12
        links[name] = [zodiac,links[compareName][1] + dif]
    else:
        dif = zodiac - links[compareName][0]
        if dif <= 0:
            dif += 12
        links[name] = [zodiac,links[compareName][1] - dif]

print(abs(links['Elsie'][1]))

