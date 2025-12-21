# CCC '24 J4 - Troublesome Keys
# with teacher help
press = input()
display = input()

n,m = len(press),len(display)

quiet = False
if n != m:
    quiet = True

ifContinue = True
if not quiet:
    for i in range(n):
        if press[i] != display[i]:
            print(press[i],display[i])
            print('-')
            ifContinue = False
            break

if ifContinue:
    prs = []
    dsp = []
    for i in range(n):
        nur = press[i]
        if nur not in prs: prs.append(nur)
        try:
            dur = display[i]
            if dur not in dsp: dsp.append(dur)
        except IndexError:
            continue


    
    p_dif_d = [i for i in prs if i not in dsp]
    d_dif_p = [i for i in dsp if i not in prs]
    wrong,replacement = p_dif_d[0],d_dif_p[0]
    silent = p_dif_d[1]
    if (press.replace(wrong,replacement).replace(silent,"")) != display:
        wrong = p_dif_d[1]
        silent = p_dif_d[0]
    print(wrong,replacement)
    print(silent)


