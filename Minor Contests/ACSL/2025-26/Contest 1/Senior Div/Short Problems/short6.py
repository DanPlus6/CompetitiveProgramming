n = 0
for x in range(1,5):
    z = 10-x
    a = str(1089*x)
    s = ""
    for y in range(len(a)):
        s = a[y] + s
    if s == str(1089*z):
        n += 1
print(n)
