# CCC '8 J2 - Do the Shuffle
press = []
while True:
    b,n = int(input()),int(input())
    press.append((b,n))
    if b == 4:
        break

playlist = list('ABCDE')
def but1(n):
    for i in range(n):
        playlist.append(playlist.pop(0))

def but2(n):
    for i in range(n):
        song = playlist.pop()
        playlist.insert(0,song)

def but3(n):
    for i in range(n):
        first,second = playlist[0],playlist[1]
        playlist[0],playlist[1] = second,first

for i in press:
    if i[0] == 1:
        but1(i[1])
    elif i[0] == 2:
        but2(i[1])
    elif i[0] == 3:
        but3(i[1])
    else:
        for j in range(i[1]):
            print(' '.join(playlist))

