# # CCC '17 J4 - Favourite Times
def main() -> int:
    from sys import stdin
    D = int(stdin.readline())

    ash = [34, 71, 83, 95, 107, 119, 130, 142, 154, 166, 178, 201, 213, 225, 237, 260, 272, 284, 296, 331, 343, 355, 390, 402, 414, 461, 473, 520, 532, 591, 671]

    res = (D // 720) * 31
    overUnderShoot = D % 720
    if not overUnderShoot:
        return res
    
    for i in range(31):
        if ash[i] > overUnderShoot:
            res += i
            break

    return res

    """
    if D == 720:
        return 31
    if D % 720 == 0:
        return (D//720) * 31

    res = 0
    d = D
    while d > 720:
        d -= 720
        res += 31
    
    if d < 34:
        return res
    if d >= 671:
        return res + 31
    
    for i in range(31):
        if ash[i] > d:
            res += i
            break

    return res
    """

print(main())
