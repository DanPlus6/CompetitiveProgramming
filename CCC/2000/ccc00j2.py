# CCC '00 J2 - 9966
a = int(input())
b = int(input())

rotate = {
    '0': '0',
    '1': '1',
    '6': '9',
    '8': '8',
    '9': '6'
}

count = 0

for n in range(a, b + 1):
    s = str(n)
    rotated = ""
    valid = True

    for digit in reversed(s):
        if digit not in rotate:
            valid = False
            break
        rotated += rotate[digit]

    if valid and rotated == s:
        count += 1

print(count)
