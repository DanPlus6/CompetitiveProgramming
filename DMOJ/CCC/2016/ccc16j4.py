# CCC '16 J4 - Arrival Time
from sys import stdin

# naieve method; way too lazy to figure out the math for the instant/efficient method
def main() -> str:
    h,m = map(int, stdin.readline().split(':'))
    iM = h*60 + m
    
    for i in range(120):
        if iM >= 420 and iM < 600 or iM >= 900 and iM < 1140:
            iM += 2; continue
        iM += 1
        if iM >= 1440: iM -= 1440

    h = iM // 60; m = iM % 60
    if h < 10: h = '0'+str(iM//60)
    if m < 10: m = '0'+str(m)
    return str(h)+':'+str(m)
    
print(main())
