# CCC '18 J1 - Telemarketer or not?
def main() -> str:
    from sys import stdin
    firstDig = int(stdin.readline())
    secondDig = int(stdin.readline())
    thirdDig = int(stdin.readline())
    fourthDig = int(stdin.readline())

    return 'ignore' if firstDig in (8,9) and fourthDig in (9,8) and secondDig == thirdDig else 'answer'

print(main())
