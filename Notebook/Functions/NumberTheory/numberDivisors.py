import math
def numberDivisors(n):
    counter=0
    sq=math.sqrt(n)
    # print(sq)
    for i in range(1,int(sq)+1):
        if(n%i==0):
            counter+=2
    if(sq-math.floor(sq)==0):
        counter-=1
    return counter

print(numberDivisors(10))

