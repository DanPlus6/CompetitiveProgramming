# Cat Lovers
from sys import stdin
ipt = [stdin.readline().strip('\n') for i in range(int(stdin.readline()))]
cats,dogs = 0,0
for i in ipt:
    if i == 'cats':
        cats += 1
    else:
        dogs += 1

if cats > dogs:
    print('cats')
elif dogs > cats:
    print('dogs')
else:
    print('equal')

