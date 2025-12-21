H,W = map(int, input().split())

raw = [input() for i in range(H)]
print("#"*(W+2))
for i in range(H):
    print("#",end="")
    print(raw[i],end="")
    print("#")

print("#"*(W+2))
