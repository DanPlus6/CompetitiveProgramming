# UTS Open '18 P3 - Restaurants
from sys import stdin
def main():
    N,T,K,V = map(int,stdin.readline().split())
    arr = [0 for i in range(N)]
    for i in range(V):
        arr[int(stdin.readline())-1] = 1
    
    res = 0
    s,stk = 0,[]
    for i in range(N):
        s += arr[i]
        if arr[i] == 0:
            stk.append(i)

        if i >= T: s -= arr[i-T]    # "slides" the window forward if past window footer, by removing (subtracting) the item @ window header
        if i >= T-1:                # add restaurants if footer of window reached
            while s < K:
                arr[stk.pop()] = 1
                s += 1
                res += 1
                
        # old poo poo code
        # ( copied old code, had 0 clue what I was doing )
        # if i >= T-1:
        #     s -= arr[i-T]
        #     while s < K:
        #         arr[stk.pop()] = 1
        #         s += 1
        #         res += 1


    print(res)

main()

