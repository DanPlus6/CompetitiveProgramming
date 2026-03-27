# An Animal Contest 3 P2 - Monkey Potato
K,D = map(int, input().split())
digits = list(map(int, input().split()))
digits.sort()

if digits[0] == 0: # if lowest digit is 0
    if D == 1: # 0 is only digit provided, we cant make a number that is just 0s
        print(-1)
    elif K <= 2: # we can only use second lowest digit if K<=2 as you cant have trailing 0s or just 0s
        for i in range(K):
            print(digits[1],end="")
        print() # print new line to prevent presentation error
    elif K > 2: # no trailing 0s, so have two of lowest digit surround 0s
        print(digits[1],end="")
        for i in range(K-2):
            print(0,end="")
        print(digits[1])
else:
    for i in range(K): # no 0s, just print K of lowest digit
        print(digits[0],end="")
    print() # print new line to avoid presentation error
