# CCC '05 J1 - The Cell Sell
DAY = int(input())
EVE = int(input())
WEE = int(input())

A = (0 if DAY <= 100 else (DAY-100)*25) + (EVE*15) + (WEE*20)
B = (0 if DAY <= 250 else (DAY-250)*45) + (EVE*35) + (WEE*25)

print(f"Plan A costs {A/100:.2f}")
print(f"Plan B costs {B/100:.2f}")
if A < B: print("Plan A is cheapest.")
elif B < A: print("Plan B is cheapest.")
else: print("Plan A and B are the same price.")
