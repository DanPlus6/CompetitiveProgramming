# CCC '24 J2 - Dusa and The Yobis
D = int(input())
d = D
while True:
    y = int(input())
    if d <= y:
        break
    d += y
print(d)
