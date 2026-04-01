N = int(input())
for i in range(N):
    idx, text = input().split(maxsplit=1)
    idx = int(idx)

    mis = text[:idx-1] + text[idx:]
    print(i+1, mis)
