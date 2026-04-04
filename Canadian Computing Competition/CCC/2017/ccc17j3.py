# CCC '17 J3 - Exactly Electrical
# YOOOOO
# REFFFFF
# HOW WAS IT THIS EASYYY
# THIS GOTTA BE A SCAMMMMMM
def main() -> bool:
    from sys import stdin
    a,b = map(int, stdin.readline().strip('\n').split())
    c,d = map(int, stdin.readline().strip('\n').split())
    t = int(stdin.readline()); minDist = abs(a-c) + abs(b-d)

    if t < minDist:
        return False
    if minDist == t:
        return True
    if (t - minDist) % 2 == 0:
        return True
    
print('Y') if main() else print('N')
