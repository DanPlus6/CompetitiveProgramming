# CCC '04 J4 - Simple Encryption
alpha = {'A':0,'B':1,'C':2,'D':3,'E':4,'F':5,'G':6,'H':7,'I':8,'J':9,'K':10,'L':11,'M':12,'N':13,'O':14,'P':15,'Q':16,'R':17,'S':18,'T':19,'U':20,'V':21,'W':22,'X':23,'Y':24,'Z':25}

keyword = input()
raw = input()
i = 0
for j in range(len(raw)):
    c = raw[j]
    if c.isalpha():
        res = (ord(c) + alpha[keyword[i%len(keyword)]]) % 91
        print(chr(res),end="") if res >= 65 else print(chr(res+65),end="")
        i += 1

