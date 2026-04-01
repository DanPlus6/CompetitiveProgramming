# CCC '25 J3 - Product Codes
N = int(input())
productCodes = [input() for _ in range(N)]


for i in range(len(productCodes)):
    code = productCodes[i]

    nsum = 0
    sstring = ''
    hold = ''

    for j in range(len(code)):
        char = code[j]

        if char.isalpha():
            if hold:
                nsum += int(hold)
                hold = ''
            if char.isupper():
                sstring += char
            continue

        if (char.isdigit()) or (char == "-"):
            if hold and char == '-':
                nsum += int(hold)
                hold = '-'
                continue
            hold += char
            if hold and j == (len(code)-1):
                nsum += int(hold)

    productCodes[i] = (sstring+str(nsum))


for i in productCodes:
    print(i)

