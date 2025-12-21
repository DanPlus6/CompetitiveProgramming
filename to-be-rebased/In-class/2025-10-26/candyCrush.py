from sys import stdin
K = int(stdin.readline())
candies = stdin.readline().strip('\n')
stack = []
for i in candies:
    if not stack:
        stack.append([i,1])
    else:
        if stack[-1][0] != i:
            if stack[-1][1] >= K:
                stack.pop()
                
            if stack[-1][0] != i:
                stack.append([i,1])
            else:
                stack[-1][1] += 1
        else:
            stack[-1][1] += 1

print(stack)
