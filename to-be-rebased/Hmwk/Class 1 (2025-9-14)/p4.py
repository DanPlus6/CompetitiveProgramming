# CCC '24 S1 - Hat Circle
N = int(input())
hats = [int(input()) for i in range(N)]

seen = 0
for i in range(N//2):
    # comment these out cuz they waste time on large batches, and on small batches #
    # these are intended to catch, it doesn't exceed time to just not use them     #
    # if len(set(hats)) == 1:
    #     seen = N
    #     break
    # if N == 2 and hats[0] != hats[1]:
    #     break
    #------------------------------------------------------------------------------#

    if hats[i] == hats[i+N//2]:
        seen += 2
        

print(seen)
