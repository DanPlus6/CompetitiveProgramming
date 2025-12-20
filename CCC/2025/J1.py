N = int(input("Place in line: "))
C = int(input("Number of train cars: "))
P = int(input("Number of people a single car holds: "))

if C*P >= N:
    print('yes')
else:
    print('no')