from sympy import isprime
def f(x):
    if x > 5 and isprime(x): return f(x+3)-1
    elif x == 1 or x%3==0 or x%5==0: return f(x-1)+2
    else: return x-2

print(f(f(f(7))))
