# Mock CCC '18 Contest 3 J2 - A Palindrome Problem
from sys import stdin
def main():
    S = stdin.readline().strip()
    N = len(S)
    if N == 1: return False
    if N == 2: return True

    def ifPalindrome(string: str) -> bool:
        if not string: return False
        n = len(string)
        if n == 1: return True
        for i in range(n//2):
            if string[i] != string[-1-i]: return False
        return True

    for i in range(N):
        if ifPalindrome(S[:i+1]) and ifPalindrome(S[i+1:]): return True
    return False

print('YES') if main() else print('NO')
