# Decoding

# bruh we coulda just done ts
def solve(n):print n
type(foo)(type(foo.__code__)(0, 3, 0, 0, foo.__code__.co_code, foo.__code__.co_consts[:-1] + (solve.__code__,), foo.__code__.co_names, (), "", "", 0, ""), globals())()


# my code... works...?
# idk_y = None
# def yoink(n):
#     global idk_y
#     idk_y = n
    
# consts = list(foo.__code__.co_consts)
# for i, const in enumerate(consts):
#     if hasattr(const, 'co_name') and const.co_name == 'magic':
#         consts[i] = yoink.__code__
#         break
        
# foo.__code__ = foo.__code__.replace(co_consts=tuple(consts))
# foo()
# print(idk_y)


# ts not tuff 🥀💔
# idk_y = None
# def yoink(n):
#     global idk_y
#     idk_y = n

# new = type(foo.__code__)(
#     foo.__code__.co_argcount,
#     foo.__code__.co_kwonlyargcount,
#     foo.__code__.co_nlocals,
#     foo.__code__.co_stacksize,
#     foo.__code__.co_flags,
#     foo.__code__.co_code,
#     foo.__code__.co_consts,
#     foo.__code__.co_names,
#     foo.__code__.co_varnames,
#     foo.__code__.co_filename,
#     foo.__code__.co_name,
#     foo.__code__.co_firstlineno,
#     foo.__code__.co_lnotab,
#     foo.__code__.co_freevars,
#     foo.__code__.co_cellvars
# )

# foo.__code__ = new
# foo.__globals__['magic'] = yoink
# foo()

# print(idk_y)


