# ECOO '19 R2 P1 - Email

# 🙏 pls work (more efficient and clean solution (cheated, looked at teacher's solution))
def rootEmail(email: str) -> str:
    email = email.lower()
    name,domain = email.split('@')
    name = name.replace('.','')
    for i in range(len(name)):
        if name[i] == '+':
            name = name[:i]
            break
    return name + '@' + domain

dbs = [[] for i in range(10)]
for i in range(10):
    for j in range(int(input())):
        dbs[i].append(input())

for db in dbs:
    emails = set()
    for i in db:
        emails.add(rootEmail(i))
    print(len(emails))



# failed attempt (git gud)
"""
dbs = [[] for i in range(10)]
for i in range(10):
    length = int(input())
    dbs[i].append(length)
    for j in range(length):
        dbs[i].append(input())

def rip(string,blacklist,remnants=0):
    if remnants:
        ct = {}
        for i in string:
            if i not in ct:
                ct[i] = 1
            else:
                ct[i] += 1       
        res = list(string)
        for i in blacklist:
            rem = ct[i] - remnants
            if rem <= 0: rem = 0
            for j in range(rem):
                res.remove(i)
        return ''.join(res)
    else:
        res = ''
        for i in range(len(string)):
            if string[i] not in blacklist:
                res += string[i]
        return res


ret = []
for db in dbs:
    emails = set()
    for i in range(1,db[0]+1):
        adr,dm = db[i].split('@')
        adr,dm = adr.lower(),dm.lower()
        # try:
        #     dmH,dmT = dm.split('.')
        # except ValueError:

        # dmH,dmT = rip(dmH,'.'),rip(dmT,'.')
        dm = rip(dm,'.',1)
        adr = rip(adr,'.')
        for j in range(len(adr)):
            if adr[j] == '+':
                emails.add((adr[:j]+'@'+dm))
                break
        else:
            emails.add((adr+'@'+dm))
    ret.append(len(emails))

for i in ret:
    print(i)
   
"""


        
