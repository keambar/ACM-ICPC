
import random

from random import Random
chars = 'qwertyuiopasdfghjklzxcvbnm'
def random_str(randomlength=8):
    str = ''
    length = len(chars) - 1
    random = Random()
    for i in range(randomlength):
        str+=chars[random.randint(0, length)]
    return str

def solve_random_str(string):
    length = len(string)
    ansStr = ""
    for c in range(0,length):
        if random.randrange(0,20) == 0:
            ansStr += chars[random.randint(0, len(chars) - 1)]
        else:
            ansStr += string[c]
    return ansStr

if __name__=="__main__":
    file = open("B.in","w")
    file.write("5000\n")
    for simpleNum in range(0,5001):
        ansStr = random_str(random.randrange(2,101))
        ansStrLen = len(ansStr)
        k = random.randrange(1,ansStrLen)
        Astr = solve_random_str(ansStr[0:k])
        Bstr = solve_random_str(ansStr[k:])

        rd = random.randrange(0,2)
        if random.randrange(0,2) == 1 :
            Astr = Astr[::-1]
        if random.randrange(0,2) == 1 :
            Bstr = Bstr[::-1]
        if random.randrange(0,2) == 1 :
            Astr,Bstr = Bstr,Astr
        if len(Astr) == 0 or len(Bstr) == 0:
            exit(1)
        file.write(Astr + " " + Bstr + "\n")
        file.write(ansStr + "\n")

