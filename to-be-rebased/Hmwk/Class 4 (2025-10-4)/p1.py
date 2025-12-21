# CCC '19 J1 - Winning Score
apples = int(input()) * 3
apples += (int(input()) * 2)
apples += int(input())
bananas = int(input()) * 3
bananas += (int(input()) * 2)
bananas += int(input())
 
if apples == bananas:
    print('T')
elif apples > bananas:
    print('A')
else:
    print('B')
