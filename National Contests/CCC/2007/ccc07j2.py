# CCC '07 J2 - I Speak TXTMSG
from sys import stdin
input = stdin.readline

Dictionary = {
    "CU" 	:"see you",
    ":-)" 	:"I'm happy",
    ":-(" 	:"I'm unhappy",
    ";-)" 	:"wink",
    ":-P" 	:"stick out my tongue",
    "(~.~)" :"sleepy",
    "TA" 	:"totally awesome",
    "CCC" 	:"Canadian Computing Competition",
    "CUZ" 	:"because",
    "TY" 	:"thank-you",
    "YW" 	:"you're welcome",
    "TTYL" 	:"talk to you later"
}

while True:
    ln = input().strip()
    if ln in Dictionary.keys():
        print(Dictionary[ln])
        if ln == "TTYL": break
    else:
        print(ln)
