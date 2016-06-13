
import random
file = open("A.in","w")
file.write("5000\n")
for i in range(1,5001):
    ok = 0
    while ok == 0:
        sum = 0
        length = random.randrange(1,51)
        if length % 2 == 1:
            continue
        j = 0
        string = ""
        while j < length :
            k = random.randrange(0,2)
            if k == 0:
                sum += 1
                string += "("
            elif sum == 0:
                sum += 1
                string += "("
            else:
                sum -= 1
                string += ")"
            j += 1
        if sum == 0 :
            ok = 1
            #print string
            ansStr = ""
            for c in string:
                rd = random.randrange(0,5)
                if rd == 3:
                    if c == ")":
                        ansStr += "("
                    else:
                        ansStr += ")"
                elif rd == 4:
                    ansStr += "?"
                else :
                    ansStr += c
            file.write(ansStr + "\n")
            if len(string) > 50:
                exit(1)



