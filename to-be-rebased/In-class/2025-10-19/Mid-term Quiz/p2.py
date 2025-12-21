# Candy Division
def main() -> int:
    from sys import stdin
    N = int(stdin.readline())
    candies = sorted(list(map(int, stdin.readline().split())))

    if len(set(candies)) == 1:
        return 0
    
    return candies[N//2] - candies[N//2-1]  # very smart, no need to physically search
                                            # correct version of my original idea:
                                            # I though the answer was 2, thinking that X could only be right median and right median - 1
                                            # but I didn't think far enough--what if right median - left median > 2?
                                            # thus, the answer is right median - left median, as the only possible X values are
                                            #  the integers > left median, <= right median
print(main())