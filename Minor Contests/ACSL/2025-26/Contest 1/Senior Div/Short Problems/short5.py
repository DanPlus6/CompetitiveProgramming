arr = [1000,500,100,50,10,5,1]
letters = "MDCLXVI"
num = 1776
ans = ""
for x in range(0,7):
    val = int(num/arr[x])
    for y in range(1,val+1):
        ans += letters[x]
    num %= arr[x]
print(ans)
