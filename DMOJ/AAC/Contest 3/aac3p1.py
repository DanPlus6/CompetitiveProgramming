# An Animal Contest 3 P1 - Monkey Shopping
A,B,C,D = map(int, input().split())

if A >= B and C >= D:
    print("Stay home")
elif A < B and C < D:
    print("Go to the department store")
elif A < B and C >= D: 
    print("Go to the grocery store")
elif C < D and A >= B: 
    print("Go to the pharmacy")
