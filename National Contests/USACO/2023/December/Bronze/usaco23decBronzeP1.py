# USACO 2023 December Bronze P1 - Candy Cane Feast
from sys import stdin
N,M = map(int, stdin.readline().split())
CO = list(map(int, stdin.readline().split()))
CA = list(map(int, stdin.readline().split()))

# Orz bruce 🙏
for i in range(M): # loop candy
    base,candy = 0,CA[i]
    for j in range(N): # loop cows
        cow = CO[j]
        if base < cow:
            eat = min(candy,cow) - base # min to prevent overeating
            base = min(candy,cow)
            CO[j] += eat

            if base >= candy: # candy eaten
                break

for i in CO:
    print(i)
