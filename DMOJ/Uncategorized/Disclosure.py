# Disclosure

# def outer():
#     secret = None
#     def inner():
#         secret = secret
#     return inner

# x = outer()
# del outer

index = x.__code__.co_freevars.index('secret')
print(x.__closure__[index].cell_contents)
