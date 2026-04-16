# TLE '16 Contest 8 P2 - Dank Meme
for i in range(int(input())):
    res = []
    for d in bin(int(input()))[2:]:
        if d == '0': res.append("meme") 
        else: res.append("dank")
    print(" ".join(res))

