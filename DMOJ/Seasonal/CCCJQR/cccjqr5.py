# CCCJQR P5
base = ord('a')
N = ord(input().strip()) - base + 1
reslen = 2**N - 1

res = []
for i in range(1,reslen+1): res.append( chr(base + (i & -i).bit_length() - 1) )
print(''.join(res))



# 67 million instructions 💔
# c = input()

# def s(c: str):
#     if c == 'a':
#         return "a"
    
#     return s(chr(ord(c)-1)) + c + s(chr(ord(c)-1))

# print(s(c))
