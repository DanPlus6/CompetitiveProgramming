# CCC '07 J4 - Anagram Checker
from collections import Counter
from sys import stdin
input = stdin.readline

print("Is an anagram.") if sorted(Counter(input().strip())) == sorted(Counter(input().strip())) else print("Is not an anagram.")
