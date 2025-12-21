# CCC '21 J3 - Secret Instructions
ipt = []
while True:
    code = input()
    if code == '99999':
        break
    ipt.append(code)

dir = None
for i in ipt:
    headsum = (int(i[0]) + int(i[1]))
    if headsum & 1 == 0 and headsum != 0:
        dir = 'right'
        print(dir,i[-3:])
    elif headsum == 0:
        print(dir,i[-3:])
    else:
        dir = 'left'
        print(dir,i[-3:])
