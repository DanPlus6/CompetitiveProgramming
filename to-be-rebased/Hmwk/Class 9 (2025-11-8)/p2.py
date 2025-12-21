# Mock CCC '23 Contest 1 J2 - Healthy Schedule
from sys import stdin
def main() -> bool:
    S = int(stdin.readline()); W = int(stdin.readline())
    if not (S >= 20 and S <= 23) or not (W >= 6 and W <= 9):
        return False
    s = 24-S + W
    if not (s >= 8 and s <= 10):
        return False
    return True
print('Healthy') if main() else print('Unhealthy')
