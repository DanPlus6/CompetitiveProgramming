# CCC '07 J3 - Deal or No Deal Calculator
casesDef = {1:100 , 2:500 , 3:1000 , 4:5000 , 5:10000 , 6:25000 , 7:50000 , 8:100000 , 9:500000 , 10:1000000}

res = 1691600
for i in range(N := int(input())):
    res -= casesDef[int(input())]

print("deal") if int(input()) > res/(10-N) else print("no deal")


