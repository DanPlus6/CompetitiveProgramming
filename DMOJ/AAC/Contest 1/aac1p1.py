S,R = map(int, input().split())

areaOfSquare = S**2 # S*S
areaOfCircle = 3.14 * R**2

if areaOfSquare > areaOfCircle:
    print("SQUARE")
else:
    print("CIRCLE")

