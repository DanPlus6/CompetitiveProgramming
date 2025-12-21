# CCC '18 J3 - Are we there yet?
from sys import stdin

# a 3 year old can do this
def main():
    cities = list(map(int,stdin.readline().split()))

    city = [0, cities[0], sum(cities[:2]), sum(cities[:3]), sum(cities)]
    for i in range(5):
        if i == 0:
            print(' '.join(list(map(str,city))))
        else:
            for j in range(5):
                print(abs(city[j]-city[i]),end=" ")
            print()

main()
